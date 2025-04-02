// #include "include/opencv2/opencv.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include "include/detection.hpp"

struct DetectionResult {
  std::vector<cv::Rect> detectionBoxes;
  std::vector<int> index;
  std::vector <float> confidence;
};

DetectionResult* vehicleDetection (){

  cv::dnn::DetectionModel detectionModel = cv::dnn::DetectionModel(model,config);

  std::fstream labelsFile;
  std::vector<std::string> labels;


  labelsFile.open("./models/labels.txt",std::ios_base::in);
  if (labelsFile.is_open()){
    std::string label;
    while(std::getline(labelsFile,label)){
      labels.push_back(label);
    }
  }

  detectionModel.setInputSize(320,320);
  detectionModel.setInputScale(1.0/127.5);
  detectionModel.setInputMean(127.5);
  detectionModel.setInputSwapRB(true);

  cv::Mat img = cv::imread("./example.png");
  if (img.empty()) {
    std::cerr << "Error: Could not read the image!" << std::endl;
    return nullptr;
}

  cv::dnn::MatShape classIndex;
  std::vector<cv::Rect> bBoxes;
  std::vector <float> confidenceScores;


  detectionModel.detect(img, classIndex,confidenceScores,bBoxes,0.5f,0.0f);


  
  DetectionResult* result = new DetectionResult{
    .detectionBoxes = bBoxes,
    .index = classIndex,
    .confidence = confidenceScores,
  };
  return result;
}














