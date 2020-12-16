#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	// 创建一副512*512 3通道的图像
    Mat src = Mat::zeros(Size(512, 512), CV_8UC3);
	
	// 创建一个矩形，左上角的点为100,100；右下角的点为200,200；因此创建了一个尺寸为100*100的矩形
    Rect rect(100, 100, 200, 200);
	/*
     * 在src图像中绘制矩形
	 * 参数1: 要绘制的Mat对象
	 * 参数2: 矩形左上角的点和右下角的点
	 * 参数3: 线条颜色
	 * 参数4: 线条宽度，-1为填充矩形
	 * 参数5: 绘制算法
	 * 参数6: 位移
	 */
    rectangle(src, rect, Scalar(255, 0, 0), 2, LINE_8, 0);
	/*
     * 在src图像中绘制圆形
	 * 参数1: 要绘制的Mat对象
	 * 参数2: 圆心坐标
	 * 参数3: 半径
	 * 参数4: 线条颜色
	 * 参数5: 线条宽度，-1为填充
	 * 参数6: 绘制算法
	 * 参数7: 位移
	 */
    circle(src, Point(256, 256), 50, Scalar(0, 0, 255), 2, LINE_8, 0);
	/*
     * 在src图像中绘制椭圆形
	 * 参数1: 要绘制的Mat对象
	 * 参数2: 圆心坐标
	 * 参数3: 长轴和短轴
	 * 参数4: 偏转的角度
	 * 参数5: 圆弧起始角的角度
	 * 参数6: 圆弧终结角的角度
 	 * 参数7: 线条颜色
	 * 参数8: 线条宽度
	 * 参数9: 绘制算法
	 * 参数10: 位移
	 */
    ellipse(src, Point(256, 256), Size(150, 50), 200, 90, 360, Scalar(0, 255, 0), 2, LINE_8, 0);

    imshow("src", src);

    waitKey(0);

    RNG rng(0xffffff);	// 随机数种子
    src.setTo(Scalar(0, 0, 0));	// 清空Mat对象

    for (int i = 0; i < 100000; i++) {
        // src.setTo(Scalar(0,0,0));
		// 生成一个0~512直接的随机数
        int x1 = rng.uniform(0, 512);
        int y1 = rng.uniform(0, 512);
        int x2 = rng.uniform(0, 512);
        int y2 = rng.uniform(0, 512);

		// 生成一个0~256直接的随机数
        int b = rng.uniform(0, 256);
        int g = rng.uniform(0, 256);
        int r = rng.uniform(0, 256);

	   /*
     	* 在src图像中绘制线段
	 	* 参数1: 要绘制的Mat对象
	 	* 参数2: 线段起点
	 	* 参数3: 线段终点
	 	* 参数4: 线条颜色
	 	* 参数5: 线条宽度，-1为填充
	 	* 参数6: 绘制算法
	 	* 参数7: 位移
	 	*/
        line(src, Point(x1, y1), Point(x2,y2), Scalar(b, g, r), 1, LINE_AA, 0);

        rect.x = x1;
        rect.y = y1;
        rect.width = x2-x1;
        rect.height = y2-y1;
        // rectangle(src, rect, Scalar(b, g, r), 1, LINE_AA, 0);
        imshow("src", src);
        char c = waitKey(20);
        if (c == 'q') {
            break;
        }
    }

    waitKey(0);

    return 0;
}
