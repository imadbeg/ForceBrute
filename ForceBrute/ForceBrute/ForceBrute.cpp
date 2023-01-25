#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <time.h>;
#include <math.h>
using namespace cv;
using namespace std;

int main()
{
	srand(time(NULL));


	Mat image = imread("D:\\imad\\TDopencv\\rendreexam\\ForceBrute\\picture.jpg");
	Mat image2 = imread("D:\\imad\\TDopencv\\rendreexam\\ForceBrute\\picture.jpg");

	const int NbpVo = 1000;


	Point points[NbpVo];

	for (int i = 0; i < NbpVo; i++)
	{
		points[i].x = rand() % image.cols;
		points[i].y = rand() % image.rows;
	}


	for (int i = 0; i < image.cols; i++)
	{
		for (int j = 0; j < image.rows; j++)
		{
			int min = 1000000;
			int dis = 0;
			int trouve = 0;

			for (int k = 0; k < NbpVo; k++)
			{
				dis = sqrt(((points[k].x - i) * (points[k].x - i)) + ((points[k].y - j) * (points[k].y - j)));

				if (dis < min)
				{
					min = dis;
					trouve = k;
				}
			}



			image.at<Vec3b>(j, i)[0] = image.at<Vec3b>(points[trouve].y, points[trouve].x)[0];
			image.at<Vec3b>(j, i)[1] = image.at<Vec3b>(points[trouve].y, points[trouve].x)[1];
			image.at<Vec3b>(j, i)[2] = image.at<Vec3b>(points[trouve].y, points[trouve].x)[2];
		}
	}

	for (int i = 0; i < NbpVo; i++)
	{
		image.at<Vec3b>(points[i])[0] = 0;
		image.at<Vec3b>(points[i])[1] = 0;
		image.at<Vec3b>(points[i])[2] = 0;
	}


	imshow(" Window1", image);
	imshow(" Window2", image2);
	waitKey(0);
	return 0;
}