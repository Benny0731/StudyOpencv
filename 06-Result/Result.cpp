#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    // 打开示例图像
    Mat src1 = imread("/home/liuzh/Downloads/opencv-4.1.0/samples/data/LinuxLogo.jpg");
    Mat src2 = imread("/home/liuzh/Downloads/opencv-4.1.0/samples/data/WindowsLogo.jpg");

    // 判断是否为空
    if (src1.empty() || src2.empty()) {
        cout << "could not load image..." << endl;
        return -1;
    }

    // 显示原图
    imshow("input1", src1);
    imshow("input2", src2);

    int height = src1.rows;
    int width = src2.cols;

    int b1 = 0, g1 = 0, r1 = 0;
    int b2 = 0, g2 = 0, r2 = 0;
    int b = 0, g = 0, r = 0;

    // 创建空图用于保存计算后的图像
    Mat result = Mat::zeros(src1.size(), src1.type());

    // 自己实现的加法功能
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // 读取b g r三个通道的值
            b1 = src1.at<Vec3b>(row, col)[0];
            g1 = src1.at<Vec3b>(row, col)[1];
            r1 = src1.at<Vec3b>(row, col)[2];

            b2 = src2.at<Vec3b>(row, col)[0];
            g2 = src2.at<Vec3b>(row, col)[1];
            r2 = src2.at<Vec3b>(row, col)[2];

            // saturate_cast为强制类型转换函数
            result.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b1+b2);
            result.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g1+g2);
            result.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r1+r2);

        }
    }

    imshow("result", result);

    // 调用opencv提供的加、减、乘、除功能
    Mat add_result = Mat::zeros(src1.size(), src1.type());
    add(src1, src2, add_result);
    imshow("add_result", add_result);

    Mat mul_result = Mat::zeros(src1.size(), src1.type());
    multiply(src1, src2, mul_result);
    imshow("mul_result", mul_result);

    Mat sub_result = Mat::zeros(src1.size(), src1.type());
    subtract(src1, src2, sub_result);
    imshow("sub_result", sub_result);

    Mat div_result = Mat::zeros(src1.size(), src1.type());
    divide(src1, src2, div_result);
    imshow("div_result", div_result);

    waitKey(0);

    return 0;
}