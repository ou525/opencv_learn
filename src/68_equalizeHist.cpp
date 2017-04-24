//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV3版书本配套示例程序68
//		程序描述：直方图均衡化
//		开发测试所用操作系统： Windows 7 64bit
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年12月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------


//---------------------------------【头文件、命名空间包含部分】---------------------------
//          描述：包含程序所使用的头文件和命名空间
//-----------------------------------------------------------------------------------------------
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;


//--------------------------------------【main( )函数】-----------------------------------------
//          描述：控制台应用程序的入口函数，我们的程序从这里开始执行
//-----------------------------------------------------------------------------------------------
int main( )
{
	// 【1】加载源图像
	Mat srcImage, dstImage;
	srcImage = imread( "./data/25.jpg", 1 );
	if(!srcImage.data ) { printf("read error \n"); return false; } 

	// 【2】转为灰度图并显示出来
	cvtColor( srcImage, srcImage, COLOR_BGR2GRAY );
	imshow( "source", srcImage );

	// 【3】进行直方图均衡化
	equalizeHist( srcImage, dstImage );

	// 【4】显示结果
	imshow( "output", dstImage );

	// 等待用户按键退出程序
	waitKey(0);
	return 0;

}