#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture video(0);
	// VideoCapture video("cup.mp4");
	if (video.isOpened()) {
		video.set(CAP_PROP_FRAME_WIDTH, 320);
		video.set(CAP_PROP_FRAME_HEIGHT, 240);
		video.set(CAP_PROP_FPS, 15);
	} else {
		cout << "请确认视频文件名称是否正确" << endl;
		return -1;
	}

	while (video.isOpened()) {
		Mat frame, gray_frame;
		video >> frame;

		if (frame.empty())
			break;

		cvtColor(frame, gray_frame, COLOR_BGR2GRAY);

		imshow("video", frame);
		imshow("gray video", gray_frame);

		waitKey(3);
	}

	video.release();
	destroyAllWindows();

	return 0;
}
