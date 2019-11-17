#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void GaussBlur(Mat &image)
{
	namedWindow("in", WINDOW_FREERATIO);
	namedWindow("out", WINDOW_FREERATIO);

	imshow("in", image);

	Mat out;
	GaussianBlur(image, out, Size(11,11), 3, 3);
	GaussianBlur(out, out, Size(11, 11), 3, 3);
	imshow("out", out);
	waitKey(0);
}

int main()
{
	Mat img1 = imread("E://GoogleDownload//img//blue.jpg");
	//GaussBlur(img);
	Mat img2;
	namedWindow("in", WINDOW_FREERATIO);
	namedWindow("out", WINDOW_FREERATIO);
	imshow("in", img1);

	pyrDown(img1, img2);
	imshow("out", img2);
	waitKey(0);
	return 0;
}
