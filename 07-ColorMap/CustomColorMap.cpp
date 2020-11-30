//
// Created by linux on 11/29/20.
//

#include "CustomColorMap.h"

void CustomColorMap::customColorMap(Mat &image) {
    int lut[256];

    // 设置LUT表，小于127的颜色值都设置为0，大于等于127的颜色值都设置为255
    for (int i = 0; i < 256; i++) {
        if (i < 127) {
            lut[i] = 0;
        } else {
            lut[i] = 255;
        }
    }

    int h = image.rows;
    int w = image.cols;

    // 遍历图片像素
    for (int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            // 读取当前像素值
            int pv = image.at<uchar>(row, col);
            // 查表设置LUT中的值
            image.at<uchar>(row, col) = lut[pv];
        }
    }

    imshow("customColorMap", image);
}
