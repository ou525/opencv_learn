//--------------------------------------【程序说明】-------------------------------------------
//		程序说明：《OpenCV3编程入门》OpenCV2版书本配套示例程序25
//		程序描述：初级图像混合
//		开发测试所用IDE版本：Visual Studio 2010
//		开发测试所用OpenCV版本：	3.0 beta
//		2014年11月 Created by @浅墨_毛星云
//		2014年12月 Revised by @浅墨_毛星云
//------------------------------------------------------------------------------------------------


//---------------------------------【头文件、命名空间包含部分】-------------------------------
//		描述：包含程序所使用的头文件和命名空间
//------------------------------------------------------------------------------------------------                                                                                 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//-----------------------------------【全局函数声明部分】--------------------------------------
//	描述：全局函数声明
//-----------------------------------------------------------------------------------------------
bool  ROI_AddImage();
bool  LinearBlending();
bool  ROI_LinearBlending();
void   ShowHelpText();

//-----------------------------------【main( )函数】--------------------------------------------
//	描述：控制台应用程序的入口函数，我们的程序从这里开始
//-----------------------------------------------------------------------------------------------
int main(   )
{
	// system("color 6F");

	if(ROI_AddImage( )&& LinearBlending( )&&ROI_LinearBlending( ))
	{
		cout<<endl<<"\neeeeeeeeeeeeeeeeeeeeeeee";
	}

	waitKey(0);
	return 0;
}

bool  ROI_AddImage()
{

	// 【1】读入图像
	Mat srcImage1= imread("./data/dota_pa.jpg");
	Mat logoImage= imread("./data/dota_logo.jpg");
	if( !srcImage1.data ) { printf("11111111111 \n"); return false; }
	if( !logoImage.data ) { printf("22222222222 \n"); return false; }

	// 【2】定义一个Mat类型并给其设定ROI区域
	Mat imageROI= srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));

	// 【3】加载掩模（必须是灰度图）
	Mat mask= imread("./data/dota_logo.jpg",0);

	//【4】将掩膜拷贝到ROI
	logoImage.copyTo(imageROI,mask);

	// 【5】显示结果
	//namedWindow("3333333333333333333333333");
	imshow("4444444444444444444444",srcImage1);

	return true;
}

bool  LinearBlending()
{
	//【0】定义一些局部变量
	double alphaValue = 0.7; 
	double betaValue;
	Mat srcImage2, srcImage3, dstImage;

	// 【1】读取图像 ( 两幅图片需为同样的类型和尺寸 )
	srcImage2 = imread("./data/mogu.jpg");
	srcImage3 = imread("./data/rain.jpg");

	if( !srcImage2.data ) { printf("5555555555555555555555 \n"); return false; }
	if( !srcImage3.data ) { printf("6666666666666666666666 \n"); return false; }

	// 【2】进行图像混合加权操作
	betaValue = ( 1.0 - alphaValue );
	addWeighted( srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);

	// 【3】显示原图窗口
	imshow( "7777777777777777777777", srcImage2 );
	imshow( "8888888888888888888888", dstImage );

	return true;

}

//---------------------------------【ROI_LinearBlending（）】-------------------------------------
// 函数名：ROI_LinearBlending（）
// 描述：线性混合实现函数,指定区域线性图像混合.利用cv::addWeighted（）函数结合定义
//			  感兴趣区域ROI，实现自定义区域的线性混合
//--------------------------------------------------------------------------------------------
bool  ROI_LinearBlending()
{

	//【1】读取图像
	Mat srcImage4= imread("./data/dota_pa.jpg",1);
	Mat logoImage= imread("./data/dota_logo.jpg");

	if( !srcImage4.data ) { printf("999999999999999999999999999 \n"); return false; }
	if( !logoImage.data ) { printf("qqqqqqqqqqqqqqqqqqqqqqqqqqq \n"); return false; }

	//【2】定义一个Mat类型并给其设定ROI区域
	Mat imageROI;
	//方法一
	imageROI= srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
	//方法二
	//imageROI= srcImage4(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

	//【3】将logo加到原图上
	addWeighted(imageROI,0.5,logoImage,0.3,0.,imageROI);

	//【4】显示结果
	imshow("wwwwwwwwwwwwwwwwwwwwwwwwwwww",srcImage4);

	return true;
}

