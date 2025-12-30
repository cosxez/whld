#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

struct Image
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};

int main()
{
	cout<<"Enter filename: ";
	string filename;
	cin>>filename;
	unsigned int w;
	unsigned int h;
	cout<<"Enter width: ";
	cin>>w;
	cout<<"Enter height: ";
	cin>>h;
	Mat img=imread(filename);
	resize(img,img,Size(w,h));
	ofstream file("image.whld",ios::binary);
	
	Image iamge;
	
	file.write(reinterpret_cast<const char*>(&w),sizeof(w));
	file.write(reinterpret_cast<const char*>(&h),sizeof(h));
	
	for (int y=0;y<img.rows;y++)
	{
		for (int x=0;x<img.cols;x++)
		{
			Vec3b pixel=img.at<Vec3b>(y,x);
			iamge.red=pixel[2];
			iamge.green=pixel[1];
			iamge.blue=pixel[0];
			
			file.write(reinterpret_cast<const char*>(&iamge),sizeof(iamge));				
		}
	}
	
	file.close();
}
