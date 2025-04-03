#include <vector>
#include <iostream>
#include <fstream>
#include "include/detection.hpp"

struct DetectionResult {
  std::vector<cv::Rect> detectionBoxes;
  std::vector<int> index;
  std::vector <float> confidence;
};

DetectionResult* vehicleDetection (cv::Mat &img){

  cv::dnn::DetectionModel detectionModel = cv::dnn::DetectionModel(model,config);

  detectionModel.setInputSize(640,640);
  detectionModel.setInputScale(1.0/127.5);
  detectionModel.setInputMean(127.5);
  detectionModel.setInputSwapRB(true);

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














