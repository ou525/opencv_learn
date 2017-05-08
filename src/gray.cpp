// #include <iostream>  
// #include "cv.h"  
// #include "highgui.h"  
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
  
using namespace std;   
using namespace cv;  


int gray1; //¶Ô±È¶ÈÖµ
int gray2;  //ÁÁ¶ÈÖµ
Mat src, dst;

/***    设置图像灰度值的子函数         ****/  
void setSaltNoise(int, void *) 
{  
    // srand((unsigned)time(NULL));    //要产生随机数，需要一个随机数种子，这里是以时间作为  
                                    //随机数产生的种子  
    
    for (int i = 0; i < dst.rows; i++)
    {
		for (int j = 0; j < dst.cols; j++)  
	    {  
	        int x, y;                 
	        // y = rand() % src.rows;    //将随机数y的取值范围设定在图像的行范围内  
	        // x = rand() % src.cols;    //将随机数x的取值范围设定在图像的列范围内  
	        if (dst.channels() == 1)  //如果图像是单通道则直接将其（y,x）点像素的灰度值  
	        {                           //设定为255，即白色。这里注意给定点像素的读取方法  
	            dst.at<uchar>(i, j) = 100;  
	        }  
	        if (dst.channels() == 3)  //如果是三通道的图像，则注意其特定像素值的不同通道  
	        {                               //的值的设定  
	            dst.at<Vec3b>(i, j)[0] = gray1;   //设定B通道的值为白色  
	            dst.at<Vec3b>(i, j)[1] = gray1;   //设定G通道的值为白色  
	            dst.at<Vec3b>(i, j)[2] = gray1;   //设定R通道的值为白色  
	        }  
	    } 
    }
    imshow("dst", dst);   
 
}  
  
int main(int argc, char* argv[])  
{  
    src = imread("./data/12.jpg");//读取图像 
    cv::resize(src, dst, cv::Size(src.rows+100, src.cols+100), (0, 0), (0, 0), cv::INTER_LINEAR); 
    namedWindow("dst");     //创建图像显示窗口

    createTrackbar("constrast", "dst",&gray1, 255,setSaltNoise );

    setSaltNoise(gray1, 0);     //设置图像灰度值  
    // imshow("src", src);     //在窗口中显示图像  
    waitKey(0);         //等待按键响应  
  
    system("pause");      
    return 0;  
}
