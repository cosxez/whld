#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

int main()
{
	cout<<"Enter filename: ";
	string filename;
	getline(cin,filename);
	int w;
	int h;
	cout<<"Enter width: ";
	getline(cin,w);
	cout<<"Enter height: ";
	getline(cin,h);
	Mat img=imread(filename);
	resize(img,img,Size(w,h));
	ofstream file("image.whld");
	
	file<<w<<"W "<<h<<"H\n";
	for (int y=0;y<img.rows;y++)
	{
		for (int x=0;x<img.cols;x++)
		{
			Vec3b pixel=img.at<Vec3b>(y,x);
			uchar red=pixel[2];
			uchar green=pixel[1];
			uchar blue=pixel[0];
			
			file<<(int)red<<' '<<(int)green<<' '<<(int)blue<<endl;
		}
	}
}
