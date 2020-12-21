#include <opencv2/opencv.hpp>

using namespace cv;

int main (int argc, char *argv[])
{
	// 读取图片
    Mat src = imread("../lena.jpg");
    if (src.empty()) {
        std::cout<<"could not load image..."<<std::endl;
        return -1;
    }

    Mat gray, dst;
	// 将图片转为灰度图
    cvtColor(src, gray, COLOR_BGR2GRAY);
    imshow("input", gray);
	// 执行直方图均衡化
    equalizeHist(gray, dst);
    imshow("eq", dst);

    waitKey(0);

	// 将彩色图片直方图均衡化
    Mat ycrcb;
    std::vector<Mat> channels;
    cvtColor(src, ycrcb, COLOR_BGR2YCrCb);
    split(ycrcb, channels);
    equalizeHist(channels[0], channels[0]);
    Mat result;
    merge(channels, ycrcb);
    cvtColor(ycrcb, result, COLOR_YCrCb2BGR);
    imshow("result", result);
    imshow("src", src);

    waitKey(0);

    return 0;
}
