#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    Mat src1, src2, src3, src4;

	// 读取图片
    src1 = imread("../m1.png");
    src2 = imread("../m2.png");
    src3 = imread("../flower.png");
    src4 = imread("../test.png");

	// 判断图片是否存在
    if (src1.empty() || src2.empty() || src3.empty() || src4.empty()) {
        std::cout<<"could not load image..."<<std::endl;
        return -1;
    }

	// 显示图片
    imshow("input1", src1);
    imshow("input2", src2);
    imshow("input3", src3);
    imshow("input4", src4);

	// 将BGR装换成HSV
    Mat hsv1, hsv2, hsv3, hsv4;
    cvtColor(src1, hsv1, COLOR_BGR2HSV);
    cvtColor(src2, hsv2, COLOR_BGR2HSV);
    cvtColor(src3, hsv3, COLOR_BGR2HSV);
    cvtColor(src4, hsv4, COLOR_BGR2HSV);

    int h_bins = 60; int s_bins = 64;
    int histSize[] = {h_bins, s_bins};
    float h_ranges[] = {0, 180};
    float s_ranges[] = {0, 256};
    const float *ranges[] = {h_ranges, s_ranges};
    int channels[] = {0, 1};

	// 统计h通道和s通道两个通道的直方图数据
    Mat hist1, hist2, hist3, hist4;
    calcHist(&hsv1, 1, channels, Mat(), hist1, 2, histSize, ranges, true, false);
    calcHist(&hsv2, 1, channels, Mat(), hist2, 2, histSize, ranges, true, false);
    calcHist(&hsv3, 1, channels, Mat(), hist3, 2, histSize, ranges, true, false);
    calcHist(&hsv4, 1, channels, Mat(), hist4, 2, histSize, ranges, true, false);

	// 执行归一化
    normalize(hist1, hist1, 0, 1, NORM_MINMAX, -1, Mat());
    normalize(hist2, hist2, 0, 1, NORM_MINMAX, -1, Mat());
    normalize(hist3, hist3, 0, 1, NORM_MINMAX, -1, Mat());
    normalize(hist4, hist4, 0, 1, NORM_MINMAX, -1, Mat());

	// 使用相关性算法比较
    double src1_src2 = compareHist(hist1, hist2, HISTCMP_CORREL);
    double src3_src4 = compareHist(hist3, hist4, HISTCMP_CORREL);
    printf("Method HISTCMP_CORREL : src1_src2 : %f, src3_src4: %f\n", src1_src2, src3_src4);

	// 使用卡方算法比较
    src1_src2 = compareHist(hist1, hist2, HISTCMP_CHISQR);
    src3_src4 = compareHist(hist3, hist4, HISTCMP_CHISQR);
    printf("Method HISTCMP_CHISQR : src1_src2 : %f, src3_src4: %f\n", src1_src2, src3_src4);

	// 使用交叉算法比较
    src1_src2 = compareHist(hist1, hist2, HISTCMP_INTERSECT);
    src3_src4 = compareHist(hist3, hist4, HISTCMP_INTERSECT);
    printf("Method HISTCMP_INTERSECT : src1_src2 : %f, src3_src4: %f\n", src1_src2, src3_src4);

	// 使用巴氏算法比较
    src1_src2 = compareHist(hist1, hist2, HISTCMP_BHATTACHARYYA);
    src3_src4 = compareHist(hist3, hist4, HISTCMP_BHATTACHARYYA);
    printf("Method HISTCMP_BHATTACHARYYA : src1_src2 : %f, src3_src4: %f\n", src1_src2, src3_src4);

    waitKey(0);

    return 0;
}
