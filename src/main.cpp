/**
	@author Fabio Dominio
	@version 0.1.0
	@date 2021/08/11
*/

// Include standard headers
#include <iostream>
#include <functional>
#include <thread>
#include <string>

// Include opencv headers
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Define employed namespaces
using namespace std;
using namespace cv;

// Define constants
const string SAVE_PATH = ""; // Path where to save the grabbed frames
const int WIDTH = 1280; // Frame width (pixels)
const int HEIGHT = 960; // Frame height (pixels)
// Define variables;
int fps = 0;
int fpsCounter = 0;
long frameNr = 0;
int savedFrames = 0;
char key = 0;

// Define opencv data structures
Mat frame;
Mat colorImage;
Mat processedImage;
VideoCapture cap;

// Define utility methods
// FPS update
void fpsUpdate()
{
	fps = fpsCounter;
	fpsCounter = 0;
}

// FPS counter method
void timer_start(std::function<void(void)> func, unsigned int interval)
{
	std::thread([func, interval]() {
		while (true)
		{
			func();
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
		}
	}).detach();
}

// Memory cleanup method
void cleanup() {
	// Cleanup memory
	frame.release();
}

// Main method
int main() {
	// Open default webcam, after selecting a supported resolution    
	bool res = cap.open(0);
	if (!res) {
		// Camera not open
		cerr << "Unable to open default camera!" << endl;
		cin.get();
		exit(-1);
	}
	
	// Else camera open; set frame size
/*	res = cap.set(CAP_PROP_FRAME_WIDTH, WIDTH);
	if (!res) {
		// Frame width not set
		cerr << "Unable to set frame width!" << endl;
		cin.get();
		exit(-1);
	}
	res = cap.set(CAP_PROP_FRAME_HEIGHT, HEIGHT);
	if (!res) {
		// Frame height not set
		cerr << "Unable to set frame height!" << endl;
		cin.get();
		exit(-1);
    }	*/
	
	// Create preview window
	namedWindow("Color stream");

	// Start fps counter thread
	timer_start(fpsUpdate, 1000);
	
	// Start streaming until ESC is pressed
	cout << "Acquisition started" << endl;

	while (key != 27) {
		frameNr++;
		// Grab frame
		res = cap.grab();
		if (!res) {
			cerr <<"Unable to grab frame " << frameNr << endl;			
		}
		else {	
			// Retrieve frame
			res = cap.retrieve(frame);
			if (res) {
				fpsCounter++;
				colorImage = frame.clone();
				processedImage = frame.clone();

				////////////////////////////////////////////////////////////
				// INSERT HERE THE FRAME PROCESSING CODE				 //
				////////////////////////////////////////////////////////////

				////////////////////////////////////////////////////////////////

				// Update frame counter
				putText(frame, "Current FPS: " + to_string(fps), Point(10, 50), FONT_HERSHEY_PLAIN, 3, Scalar(255, 255, 255));
				// Display frame
				imshow("Color stream", frame);				
			}
			else
				cerr << "Unable to grab frame " << frameNr << endl;			
		}		

		// Grab key
		key = waitKey(1);

		// Save frame if required
		if (key == 'g' || key == 'G') {
			// Save grabbed frame
			imwrite(SAVE_PATH + to_string(++savedFrames) + "_RGB.png", colorImage); // Change file name if desired
			imwrite(SAVE_PATH + to_string(savedFrames) + "_PROCESSED.png", processedImage); // Change file name if desired
			cout <<"Frame " << savedFrames << " saved" << endl;
		}
	} // End while	

	// Cleanup
	destroyAllWindows();
	cleanup();
	exit(0);
}
