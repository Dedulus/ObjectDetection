//Usage:  Use the HOG descriptor to detect objects in a video along with SVM(program compiled in Release mode)

//Version : 1.0, Date : 2 January 2023

//Owner : Arnab Mitra

//Contact : papan.mitra.2121@gmail.com


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// Read video file
	VideoCapture cap("detectchallenge.mp4");

	// Check if video is opened
	if (!cap.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	// Create the HOG Descriptor
	HOGDescriptor hog;

	// Set the SVM Detector
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

	// Read frames one by one
	while (1)
	{
		Mat frame;
		bool bSuccess = cap.read(frame);
		if (!bSuccess)
		{
			cout << "Found the end of the video" << endl;
			break;
		}

		// Detect people in the frame
		vector<Rect> cars;
		hog.detectMultiScale(frame, cars);

		// Draw the boxes around detected cars
		for (int i = 0; i < cars.size(); i++)
		{
			Rect r = cars[i];
			rectangle(frame, r.tl(), r.br(), Scalar(0, 0, 255), 2);
		}

		

		imshow("MyVideo", frame);
		if (waitKey(30) == 27)
		{
			
			std::cout << "Found it interesting? :).......For more such implementation please consider my profile for the interview,where I can discuss more about such ideas(cool). Thank you :)" << std::endl;
			std::cout << "        " << std::endl;
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;

			 

		}
	}
	cap.release();
	destroyAllWindows();
	return 0;
}



