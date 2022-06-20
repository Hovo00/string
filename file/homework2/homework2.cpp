#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    cv::Mat input = cv::imread("Images.jpg");

    cv::Mat mask;
    // create a perfect mask: Easy if you know the 2 colors present in your image:
    cv::inRange(input, cv::Scalar(100, 0, 0), cv::Scalar(255, 255, 255), mask);
    cv::imshow("mask", mask);

    std::vector<std::vector<cv::Point> > contours; // contour points
    std::vector<cv::Vec4i> hierarchy; // this will give you the information whether it is an internal or external conotour.

    // contour extraction: This will alter the input image, so if you need it later use mask.clone() instead
    findContours(mask, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE, cv::Point(0, 0)); // use different CV_CHAIN_APPROX_ if you dont need ALL the points but only the ones that dont lie on a common line

    // output images:
    cv::Mat contoursExternal = input.clone();
    cv::Mat contoursInternal = input.clone();
    cv::Mat contoursAll = cv::Mat::zeros(input.size(), CV_8UC1);

    // draw contours
    for (unsigned int i = 0; i < contours.size(); ++i)
    {
        cv::drawContours(contoursAll, contours, i, cv::Scalar::all(255), 1);
        if (hierarchy[i][3] != -1) cv::drawContours(contoursInternal, contours, i, cv::Scalar::all(255), 1);
        else cv::drawContours(contoursExternal, contours, i, cv::Scalar::all(255), 1);
    }

    cv::imshow("internal", contoursInternal);
    cv::imshow("external", contoursExternal);
    cv::imshow("all", contoursAll);


    cv::imshow("input", input);
    cv::waitKey(0);
    return 0;
}
