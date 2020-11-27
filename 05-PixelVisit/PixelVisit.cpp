#include <iostream>

#include "Pixelvisit.h"

int main() {
    /*
     * 0: 灰度
     * 1: 彩色
     * */
    Mat image = imread("../lena.jpg", 1);
    imshow("image show", image);
    // 使用类实现
    // Pixelvisit::pixel_visit_at(image);
    // 使用指针实现
    Pixelvisit::pixel_visit_pointer(image);
    waitKey(0);

    return 0;
}
