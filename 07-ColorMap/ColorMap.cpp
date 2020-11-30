#include <iostream>
#include <opencv2/opencv.hpp>

#include "CustomColorMap.h"

using namespace cv;

int main() {
    // 打开图片
    Mat src = imread("../coins.jpg");

    if (src.empty()) {
        std::cout << "could not load image..." << std::endl;
        return -1;
    }
    Mat dst;

    // 设置图像LUT
    applyColorMap(src, dst, COLORMAP_SUMMER);
    // 显示图像
    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);

    // 自己实验的二值化函数
    CustomColorMap ccm = CustomColorMap();

    Mat gray;

    // 将图像设置为灰度图
    cvtColor(src, gray, COLOR_BGR2GRAY);
    imshow("gray", gray);
    // 调用实现的二值化函数
    ccm.customColorMap(gray);

    waitKey(0);

    return 0;
}
