#include <iostream>
#include "include/opencv2/opencv.hpp"
#include "detection.cpp"



int main (){

    std::fstream labelsFile;
    std::vector<std::string> labels;
  
  
    labelsFile.open("./models/labels.txt",std::ios_base::in);
    if (labelsFile.is_open()){
      std::string label;
      while(std::getline(labelsFile,label)){
        labels.push_back(label);
      }
    }
  
  cv::Mat img  = cv::imread("./example.png");
  
  if (img.empty()) {
    std::cerr << "Error: Could not read the image!" << std::endl;
    return -1;
    }

  DetectionResult* detRes = vehicleDetection(img);  

  if (detRes == nullptr) {
      std::cerr << "Error: Detection failed!" << std::endl;
      return -1;  // Exit with error
  }

  cv::Scalar color = {0.0,127.0,0.0};

  for (size_t i = 0 ; i <  detRes->detectionBoxes.size(); i++ ){
    cv::Point point = {detRes->detectionBoxes[i].x,detRes->detectionBoxes[i].y};
    cv::putText(img,labels[detRes->index[i]-1],point,cv::FONT_HERSHEY_SIMPLEX,0.5,color,2);
    cv::rectangle(img,detRes->detectionBoxes[i],color);
    std::cout<<labels[i]<<"\n";
  } 


//   if (!detRes->index.empty()) {
    //   std::cout << "First detected class index: " << detRes->detectionBoxes[0] << std::endl;
//   } else {
    //   std::cout << "No objects detected." << std::endl;
//   }

  cv::imshow("Detected Image",img);
  cv::waitKey(0);
  cv::destroyAllWindows();

  // Free allocated memory
  delete detRes;

  return 0;
}
