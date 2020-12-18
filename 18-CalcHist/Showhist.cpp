//
// Created by linux on 12/18/20.
//

#include "Showhist.h"

 void Showhist::showHist(cv::Mat &img, cv::Mat &dst) {
    // 三通道分离
    std::vector<cv::Mat> bgr_plane;
    split(img, bgr_plane);
    // 定义参数变量
    const int channels[1] = { 0 };
    const int bins[1] = { 256 };
    float hranges[2] = { 0,255 };
    const float* ranges[1] = { hranges };
    cv::Mat b_hist;
    cv::Mat g_hist;
    cv::Mat r_hist;
    // 计算Blue, Green, Red通道的直方图
    /*
     * 参数1: 图像
     * 参数2: 输入图像的个数
     * 参数3: 需要统计直方图的第几通道
     * 参数4: 计算掩膜内的直方图
     * 参数5: 输出的直方图数组
     * 参数6: 需要统计直方图通道的个数
     * 参数7: 直方图分成多少个区间
     * 参数8: 统计像素值得区间
     * */
    calcHist(&bgr_plane[0], 1, 0, cv::Mat(), b_hist, 1, bins, ranges);
    calcHist(&bgr_plane[1], 1, 0, cv::Mat(), g_hist, 1, bins, ranges);
    calcHist(&bgr_plane[2], 1, 0, cv::Mat(), r_hist, 1, bins, ranges);
    // 显示直方图
    int hist_w = 512;
    int hist_h = 400;
    // 将输入浮点数转换成整数
    // 返回跟参数最接近的整数值
    int bin_w = cvRound((double)hist_w / bins[0]);
    cv::Mat histImage = cv:: Mat::zeros(hist_h, hist_w, CV_8UC3);
    // 归一化直方图数据
    normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    // 绘制直方图曲线
    for (int i = 1; i < bins[0]; i++) {
        line(histImage, cv:: Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
             cv:: Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))), cv:: Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, cv:: Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
             cv::Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))), cv:: Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
             cv::Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))), cv::Scalar(0, 0, 255), 2, 8, 0);
    }

    dst = histImage;
}

void Showhist::grayHist(cv::Mat &img, cv::Mat &dst) {
    // 定义参数变量
    const int channels[1] = { 0 };
    const int bins[1] = { 256 };
    float hranges[2] = { 0,255 };
    const float* ranges[1] = { hranges };
    cv::Mat gray_hist;
    // 计算Blue, Green, Red通道的直方图
    /*
     * 参数1: 图像
     * 参数2: 输入图像的个数
     * 参数3: 需要统计直方图的第几通道
     * 参数4: 计算掩膜内的直方图
     * 参数5: 输出的直方图数组
     * 参数6: 需要统计直方图通道的个数
     * 参数7: 直方图分成多少个区间
     * 参数8: 统计像素值得区间
     * */
    calcHist(&img, 1, 0, cv::Mat(), gray_hist, 1, bins, ranges);

    // 显示直方图
    int hist_w = 512;
    int hist_h = 400;
    // 将输入浮点数转换成整数
    // 返回跟参数最接近的整数值
    int bin_w = cvRound((double)hist_w / bins[0]);
    cv::Mat histImage = cv:: Mat::zeros(hist_h, hist_w, CV_8UC3);
    // 归一化直方图数据
    normalize(gray_hist, gray_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat());
    // 绘制直方图曲线
    for (int i = 1; i < bins[0]; i++) {
        line(histImage, cv::Point(bin_w*(i - 1), hist_h - cvRound(gray_hist.at<float>(i - 1))),
             cv::Point(bin_w*(i), hist_h - cvRound(gray_hist.at<float>(i))), cv::Scalar(0, 0, 255), 2, 8, 0);
    }

    dst = histImage;
}
