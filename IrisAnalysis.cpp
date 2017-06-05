
#include "IrisAnalysis.h"

#include "Iris/ImageUtility.h"
#include "Iris/ImageQuality.h"
#include "Iris/FindPupilCircleNew.h"
#include "Iris/FindIrisCircle.h"
#include "Iris/FindEyelidCurve.h"
#include "Iris/FindHighLights.h"
#include "Iris/MatchAlg.h"
#include "Iris/Normalization.h"
#include "Iris/Encode.h"

#include <iostream>
#include <string>
#include <QFileDialog>

IrisAnalysis::IrisAnalysis()
{
}

IrisAnalysis::IrisAnalysis(std::string filename)
{
    irisFileName = filename;
}

IrisAnalysis::~IrisAnalysis()
{

}

void IrisAnalysis::setIrisFileName(std::string filename) {
    irisFileName = filename;
}

std::string IrisAnalysis::getIrisFileName() {
   return irisFileName;
}

// Dialog & Widget: Get the eye image
void IrisAnalysis::getEyeImage()
{
    if (irisFileName.empty()) {
        std::cout << "File is empty.";
    } else {
        irisImage = cv::imread(irisFileName, CV_LOAD_IMAGE_GRAYSCALE);  // always convert to gray
        std::cout << "File loaded for analysis in memory " << irisFileName << std::endl;
    }

}

double IrisAnalysis::getImageQuality(){
    return imageQualityScore;
}

//MENU: Image Quality Measurement using Sobel operator
void IrisAnalysis::checkQuality()
{
    if(irisImage.empty()){
        std::cout << "Iris image file is not loaded. No task to do!";
    } else {
        try
        {
            // method 1. not so efficient, but works
//            IplImage* img = NULL;
//            const char *fn = irisFileName.c_str();
//            img = cvLoadImage(fn, 0);
            //////////////////////////////////////////////////

            // method 2. no disk io. faster.
            IplImage *img=NULL;
            // convert from mat to ipl  https://gist.github.com/QuarkSpark/3404507
            IplImage ipl_img = irisImage;
            //CvMat cvmat = irisImage;
            img = &ipl_img;
            ///////////////////////////////////////////////////

            //ImageUtility::CVMatToIplImage(&irisImage, img);


            // If it is NULL, release the image, and stop processing
            if(img == NULL)
            {
                std::cout << "Failed to load the file: " << irisFileName << std::endl;
                return;
            }

            // debug: verify image loaded on memory.
            ImageUtility::showImage("Image loaded on memory", img);

            imageQualityScore = ImageQuality::doProcess(img, 0); //0:Sobel
            cout << "Quality score: " << imageQualityScore << endl;            

            //cvReleaseImage(&img);
        }
        catch(const char* msg)
        {
            cout << "ERROR: Failed to load the file" << msg << endl;
        }
    }
}

