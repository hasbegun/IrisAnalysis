
#ifndef IMAGE_SOURCE_H
#define IMAGE_SOURCE_H

/**
 * Abstract class that defines the methods an image source, i.e. provider,
 * needs to implement.
 */
class ImageSource
{
public:
  /**
   * This method should returns a single sentence describing the image source.
   */
  virtual const char* getDescription() const = 0;
  
  /**
   * This method should return the number of available images.
   *
   * @return Number of available images (>= 0)
   */
  virtual int getNumberOfImages() const = 0;

   /**
   * This method should return \c true in case there are more images that can
   * be fetched using getNextImage()
   *
   * @return \c true = one or more images available, \c false = no images
   */
  virtual bool hasNextImage() = 0;

  /**
   * This method should return the next image.
   *
   * @note The deallocation of the returned image is up to the program.
   *
   * @return Next image, or \c NULL in case of an error or if there is not any
   *    image left for processing
   */
  virtual IplImage* getNextImage() = 0;
};

#endif // !IMAGE_SOURCE_H
