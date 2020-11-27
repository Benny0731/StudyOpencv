//
// Created by linux on 11/26/20.
//

#ifndef INC_05_PIXELVISIT_PIXELVISIT_H
#define INC_05_PIXELVISIT_PIXELVISIT_H

#include <opencv2/opencv.hpp>

using namespace cv;

class Pixelvisit {
public:
    static void pixel_visit_at(Mat &image);
    static void pixel_visit_pointer(Mat &image);
};


#endif //INC_05_PIXELVISIT_PIXELVISIT_H
