//
// Created by linux on 11/26/20.
//

#include "Pixelvisit.h"

void Pixelvisit::pixel_visit_at(Mat &image) {
    // 获取图像信息
    int w = image.cols;
    int h = image.rows;
    int dims = image.channels();

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if(dims == 1) { // 单通道
                // 获取单通道的色彩值
                int pv = image.at<uchar>(row, col);
                // 修改通道值为原图的反向
                image.at<uchar>(row, col) = 255-pv;
            }
            if(dims == 3) { // 多通道
                // 获取RGB三通道的色彩值
                Vec3b rgb = image.at<Vec3b>(row, col);
                // 修改通道值为原图的反向
                image.at<Vec3b>(row, col)[0] = 255-rgb[0];
                image.at<Vec3b>(row, col)[1] = 255-rgb[1];
                image.at<Vec3b>(row, col)[2] = 255-rgb[2];
            }
        }
    }

    imshow("image", image);
}

void Pixelvisit::pixel_visit_pointer(Mat &image) {
    // 获取图像信息
    int w = image.cols;
    int h = image.rows;
    int dims = image.channels();

    for(int row = 0; row < h; row++) {
        uchar *p = image.ptr<uchar>(row);
        for(int col = 0; col < w; col++) {
            if(dims == 1) { // 单通道
                // 获取单通道的色彩值
                int pv = *p;
                // 修改通道值为原图的反向
                *p++ = 255 - pv;
            }
            if(dims == 3) { // 多通道
                // 修改通道值为原图的反向
                *p++ = 255 - *p;
                *p++ = 255 - *p;
                *p++ = 255 - *p;
            }
        }
    }

    imshow("image", image);
}
