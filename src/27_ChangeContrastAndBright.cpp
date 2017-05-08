

//--------------------------------------¡¾³ÌÐòËµÃ÷¡¿-------------------------------------------
//		³ÌÐòËµÃ÷£º¡¶OpenCV3±à³ÌÈëÃÅ¡·OpenCV3°æÊé±¾ÅäÌ×Ê¾Àý³ÌÐò27
//		³ÌÐòÃèÊö£ºÍ¼Ïñ¶Ô±È¶È¡¢ÁÁ¶ÈÖµµ÷Õû
//		¿ª·¢²âÊÔËùÓÃIDE°æ±¾£ºVisual Studio 2010
//		¿ª·¢²âÊÔËùÓÃOpenCV°æ±¾£º	3.0 beta
//		2014Äê11ÔÂ Created by @Ç³Ä«_Ã«ÐÇÔÆ
//		2014Äê12ÔÂ Revised by @Ç³Ä«_Ã«ÐÇÔÆ
//------------------------------------------------------------------------------------------------



//-----------------------------------¡¾Í·ÎÄ¼þ°üº¬²¿·Ö¡¿---------------------------------------
//	ÃèÊö£º°üº¬³ÌÐòËùÒÀÀµµÄÍ·ÎÄ¼þ
//---------------------------------------------------------------------------------------------- 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

//-----------------------------------¡¾ÃüÃû¿Õ¼äÉùÃ÷²¿·Ö¡¿---------------------------------------
//	ÃèÊö£º°üº¬³ÌÐòËùÊ¹ÓÃµÄÃüÃû¿Õ¼ä
//-----------------------------------------------------------------------------------------------   
using namespace std;
using namespace cv;


//-----------------------------------¡¾È«¾Öº¯ÊýÉùÃ÷²¿·Ö¡¿--------------------------------------
//	ÃèÊö£ºÈ«¾Öº¯ÊýÉùÃ÷
//-----------------------------------------------------------------------------------------------
static void ContrastAndBright(int, void *);
void   ShowHelpText();

//-----------------------------------¡¾È«¾Ö±äÁ¿ÉùÃ÷²¿·Ö¡¿--------------------------------------
//	ÃèÊö£ºÈ«¾Ö±äÁ¿ÉùÃ÷
//-----------------------------------------------------------------------------------------------
int g_nContrastValue; //¶Ô±È¶ÈÖµ
int g_nBrightValue;  //ÁÁ¶ÈÖµ
Mat g_srcImage,g_dstImage;
//-----------------------------------¡¾main( )º¯Êý¡¿--------------------------------------------
//	ÃèÊö£º¿ØÖÆÌ¨Ó¦ÓÃ³ÌÐòµÄÈë¿Úº¯Êý£¬ÎÒÃÇµÄ³ÌÐò´ÓÕâÀï¿ªÊ¼
//-----------------------------------------------------------------------------------------------


Mat  ChangeImg(Mat &img,const uchar* table)
{
	CV_Assert(img.depth ()!=sizeof(uchar));  //声明只对深度8bit的图像操作
	int channels=img.channels ();            //获取图像channel
	int nrows=img.rows;                     //矩阵的行数
	int ncols=img.cols*channels;             //矩阵的总列数=列数*channel分量数
	if (img.isContinuous ())               //判断矩阵是否连续，若连续，我们相当于只需要遍历一个一维数组
	{
		ncols*=nrows;
		nrows=1;                 //一维数组
	}
	//遍历像素点灰度值
	for (int i=0;i<nrows;i++)
	{
		uchar *p=img.ptr<uchar>(i);    //获取行地址
		for (int j=0;j<ncols;j++)
		{
			p[j]=table[p[j]];           //修改灰度值
		}
	}
	return img;
}

int main(   )
{
	g_srcImage = imread( "./data/39.jpg");
	if( !g_srcImage.data ) { printf("11111111111111 \n"); return false; }
	g_dstImage = Mat::zeros( g_srcImage.size(), g_srcImage.type() );

	// Mat g_srcImage;
	// uchar table[256];
	// for (int i=0;i<256;i++)
	// {
	// 	table[i]=100;   //这里利用了C++的语言特性i/100只会留下整数部分
	// }  

	// g_srcImage = ChangeImg(g_srcImage, table);

	cvtColor(g_srcImage,g_srcImage,CV_BGR2GRAY);

	//Éè¶¨¶Ô±È¶ÈºÍÁÁ¶ÈµÄ³õÖµ
	g_nContrastValue=80;
	g_nBrightValue=80;

	//´´½¨´°¿Ú
	namedWindow("source", 1);

	//´´½¨¹ì¼£Ìõ
	createTrackbar("constrast", "source",&g_nContrastValue, 300,ContrastAndBright );
	createTrackbar("bright", "source",&g_nBrightValue, 200,ContrastAndBright );

	//µ÷ÓÃ»Øµ÷º¯Êý
	ContrastAndBright(g_nContrastValue,0);
	ContrastAndBright(g_nBrightValue,0);

	//Êä³öÒ»Ð©°ïÖúÐÅÏ¢
	cout<<endl<<"\t77777777777777777777777\n\n"
		<<"\t888888888888888888888\n";

	//°´ÏÂ¡°q¡±¼üÊ±£¬³ÌÐòÍË³ö
	while(char(waitKey(1)) != 'q') {}
	return 0;
}

//-----------------------------¡¾ContrastAndBright( )º¯Êý¡¿------------------------------------
//	ÃèÊö£º¸Ä±äÍ¼Ïñ¶Ô±È¶ÈºÍÁÁ¶ÈÖµµÄ»Øµ÷º¯Êý
//-----------------------------------------------------------------------------------------------
static void ContrastAndBright(int, void *)
{

	// ´´½¨´°¿Ú
	namedWindow("output", 1);

	// Èý¸öforÑ­»·£¬Ö´ÐÐÔËËã g_dstImage(i,j) = a*g_srcImage(i,j) + b
	for( int y = 0; y < g_srcImage.rows; y++ )
	{
		for( int x = 0; x < g_srcImage.cols; x++ )
		{
			for( int c = 0; c < 3; c++ )
			{
				g_dstImage.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( (g_nContrastValue*0.01)*( g_srcImage.at<Vec3b>(y,x)[c] ) + g_nBrightValue );
			}
		}
	}

	// ÏÔÊ¾Í¼Ïñ
	imshow("source", g_srcImage);
	imshow("output", g_dstImage);
}


