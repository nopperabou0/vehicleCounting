#!/bin/bash
 clang++ -v main.cpp -o vehicleCounter -Wl,-rpath,./lib64 -I. -I./include -L./lib64/ -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc