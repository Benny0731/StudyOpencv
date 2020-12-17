#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	// 读取图片并显示
    Mat src = imread("../lena.jpg");
    if (src.empty()) {
        std::cout << "could not load image..." << std::endl;
        return -1;
    }
    namedWindow("input", WINDOW_AUTOSIZE);
    imshow("input", src);

	// 获取图片尺寸
    int h = src.rows;
    int w = src.cols;

	// 计算图片中心点
    int cy = h / 2;
    int cx = w / 2;

	// 设置ROI区域，并显示
	// 将图片中心点向左平移100像素再向上平移100像素的点设置为ROI矩形的左上角顶点
	// ROI的尺寸为200*200
    Rect rect(cx-100, cy-100, 200, 200);
    Mat roi = src(rect);
    imshow("roi", roi);

	// 克隆ROI到image图像中。
    Mat image = roi.clone();
	// 修改ROI区域的颜色等同于修改原图，因为Mat对象指向同一个。
	// 只有clone出来的Mat对象才会真正独立。
    roi.setTo(Scalar(255, 0, 0));
    imshow("result1", src);

	// 修改clone出来的图像，原图不受影响。
    image.setTo(Scalar(0, 0, 255));
    imshow("result2", src);
    imshow("copy roi", image);

    waitKey(0);

	// 将绿幕换成蓝色
	// 读取图像并显示
    Mat src2 = imread("../greenback.png");
    if (src2.empty()) {
        std::cout << "could not load image..." << std::endl;
        return -1;
    }
    imshow("src2", src2);
    
	Mat hsv, mask;
	// 将原图转换为HSV
    cvtColor(src2, hsv, COLOR_BGR2HSV);
	// 提取绿色区域并生成掩码
    inRange(hsv, Scalar(35, 43, 46), Scalar(99, 255, 255), mask);
    imshow("mask", mask);	// 原图绿色部分为白色(全是1)，人物部分为黑色 (全是0)

    Mat person;
	// 将掩码取反
    bitwise_not(mask, mask);	// 原图绿色部分为黑色，人物部分为白色
	// 将原图使用与运算，将掩码为白色部分的区域生成到person对象。也就是将人物提取出来
    bitwise_and(src2, src2, person, mask);
    imshow("person", person);

	// 生成一副纯蓝色图像
    Mat result = Mat::zeros(src2.size(), src2.type());
    result.setTo(Scalar(255, 0, 0));

    Mat dst;
    bitwise_not(mask, mask);	// 将掩码取反，人物为黑色，原图绿色部分为白色
    imshow("mask2", mask);

	// 将蓝色图片和人物图片按掩码做或运算，也就是除人物范围之外的区域为蓝色，人物区域为黑色
    bitwise_or(result, result, dst, mask);
    imshow("dst1", dst);
    add(dst, person, dst);	// 将人物和蓝色图像合成
    imshow("dst", dst);

	waitKey(0);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
