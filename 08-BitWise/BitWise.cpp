#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // 创建一个400*400的3通道图像
    Mat src1 = Mat::zeros(Size(400, 400), CV_8UC3);
    // 创建一个左上角顶点为100，100高度为100，宽度为100的矩形。
    Rect rect(100, 100, 100, 100);
    // 将rect的矩形填充为红色。
    src1(rect) = Scalar(0, 0, 255);
    imshow("input1", src1);
    std::cout << "create first image..." << std::endl;

    // // 创建一个左上角顶点为150，150高度为100，宽度为100的矩形。
    Mat src2 = Mat::zeros(Size(400, 400), CV_8UC3);
    rect.x = 150;
    rect.y = 150;
    src2(rect) = Scalar(0, 0, 255);
    imshow("input2", src2);
    std::cout << "create first image..." << std::endl;

    // 逻辑操作
    Mat dst1, dst2, dst3;
    bitwise_and(src1, src2, dst1);
    bitwise_xor(src1, src2, dst2);
    bitwise_or(src1, src2, dst3);

    imshow("dst1", dst1);
    imshow("dst2", dst2);
    imshow("dst3", dst3);

    waitKey(0);

    Mat src = imread("../lena.jpg");
    if (src.empty()) {
        std::cout << "could not load image..." << std::endl;
        return -1;
    }

    imshow("src", src);
    Mat dst;
    // 取反操作
    bitwise_not(src, dst);
    imshow("dst", dst);

    waitKey(0);

    return 0;
}
