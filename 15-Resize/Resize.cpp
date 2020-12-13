#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    Mat src = imread("../lena.jpg");
    if (src.empty()) {
        std::cout << "could not load image..." << std::endl;
        return -1;
    }
    imshow("input", src);

    int h = src.rows;
    int w = src.cols;
    float fx = 0.0, fy = 0.0;

    Mat dst = Mat::zeros(src.size(), src.type());
    // 最近邻插值
    resize(src, dst, Size(w*2, h*2), fx = 0, fy = 0, INTER_NEAREST);
    imshow("INTER_NEAREST", dst);

    // 线性插值
    resize(src, dst, Size(w*2, h*2), fx = 0, fy = 0, INTER_LINEAR);
    imshow("INTER_LINEAR", dst);

    // 三次样条插值
    resize(src, dst, Size(w*2, h*2), fx = 0, fy = 0, INTER_CUBIC);
    imshow("INTER_CUBIC", dst);

    //  Lanczos插值
    // 如果size有值，使用size做放缩插值，否则根据fx与fy卷积
    resize(src, dst, Size(), fx = 1.5, fy = 1.5, INTER_LANCZOS4);
    imshow("INTER_LANCZOS4", dst);

    waitKey(0);

    return 0;
}
