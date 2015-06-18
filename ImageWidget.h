
#ifndef IMAGE_WIDGET_H
#define IMAGE_WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QObject>

#include <opencv/cxcore.h>

class QImage;

/**
 * Qt widget to display an OpenCV IplImage.
 */
class ImageWidget : public QWidget
{
    Q_OBJECT
public:
	/**
	 * Initializes the widget.
	 * A blank rectangle is drawn until an image is set.
	 *
	 * @param parent Parent widget
	 */
    ImageWidget(QWidget* parent = 0);
    virtual ~ImageWidget();

	/** 
	 * Sets the image that should be displayed.
	 *
	 * @note Internally, the IplImage is converted to a QImage
	 *
	 * @param image Input image
	 */
    void setImage(QImage* image);

	/** 
	 * Sets the image that should be displayed.
	 *
	 * @param img Input image.
     * @param copy true=make a deep copy of the image data
	 */
    void setImage(IplImage* img, bool copy=false);

	/**
	 * Removes the current image.
	 * This will result in a blank rectangle - similar to the constructor.
	 */
    void reset();

	/**
	 * Draws a rectangle on top of the image.
	 *
	 * @note This method can be called multiple times in-between setImage()
	 *    to draw multiple rectangles.
	 *
	 * @param rect Rectangle coordinates and size
	 */
    void addRectange(CvRect& rect);
	
	//TESTING
	//void addEllipse(CvRect& ellip);

protected:
   /**
    * Release the current image
    */
    void releaseImage();

	/**
	 * Redraws the widget.
	 * 
	 * @note Do not call this method directly!
	 */
    void paintEvent(QPaintEvent *event);

	/** 
	 * Converts an IplImage to a QImage
	 *
	 * @param img Input image
	 * @param dest Destination image
     * @param destData Data buffer (or NULL)
	 * @return Returns \c dest
	 */
    QImage iplToQImage(IplImage* img, QImage*& dest, uchar** destData);

	QPen*         rectPen;
    uchar*        imgDataCopy;
    QImage*       image;
    QList<QRect>  rects;

};
#endif  //IMAGE_WIDGET_H
