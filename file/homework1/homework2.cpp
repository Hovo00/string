#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

cv::Mat src, dst;
int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
const int max_operator = 4;
const int max_elem = 2;
const int max_kernel_size = 21;
const char* window_name = "Morphology Transformations Demo";
void Morphology_Operations( int, void* );
int main( int argc, char** argv )
{
	cv::CommandLineParser parser( argc, argv, "{@input | baboon.jpg | input image}" );
  src = cv::imread( cv::samples::findFile( parser.get<cv::String>( "@input" ) ), cv::IMREAD_COLOR );
  if (src.empty())
  {
    std::cout << "Could not open or find the image!\n" << std::endl;
    std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
    return EXIT_FAILURE;
  }
  cv::namedWindow( window_name, cv::WINDOW_AUTOSIZE ); // Create window
  cv::createTrackbar("Operator:\n 0: Opening - 1: Closing  \n 2: Gradient - 3: Top Hat \n 4: Black Hat", window_name, &morph_operator, max_operator, Morphology_Operations );
  cv::createTrackbar( "Element:\n 0: Rect - 1: Cross - 2: Ellipse", window_name,
                  &morph_elem, max_elem,
                  Morphology_Operations );
  cv::createTrackbar( "Kernel size:\n 2n +1", window_name,
                  &morph_size, max_kernel_size,
                  Morphology_Operations );
  Morphology_Operations( 0, 0 );
  cv::waitKey(0);
  return 0;
}
void Morphology_Operations( int, void* )
{
  // Since MORPH_X : 2,3,4,5 and 6
  int operation = morph_operator + 2;
  cv::Mat element = cv::getStructuringElement( morph_elem, cv::Size( 2*morph_size + 1, 2*morph_size+1 ), cv::Point( morph_size, morph_size ) );
  cv::morphologyEx( src, dst, operation, element );
  cv::imshow( window_name, dst );
}
