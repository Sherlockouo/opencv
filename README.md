## opencv
---
opencv

![Opencv](https://pic4.zhimg.com/v2-aebf20c53413473873c2717bd1bece1b_1200x500.jpg "opencv")

1. [准备工作_环境配置]() <br>
2. [简单入门OPENCV](https://github.com/Sherlockouo/opencv/tree/master/opencv_demo)
'''
	#include "pch.h"
	#include <iostream>
	#include <opencv2/opencv.hpp>
	using namespace std;
	using namespace cv;

	int g_slide_position = 0;
	int g_run = 1, g_donset = 0;//start out in single step mode
	VideoCapture g_cap;

	void onTrackbarSlide(int pos, void *)
	{
		g_cap.set(CAP_PROP_POS_FRAMES, pos);
		if (!g_donset)
		{
			g_run = 1;
			g_donset = 0;
		}
	}

	int main(int argc, char** argv)
	{
		namedWindow("Demo", WINDOW_AUTOSIZE);
	
		g_cap.open("F://homework//oo.mp4");
		// Mat frame;
			int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
		int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH);
		int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
		cout << "Video has " << frames << " frames dimensions (" << tmpw << "," << tmph << ")." << endl;
		createTrackbar("Position ", "Demo", &g_slide_position, frames, onTrackbarSlide);
		Mat frame;
		for (;;)
		{
			if (g_run != 0)
			{
				g_cap >> frame;
				if (frame.empty())  break;
				int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
				g_donset = 1;
				setTrackbarPos("Position", "Demo", current_pos);
				imshow("Demo", frame);
				g_run -= 1;
			}
			char c = (char)waitKey(10);
			if (c == 's')//single step
			{
				g_run = 1; cout << "Single step , run = " << g_run << endl;
			}

			if (c == 'r') 
			{
				g_run = -1; cout << "Run mode , run=" << g_run << endl;
			}

			if (c == 27)
				break;
		}
	

		return 0;
	}
'''
