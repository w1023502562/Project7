#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	Mat src = cv::imread("D:\\7.png", 1);
	Mat dst;
	Mat canny;
	Canny(src, canny, 50, 200, 3);
	cvtColor(canny, dst, COLOR_GRAY2BGR);
	std::vector<cv::Vec4i> lines;
	cv::HoughLinesP(canny, lines, 1, CV_PI / 180, 37, 10, 10);
	std::vector<cv::Vec4i>::iterator it = lines.begin();
	for (int i = 0; i < lines.size(); i++) {
		Point pt1, pt2;
		pt1.x = lines[i][0];
		pt1.y = lines[i][1];
		pt2.x = lines[i][2];
		pt2.y = lines[i][3];
		line(src, pt1, pt2, cv::Scalar(0, 0, 255), 2, CV_AA);

	}
	imshow("src", src);
	imshow("canny", canny);
	waitKey(0);

}