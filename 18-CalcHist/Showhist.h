//
// Created by linux on 12/18/20.
//

#ifndef CALCHIST_SHOWHIST_H
#define CALCHIST_SHOWHIST_H

#include <opencv2/opencv.hpp>

class Showhist {
public:
   static void showHist(cv::Mat &img, cv::Mat &dst);

   static void grayHist(cv::Mat &img, cv::Mat &dst);
};


#endif //CALCHIST_SHOWHIST_H
