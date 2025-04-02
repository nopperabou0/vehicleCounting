// #include "include/opencv2/opencv.hpp"
#include <vector>
#include "include/detection.hpp"
#include <iostream>
#include <fstream>

struct DetectionResult {
  std::vector <float> detectionBoxes[4];
  std::vector <int> vehicleId;
  std::vector <std::string> vehicleClass;
  std::vector <float> confidenceScore;
};





DetectionResult vehicleDetection (){
  DetectionResult detRes;
  std::vector <float> detBoxes[4];
  std::vector <int> Id;
  std::vector <float> confScore;

  std::cout << "Object Detection Model Iniatializion...\n";
  
  
  
  cv::dnn::Net Net = cv::dnn::readNet(model,config);
  cv::dnn::DetectionModel model = cv::dnn::DetectionModel(Net);

  std::vector<std::string> labels;
  std::fstream labelsFile;
  
  labelsFile.open("./models/labels.txt",std::ios_base::in);
  if (labelsFile.is_open()){
    std::string line;
    while(std::getline(labelsFile,line)){
      labels.push_back(line);
    }
  }

  cv::Mat image = cv::imread("test.jpg",0);

  cv::Mat blob = cv::dnn::blobFromImages(image,1.0,cv::Size(1024,682),cv::Scalar(127.5));

  Net.setInput(blob);
  cv::Mat detections = Net.forward();

  for (const auto det: )
  



  return detRes;
}














