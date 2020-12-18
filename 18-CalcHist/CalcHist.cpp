#include <iostream>
#include <opencv2/opencv.hpp>
#include "Showhist.h"

using namespace cv;

int main() {
    Mat src = imread("../lena.jpg");
    Mat histImage;

    if (src.empty()) {
        std::cout<<""<<std::endl;
        return -1;
    }

    Showhist::showHist(src, histImage);
    imshow("src", src);
    namedWindow("histImage", 0);
    imshow("histImage", histImage);

    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    Showhist::grayHist(gray, histImage);
    imshow("gray", histImage);
    waitKey(0);

    return 0;
}
