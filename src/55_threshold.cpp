
//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������55
//		����������OpenCV������ֵ����
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------



//---------------------------------��ͷ�ļ��������ռ�������֡�----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

//-----------------------------------���궨�岿�֡�-------------------------------------------- 
//		����������һЩ������ 
//------------------------------------------------------------------------------------------------ 
#define WINDOW_NAME "out"        //Ϊ���ڱ��ⶨ��ĺ� 


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ���������
//-----------------------------------------------------------------------------------------------
int g_nThresholdValue = 100;
int g_nThresholdType = 3;
Mat g_srcImage, g_grayImage, g_dstImage;

//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ���������
//-----------------------------------------------------------------------------------------------
void on_Threshold( int, void* );//�ص�����


//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-----------------------------------------------------------------------------------------------
int main( )
{

	//��1������ԴͼƬ
	g_srcImage = imread("./data/16.jpg");
	if(!g_srcImage.data ) { printf("read error !!! \n"); return false; }  
	imshow("source",g_srcImage);

	//��2������һ��ԭͼ�ĻҶ�ͼ
	cvtColor( g_srcImage, g_grayImage, COLOR_RGB2GRAY );

	//��3���������ڲ���ʾԭʼͼ
	namedWindow( WINDOW_NAME, WINDOW_AUTOSIZE );

	//��4��������������������ֵ
	createTrackbar( "1",
		WINDOW_NAME, &g_nThresholdType,
		4, on_Threshold );

	createTrackbar( "2",
		WINDOW_NAME, &g_nThresholdValue,
		255, on_Threshold );

	//��5����ʼ���Զ������ֵ�ص�����
	on_Threshold( 0, 0 );

	// ��6����ѯ�ȴ��û����������ESC���������˳�����
	while(1)
	{
		int key;
		key = waitKey( 20 );
		if( (char)key == 27 ){ break; }
	}

}

//-----------------------------------��on_Threshold( )������------------------------------------
//		�������Զ������ֵ�ص�����
//-----------------------------------------------------------------------------------------------
void on_Threshold( int, void* )
{
	//������ֵ����
	threshold(g_grayImage,g_dstImage,g_nThresholdValue,255,g_nThresholdType);

	//����Ч��ͼ
	imshow( WINDOW_NAME, g_dstImage );
}

