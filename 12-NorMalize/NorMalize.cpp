#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // 读取图片
    Mat src = imread("../lena.jpg");
    if (src.empty()) {
        std::cout<<"could not load image..."<<std::endl;
        return -1;
    }

    Mat gray;
    // 设置为灰度图
    cvtColor(src, gray, COLOR_BGR2GRAY);
    // 将gray转换为CV_32F类型
    gray.convertTo(gray, CV_32F);

    /*
     * Ai: 当前像素点
     * Ah: 最大的像素点
     * Al: 最小的像素点
     * An: 每一个像素点
     * NORM_MINMAX = Ai/max(Ah)-min(Al)
     * NORM_INF = Ai/max(Ai)
     * NORM_L1 = Ai/A1+A2+A3...+An
     * NORM_L2 =
     * */
    // 像素归一化
    Mat dst = Mat::zeros(src.size(), CV_32FC1);
    normalize(gray, dst, 1.0, 0, NORM_MINMAX);
    Mat result = dst * 255;
    result.convertTo(dst, CV_8UC1);
    imshow("NORM_MINMAX", dst);

    normalize(gray, dst, 1.0, 0, NORM_INF);
    result = dst * 255;
    result.convertTo(dst, CV_8UC1);
    imshow("NORM_INF", dst);

    normalize(gray, dst, 1.0, 0, NORM_L1);
    result = dst * 10000000;
    result.convertTo(dst, CV_8UC1);
    imshow("NORM_L1", dst);

    normalize(gray, dst, 1.0, 0, NORM_L2);
    result = dst * 10000;
    result.convertTo(dst, CV_8UC1);
    imshow("NORM_L2", dst);

    waitKey(0);

    return 0;
}
