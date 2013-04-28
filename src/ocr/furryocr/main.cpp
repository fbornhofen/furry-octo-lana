#include <iostream>
#include <vector>
#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " IMAGE" << endl;
    }
    Mat img = imread(argv[1], 0);
    namedWindow("image");
    namedWindow("processed");
    Mat blurred;
    GaussianBlur(img, blurred, Size(5, 5), 0);
    Mat thresh;
    adaptiveThreshold(blurred, thresh, 255, 1, 1, 11, 2);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(thresh, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    Mat processed = Mat::zeros(thresh.size(), thresh.type());
    for (int i = 0; i< contours.size(); i++) {
        Scalar color = Scalar(255, 255, 255);
        cout << "Contour area: " << contourArea(contours[i]) << endl;
        drawContours(processed, contours, i, color, 2, 8, hierarchy, 0, Point());
    }

    char c = 0;
    while (c != 27) {
        imshow("image", img);
        imshow("processed", processed);
        c = waitKey(0);
    }
    return 0;
}

