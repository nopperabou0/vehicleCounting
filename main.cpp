#include "include/opencv2/opencv.hpp"
#include <iostream>



int main (){
  cv::Mat img_grayscale = cv::imread("test.jpg",0);
  cv::imshow("grayscale image",img_grayscale);
  cv::waitKey(0);
  cv::destroyAllWindows();
  cv::imwrite("grayscale.jpg",img_grayscale);
  return 0;
}
