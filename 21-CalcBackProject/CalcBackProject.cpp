#include <opencv2/opencv.hpp>

using namespace cv;

int main (int argc, char *argv[])
{
	// 读取图片并显示
    Mat src = imread("../target.png");
    Mat model = imread("../sample.png");
    if (src.empty() || model.empty()) {
        std::cout<<"could not load image..."<<std::endl;
        return -1;
    }

    imshow("input", src);
    imshow("model", model);

    Mat model_hsv, image_hsv;

	// 将BRG图片转换成HSV图片
    cvtColor(model, model_hsv, COLOR_BGR2HSV);
    cvtColor(src, image_hsv, COLOR_BGR2HSV);

	// 设置H通道和S通道的bins为32个
    int h_bins = 32, s_bins = 32;
    int histSize[] = {h_bins, s_bins};

	// 设置H通道和S通道的范围
    float h_ranges[] = {0, 180};
    float s_ranges[] = {0, 256};
    const float *ranges[] = {h_ranges, s_ranges};

	// 设置要统计的通道数
    int channles[] = {0, 1};
    Mat roiHist;

	// 直方图统计 统计H通道和S通道
    calcHist(&model_hsv, 1, channles, Mat(), roiHist, 2, histSize, ranges, true, false);
	// 直方图归一化 0~255
	normalize(roiHist, roiHist, 0, 255, NORM_MINMAX, -1, Mat());
    MatND backproj;
	// 直方图反向投影
	// 参数1: 输入图像
	// 参数2: 输入图像数量
	// 参数3: 用于计算反向投影的通道列表
	// 参数4: 输入直方图
	// 参数5: 目标反向投影输出图像
	// 参数6: 直方图每个维度bin的取值范围
	// 参数7: 反向投影的比例因子
    calcBackProject(&image_hsv, 1 , channles, roiHist, backproj, ranges, 1.0);

    imshow("BackProj", backproj);

    waitKey(0);
}
