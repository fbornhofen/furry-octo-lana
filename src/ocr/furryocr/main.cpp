#include <iostream>
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " IMAGE" << std::endl;
    }
    cv::Mat img = cv::imread(argv[1], 0);
    cv::namedWindow("image");
    char c = 0;
    while (c != 27) {
        cv::imshow("image", img);
        c = cv::waitKey(0);
    }
    return 0;
}

