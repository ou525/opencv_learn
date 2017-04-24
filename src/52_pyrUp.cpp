//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序52
//		程序描述：pyrUp函数用法示例
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年12月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------


//---------------------------------【头文件、命名空间包含部分】----------------------------
//		描述：包含程序所使用的头文件和命名空间
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;



//-----------------------------------【main( )函数】------------------------------------------
//		描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------------------------------------------
int main( )
{
	//载入原始图   
	Mat srcImage = imread("./data/14.jpg");  //工程目录下应该有一张名为1.jpg的素材图
	Mat tmpImage1, tmpImage2, dst1Image, dst2Image;//临时变量和目标图的定义
	tmpImage1=srcImage;//将原始图赋给临时变量
	tmpImage2=srcImage;

	//显示原始图  
	imshow("source", srcImage);  
	//进行向上取样操作
	pyrUp( tmpImage1, dst1Image, Size( tmpImage1.cols*2, tmpImage1.rows*2 ) );
	pyrDown( tmpImage2, dst2Image, Size( tmpImage2.cols/2, tmpImage2.rows/2 ) );
	//显示效果图  
	imshow("output1", dst1Image);
	imshow("output2", dst2Image);  

	waitKey(0);  

	return 0;  
}
