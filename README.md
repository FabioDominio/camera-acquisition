# Camera Acquisition

This tool is a simple blueprint of an OpenCV based application in C++ for grabbing and processing frames from a commodity webcam.



## Requirements

This tool requires:

- CMake
- an updated OpenCV library version installed (possibly >= 4.0)



## Configuration

So far, the application does not adapt itself to any webcam, hence the camera frame size, framerate and the grabbed frames folder must be set manually inside the `main.cpp` file in the `src` folder.



## Build

To build the application, open the root folder with CMake (the one containing the file `CMakeLists.txt`) and select the build folder and the compiler.

Should CMake be unable to find the OpenCV library path by itself, set the `OpenCV_DIR` variable to the proper path (the one containing the file `OpenCVConfig.cmake`). 

In absence of errors, press the "Generate" button and either compile the solution from the command line (eg. with `make`) or inside the selected IDE.



## Installation

Type `make install` from the command line (Linux) or compile the `INSTALL` project in Visual Studio.

The compiled application will be put inside the `install/bin` folder in the selected build path.

Should the system be unable to run the application due to missing dependencies, copy the `opencv_world` dynamic library inside the executable folder.



## Running

Just run the executable.

Press the "`g`" button to save a frame in the selected folder, or the "`ESC`" button to exit the application.
