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

    imshow("input", src);

    Mat hsv, yuv, ycrcb;

    // 将图片转换为HSV格式
    cvtColor(src, hsv, COLOR_BGR2HSV);
    imshow("hsv", hsv);

    // 将图片转换为YUV格式
    cvtColor(src, yuv, COLOR_BGR2YUV);
    imshow("yuv", yuv);

    // 将图片转换为YCrCb格式
    cvtColor(src, ycrcb, COLOR_BGR2YCrCb);
    imshow("ycrcb", ycrcb);

    waitKey(0);

    // 更换背景
    // 读取图片
    Mat src2 = imread("../greenback.png");
    if (src.empty()) {
        std::cout<<"could not load image..."<<std::endl;
        return -1;
    }

    imshow("src2", src2);
    // 将图片转换为HSV格式
    cvtColor(src2, hsv, COLOR_BGR2HSV);
    Mat mask;
    // 选取绿色范围，匹配到图像为白色，没有匹配到为黑色
    /*
     * 参数1: 原图
     * 参数2: HSV范围最小值
     * 参数3: HSV范围最大值
     * 参数4: 匹配到的掩码
     * */
    inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);
    imshow("mask1", mask);

    // 将掩码取反，原来人物为黑色，背景为白色。取反后人物为白色，背景为黑色
    bitwise_not(mask, mask);
    imshow("mask2", mask);

    // 创建一张背景为红色的图片
    Mat redback = Mat::zeros(Size(src2.size()), src2.type());
    redback = Scalar(40, 40, 200);
    // src2按照掩码的白色范围，复制到redback
    src2.copyTo(redback, mask);
    imshow("redback", redback);

    waitKey(0);

    return 0;
}
