#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    VideoCapture capture;
    // 读取视频文件
    capture.open("../vtest.avi");
    if (!capture.isOpened()) {
        std::cout << "could not read this video file..." << std::endl;
        return -1;
    }

    // 获取视频文件的分辨率
    Size s = Size((int)capture.get(CAP_PROP_FRAME_WIDTH), (int)capture.get(CAP_PROP_FRAME_HEIGHT));
    // 获取视频的帧率
    int fps = capture.get(CAP_PROP_FPS);
    // 获取视频文件的总帧数
    int count = capture.get(CAP_PROP_FRAME_COUNT);

    printf("width = %d, height = %d, count = %d, fps = %d.\n", s.width, s.height, count, fps);

    // 创建writer对象，设置要保存视频的格式
    /*
     * ('P', 'I', 'M', '1') = MPEG-1 codec
     * ('M', 'J', 'P', 'G') = motion-jpeg codec
     * ('M', 'P', '4', '2') = MPEG-4.2 codec
     * ('D', 'I', 'V', '3') = MPEG-4.3 codec
     * ('D', 'I', 'V', 'X') = MPEG-4 codec
     * ('U', '2', '6', '3') = H263 codec
     * ('I', '2', '6', '3') = H263I codec
     * ('F', 'L', 'V', '1') = FLV1 codec
     * */
    VideoWriter writer("./test.mp4", VideoWriter::fourcc('D', 'I', 'V', 'X'), fps, s, true);

    Mat frame;
    namedWindow("camera-demo", WINDOW_AUTOSIZE);

    // 从capture中读取每一帧数据
    while (capture.read(frame)) {
        // 显示到窗口
        imshow("camera-demo", frame);
        // 保存在writer对象中
        writer.write(frame);

        // 等待用户按下按钮
        char c = waitKey(50);
        if (c == 'q') {
            break;
        }
    }

    // 销毁创建的对象
    capture.release();
    writer.release();
    waitKey(0);

    return 0;
}
