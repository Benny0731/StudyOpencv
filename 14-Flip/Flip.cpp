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

    // 显示原始图片
    imshow("input", src);

    Mat dst;

    // 倒影
    flip(src, dst, 0);
    imshow("x-flip", dst);

    // 镜像
    flip(src, dst, 1);
    imshow("y-flip", dst);

    // 对角
    flip(src, dst, -1);
    imshow("xy-flip", dst);

    waitKey(0);

    return 0;
}
