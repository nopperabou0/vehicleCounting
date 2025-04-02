#include <iostream>
#include "detection.cpp"



int main (){
  
  DetectionResult* detRes = vehicleDetection();
    
  if (detRes == nullptr) {
      std::cerr << "Error: Detection failed!" << std::endl;
      return -1;  // Exit with error
  }

  if (!detRes->index.empty()) {
      std::cout << "First detected class index: " << detRes->index[0] << std::endl;
  } else {
      std::cout << "No objects detected." << std::endl;
  }

  // Free allocated memory
  delete detRes;

  return 0;
}
