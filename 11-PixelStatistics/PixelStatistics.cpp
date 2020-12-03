#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    // 读取图片为灰度图
    Mat src = imread("../lena.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) {
        cout<<"could not load image..."<<endl;
        return -1;
    }

    imshow("input", src);

    double minVal, maxVal;  // 用于存放最大值最小值
    Point minLoc, maxLoc;   // 用于存放最大值与最小值的x,y坐标
    Mat means, stddev;  // 用于存放均值和方差

    // 获取最大值和最小值，以及最大值和最小值的坐标
    minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

    // 打印相关信息
    cout<<"min: "<< minVal <<", max: "<< maxVal <<endl;
    cout<<"min Loc x: "<< minLoc.x<< ", min Loc y: " << minLoc.y <<endl;
    cout<<"max Loc x: "<< maxLoc.x<< ", max Loc y: " << maxLoc.y <<endl;

    // 获取均值和方差
    meanStdDev(src, means, stddev);
    // 打印均值和方差，单通道固定为(0, 0)
    printf("gray channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(0, 0), stddev.at<double>(0,0));

    // 获取图像尺寸
    int h = src.rows;
    int w = src.cols;

    // 通过判断均值来实现二值化
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            // 获取原图像素点的颜色值
            int pv = src.at<uchar>(row, col);
            // 如果颜色值小于均值则设置为0
            if (pv < means.at<double>(0, 0)) {
                src.at<uchar>(row, col) = 0;
            }
            // 如果颜色值大于等于均值则设置为255
            if (pv >= means.at<double>(0, 0)) {
                src.at<uchar>(row, col) = 255;
            }
        }
    }
    // 显示图片
    imshow("out", src);

    waitKey(0);


    Mat src2;
    // 读取为彩色图片
    src2 = imread("../lena.jpg");

    // 获取图片的均值和方差
    meanStdDev(src2, means, stddev);

    /*
     * 获取3通道的均值和方差，数据保存在Mat对象中。是一个3行1列的二维数组
     * (0, 0)表示第0行，第0列。为B通道。
     * (1, 0)表示第1行，第0列。为G通道。
     * (2, 0)表示第2行，第0列。为R通道。
     * */

    printf("blue channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(0, 0), stddev.at<double>(0,0));
    printf("green channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(1, 0), stddev.at<double>(1,0));
    printf("red channel->> mean: %.2f, stddev: %.2f\n", means.at<double>(2, 0), stddev.at<double>(2,0));

    waitKey(0);

    return 0;
}