void IrisAnalysis::irisCheck()
{
    IplImage *imgOrigin;

    const char *fn = irisFileName.c_str();
    imgOrigin = cvLoadImage(fn, 1);

    ImageUtility *imgUtil = NULL;
    IplImage *eyeImg  = ImageUtility::convertToGray(imgOrigin);
    IplImage *grayImg = ImageUtility::convertToGray(imgOrigin);

    // still image : NIR_IRIS_STILL
    // set args for sill eye image
    float nScale        = 2.0;
    const int speed_m   = 1;// Default 1
    int alpha           = 25; // Alpha value for contrast threshold

    // Setup the parameters to avoid that noise caused by reflections and
    // eyelashes covers the pupil
    double ratio4Circle = .90;

    // Initialize for Closing and Opening process
    int closeItr    = 2;//dilate->erode
    int openItr     = 3;//erode->dilate
    double norm     = 256.0;

    //IRIS INPUTS
    double scaling      = 0.4;// Default
    double lowThres     = 0.11;// Default
    double highThres    = 0.19;// Default

    const int rPupilMax = (int) (42*nScale);// Maximum radius of pupil's circle
    const int rIrisMax  = (int) (82*nScale);// Maximum radius of iris' circle

    //fine the pupil circle using contours
    int pupilCircle[6] = {0};

    // loading it again so that the analyze btm twice, it grayImg doesn't have previous outputs.
//    grayImg = ImageUtility::convertToGray(imgOrigin);


    FindPupilCircleNew::doDetect(eyeImg, rPupilMax, ratio4Circle, closeItr, openItr, speed_m, alpha, norm, nScale, pupilCircle);
    cvCircle(grayImg, cvPoint(pupilCircle[0], pupilCircle[1]), pupilCircle[2], CV_RGB(255,255,255), 1, 8);
    ImageUtility::showImage("Pupil Circle on the result", grayImg);

    ///
    CvPoint xyPupil;
    xyPupil.x = pupilCircle[0];
    xyPupil.y = pupilCircle[1];
    int rPupil = pupilCircle[2];
    IplImage* setImg = NULL;

    //ROI for detecting the iris circle
    ImageUtility::SETVALUE setVal = imgUtil->setImage(eyeImg, xyPupil, rPupil, rIrisMax, rIrisMax);	//82 is the best for video images, previous 80
    setImg = imgUtil->getROIImage(eyeImg, setVal.rect.x, setVal.rect.width, setVal.rect.y, setVal.rect.height);

    ImageUtility::showImage("Iris ROI", setImg);

    int centerAdjust=(int)(rIrisMax/4); //(rIrisMax/5); //for video dataset

    //find the iris circle using Hough Transform
    int irisCircle[3]={0};

    FindIrisCircle::doDetect(setImg, rPupil, rIrisMax, scaling, lowThres, highThres, irisCircle);

    cvCircle(setImg, cvPoint(irisCircle[0], irisCircle[1]), irisCircle[2], CV_RGB(255,255,255), 1, 8);
    ImageUtility::showImage("Iris Circle on the result", setImg);
    ImageUtility::drawCross(setImg, irisCircle[0], irisCircle[1], 10, 10, CV_RGB(255,0,0) );

    CvPoint xyIris;
    xyIris.x = irisCircle[0];
    xyIris.y = irisCircle[1];
    int rIris = irisCircle[2];
    xyIris = FindIrisCircle::getOriginPoints(xyPupil, xyIris, setVal.p, centerAdjust);

    cvReleaseImage(&setImg);

    //find upper and lower eyelids
    double x[3] = {0}, ty[3] = {0}, by[3] = {0};
    FindEyelidCurve *eyelid = NULL;
    Masek::IMAGE* noiseImage = imgUtil->convertIplToImage(eyeImg);
    eyelid->findCurves(eyeImg, xyPupil.x, xyPupil.y, rPupil,
                                xyIris.x,  xyIris.y,  rIris,
                                x, ty, by);


    // debug
//    for (int i=0; i<3; i++) {
//        std::cout << "x:[" << i << "] " << x[i] << std::endl;
//        std::cout << "top ty:[" << i << "] " << ty[i] << std::endl;
//        std::cout << "bot by:[" << i << "] " << by[i] << std::endl;
//    }
    ///////////////////////////

    ImageUtility::showEyeLidPoints("Eye Lid 3 Points", eyeImg, x, ty, by);

    int size = (int)(x[2] - x[0] + 1);
    int *destTY = new int[size];
    int *destBY = new int[size];

    eyelid->calcCurvePoints(eyeImg, x, ty, destTY);
    eyelid->calcCurvePoints(eyeImg, x, by, destBY);

    // debug: eyelid calculation verification
//    int *X1 = new int[size];
//    for(int i=0; i<size; i++) {
//        std::cout << "dest TY [" << i << "]: " << destTY[i] << "|" <<
//                     "dest BY [" << i << "]: " << destBY[i] << std::endl;
//        X1[i] = x[0] + i;
//    }
    //////////////////////////////

//    ImageUtility::drawEyeLidLines(eyeImg, X1, destTY, destBY, size);
//    delete[] X1; // need to delete.
    //// end of debug

    // find interested area only.
    eyelid->maskOutNoise(noiseImage, x, destTY, destBY);
    ImageUtility::showImage("Eyelids masked noise image", imgUtil->convertImageToIpl(noiseImage));

    delete[] destTY;
    delete[] destBY;
    delete eyelid;

    //find eyelashes
    const int min=3, max=250;

    //FindHighLights::removeHighLights2(noiseImage, min, max);//5, 230
    FindHighLights::removeHighLights2(noiseImage, min, max);
    ImageUtility::showImage("Find Eyelashes and reflections", imgUtil->convertImageToIpl(noiseImage));

    cvReleaseImage(&grayImg);
    cvReleaseImage(&eyeImg);

    // iris normalization
    int radialRes = 34;     //orginal value: 20
    int angularRes = 260;   //orignal value: 240

    Masek::filter polarArray;
    Masek::filter *imgWithNoise;
    Masek::IMAGE noiseArray;

    imgWithNoise = (Masek::filter*) malloc(sizeof(Masek::filter));
    imgWithNoise->hsize[0] = noiseImage->hsize[0];
    imgWithNoise->hsize[1] = noiseImage->hsize[1];
    imgWithNoise->data = (double*) malloc(sizeof(double) * noiseImage->hsize[0] * noiseImage->hsize[1]);

    for (int y = 0; y < noiseImage->hsize[0]; y++)
    {
        for (int x = 0; x < noiseImage->hsize[1]; x++)
        {
            if(noiseImage->data[x + y * noiseImage->hsize[1]] < 1)
                imgWithNoise->data[x + y * imgWithNoise->hsize[1]] = sqrt((double) -1);
            else
                imgWithNoise->data[x + y * imgWithNoise->hsize[1]] = (double)noiseImage->data[x + y * noiseImage->hsize[1]];
        }
    }

    free(noiseImage->data);
    free(noiseImage);

    Normalization::normalizeiris(imgWithNoise, xyIris.x,  xyIris.y,  rIris,
                                               xyPupil.x, xyPupil.y, rPupil,
                                (const int)radialRes, (const int)angularRes,
                                &polarArray, &noiseArray);
    // after this polarArray and noseArray will have somevalues.
    std::cout << "POALR ARRAY / NOISE ARRAY" << std::endl;
    for(int i=0; i<polarArray.hsize[0]; i++)
    {
        for(int j=0; j<polarArray.hsize[1]; j++)
        {
            std::cout << "PA[" << i << ", " << j << "] = " << polarArray.data[i+j] << " " <<
                         "NA[" << i << ", " << j << "] = " << noiseArray.data[i+j] << std::endl;
        }
    }
    ImageUtility::showImage("imgWithNoise anfter nomalize", imgUtil->convertFilterToIpl(imgWithNoise));
    ImageUtility::showImage("Nomalized Polar Array", imgUtil->convertFilterToIpl(&polarArray));
    ImageUtility::showImage("Nomalized Noise Array", imgUtil->convertImageToIpl(&noiseArray));

    free(imgWithNoise->data);
    free(imgWithNoise);

    // encoding
//    const int encodeScales = 1;
//    const int mult = 1; //not applicable if using encodeScales = 1
//    int minWaveLength = 18;
//    double sigmaOnf = 0.55;//0.5
//    //float coefThresRate = 0.0f;// for FX: 0.25 and 0.10

//    float magLowerThresRate = 0.02f;
//    float magUpperThresRate = 0.85f;
//    const char *template1 = "/Users/hasbegun/Desktop/testTemplate.mat";

//    Encode::newEncode(&polarArray, &noiseArray, encodeScales, (const int)minWaveLength,
//        mult, (const double)sigmaOnf, template1, mask1, width, height,
//        magLowerThresRate, magUpperThresRate);

//    free(polarArray.data);
//    free(noiseArray.data);
//    delete imgUtil;
    //////////////
}

void IrisAnalysis::eyeAnalysis()
{
    // std::string to char
    //const char *fn = irisFileName.c_str();

    char *fn = new char[irisFileName.length() + 1];
    strcpy(fn, irisFileName.c_str());

    MatchAlg::oneEyeAnalysis(fn, 1);
    delete[] fn;
}

