#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    Mat src = imread("../lena.jpg");
    if (src.empty()) {
        std::cout<<"could not load image..."<<std::endl;
        return -1;
    }

    imshow("input", src);

    // 设置一个类型为Mat的容器
    std::vector<Mat> mv;
    Mat dst1, dst2, dst3;

    // 分离通道
    // mv[0] = B
    // mv[1] = G
    // mv[2] = R
    split(src, mv);
    // 将B通道和G通道颜色值设置为0，只保留R通道
    mv[0] = Scalar(0);  // B = 0
    mv[1] = Scalar(0);  // G = 0
    // 将mv合并通道
    merge(mv, dst1);
    // 显示R通道图像
    imshow("dst1 R", dst1);

    // 分离通道
    split(src, mv);
    // 将B通道和R通道颜色值设置为0，只保留G通道
    mv[0] = Scalar(0);  // B = 0
    mv[2] = Scalar(0);  // R = 0
    // 将mv合并通道
    merge(mv, dst2);
    // 显示G通道图像
    imshow("dst2 G", dst2);

    // 分离通道
    split(src, mv);
    // 将G通道和R通道颜色值设置为0，只保留B通道
    mv[1] = Scalar(0);  // G = 0
    mv[2] = Scalar(0);  // R = 0
    // 将mv合并通道
    merge(mv, dst3);
    // 显示B通道图像
    imshow("dst3 B", dst3);

    waitKey(0);

    return 0;
}
