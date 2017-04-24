//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������84
//		����������ģ��ƥ��ʾ��
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------



//---------------------------------��ͷ�ļ��������ռ�������֡�----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;


//-----------------------------------���궨�岿�֡�-------------------------------------------- 
//  ����������һЩ������ 
//------------------------------------------------------------------------------------------------ 
#define WINDOW_NAME1 "111111111111"        //Ϊ���ڱ��ⶨ��ĺ� 
#define WINDOW_NAME2 "222222222222"        //Ϊ���ڱ��ⶨ��ĺ� 

//-----------------------------------��ȫ�ֱ����������֡�------------------------------------
//          ������ȫ�ֱ���������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage; Mat g_templateImage; Mat g_resultImage;
int g_nMatchMethod;
int g_nMaxTrackbarNum = 5;

//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//          ������ȫ�ֺ���������
//-----------------------------------------------------------------------------------------------
void on_Matching( int, void* );

//-----------------------------------��main( )������--------------------------------------------
//          ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-----------------------------------------------------------------------------------------------
int main(  )
{
	//��1������ԭͼ���ģ���
	g_srcImage = imread( "./data/37.jpg", 1 );
	g_templateImage = imread( "./data/38.jpg", 1 );

	//��2����������
	namedWindow( WINDOW_NAME1, WINDOW_AUTOSIZE );
	namedWindow( WINDOW_NAME2, WINDOW_AUTOSIZE );

	//��3������������������һ�γ�ʼ��
	createTrackbar( "3333", WINDOW_NAME1, &g_nMatchMethod, g_nMaxTrackbarNum, on_Matching );
	on_Matching( 0, 0 );

	waitKey(0);
	return 0;

}

//-----------------------------------��on_Matching( )������--------------------------------
//          �������ص�����
//-------------------------------------------------------------------------------------------
void on_Matching( int, void* )
{
	//��1�����ֲ�������ʼ��
	Mat srcImage;
	g_srcImage.copyTo( srcImage );

	//��2����ʼ�����ڽ������ľ���
	int resultImage_rows = g_srcImage.rows - g_templateImage.rows + 1;
	int resultImage_cols =  g_srcImage.cols - g_templateImage.cols + 1;
	g_resultImage.create(resultImage_rows,resultImage_cols, CV_32FC1);

	//��3������ƥ��ͱ�׼��
	matchTemplate( g_srcImage, g_templateImage, g_resultImage, g_nMatchMethod );
	normalize( g_resultImage, g_resultImage, 0, 1, NORM_MINMAX, -1, Mat() );

	//��4��ͨ������ minMaxLoc ��λ��ƥ���λ��
	double minValue; double maxValue; Point minLocation; Point maxLocation;
	Point matchLocation;
	minMaxLoc( g_resultImage, &minValue, &maxValue, &minLocation, &maxLocation, Mat() );

	//��5�����ڷ��� SQDIFF �� SQDIFF_NORMED, ԽС����ֵ���Ÿ��ߵ�ƥ����. ������ķ���, ��ֵԽ��ƥ��Ч��Խ��
	//�˾�����OpenCV2��Ϊ��
	//if( g_nMatchMethod  == CV_TM_SQDIFF || g_nMatchMethod == CV_TM_SQDIFF_NORMED )
	//�˾�����OpenCV3��Ϊ��
	if( g_nMatchMethod  == TM_SQDIFF || g_nMatchMethod == TM_SQDIFF_NORMED )
	{ matchLocation = minLocation; }
	else
	{ matchLocation = maxLocation; }

	//��6�����Ƴ����Σ�����ʾ���ս��
	rectangle( srcImage, matchLocation, Point( matchLocation.x + g_templateImage.cols , matchLocation.y + g_templateImage.rows ), Scalar(0,0,255), 2, 8, 0 );
	rectangle( g_resultImage, matchLocation, Point( matchLocation.x + g_templateImage.cols , matchLocation.y + g_templateImage.rows ), Scalar(0,0,255), 2, 8, 0 );

	imshow( WINDOW_NAME1, srcImage );
	imshow( WINDOW_NAME2, g_resultImage );

}


