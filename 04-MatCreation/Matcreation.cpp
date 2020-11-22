//
// Created by liuzh on 2020/11/22.
//

#include "Matcreation.h"


void Matcreation::ones_demo() {
    // 新建1通道8*8图像并填充为1
    Mat M1 = Mat::ones(Size(8, 8), CV_8UC1);
    std::cout << "ones_demo M1: " << M1 << std::endl;

    // 新建3通道8*8图像并填充为1
    Mat M2 = Mat::ones(Size(8, 8), CV_8UC3);
    // ones只会将填充第1个通道为1
    std::cout << "ones_demo M2: " << M2 << std::endl;
}

void Matcreation::creation_demo() {
    // 新建3通道240*320图像并填充为0
    Mat M1 = Mat::zeros(Size(240,320), CV_8UC3);
    // std::cout << "M1: " << M1 << std::endl;
    // 通过Mat获取image信息
    std::cout << "creation_demo width: " << M1.cols << std::endl;
    std::cout << "creation_demo height: " << M1.rows << std::endl;
    std::cout << "creation_demo channels: " << M1.channels() << std::endl;

    // 将M1填充为绿色
    M1 = Scalar(0, 255, 0); // B, G, R
    imshow("creation_demo M1", M1);

    Mat M2 = M1;    // 相当于指针赋值
    // 修改M2等于修改M1，修改为红色
    M2 = Scalar(0, 0, 255);
    imshow("copy M1", M1);

    waitKey(0);
}

void Matcreation::copy_demo() {
    // 新建3通道240*320图像并填充为0
    Mat M1 = Mat::zeros(Size(240, 320), CV_8UC3);
    // 将M1填充为蓝色
    M1 = Scalar(255, 0, 0);
    // 显示M1
    imshow("copy_demo M1", M1);
    // 等待按键按下
    waitKey(0);

    Mat M2, M3;
    // 使用copyTo方法拷贝M1到M2
    M1.copyTo(M2);
    // M2填充为绿色
    M2 = Scalar(0, 255, 0);
    // 显示M1，M2
    imshow("copy_demo M1", M1);
    imshow("copyTo M2", M2);
    waitKey(0);

    // 使用clone方法将M1克隆到M3
    M3 = M1.clone();
    // M2填充为红色
    M3 = Scalar(0, 0, 255);
    // 显示M1，M3
    imshow("copy_demo M1", M1);
    imshow("clone M3", M3);
    waitKey(0);
}
