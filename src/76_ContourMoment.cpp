
//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������76
//		�������������Һͻ���ͼƬ������
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
#include <iostream>
using namespace cv;
using namespace std;


//-----------------------------------���궨�岿�֡�-------------------------------------------- 
//		����������һЩ������ 
//------------------------------------------------------------------------------------------------ 
#define WINDOW_NAME1 "source"					//Ϊ���ڱ��ⶨ��ĺ� 
#define WINDOW_NAME2 "output"        //Ϊ���ڱ��ⶨ��ĺ� 
#define WINDOW_NAME3 "mid"

//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ���������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage; Mat g_grayImage;
int g_nThresh = 100;
int g_nMaxThresh = 255;
RNG g_rng(12345);
Mat g_cannyMat_output;
vector<vector<Point> > g_vContours;
vector<Vec4i> g_vHierarchy;

//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ���������
//-----------------------------------------------------------------------------------------------
void on_ThreshChange(int, void* );

//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-----------------------------------------------------------------------------------------------
int main( int argc, char** argv )
{
	// ����ԭͼ��, ����3ͨ��ͼ������
	g_srcImage = imread( "./data/28.jpg", 1 );

	// ��ԭͼ��ת���ɻҶ�ͼ�񲢽���ƽ��
	cvtColor( g_srcImage, g_grayImage, COLOR_BGR2GRAY );
	blur( g_grayImage, g_grayImage, Size(3,3) );

	namedWindow( WINDOW_NAME3, WINDOW_AUTOSIZE );
	//imshow( WINDOW_NAME3, g_grayImage );

	// �����´���
	namedWindow( WINDOW_NAME1, WINDOW_AUTOSIZE );
	imshow( WINDOW_NAME1, g_srcImage );

	//���������������г�ʼ��
	createTrackbar( "111", WINDOW_NAME1, &g_nThresh, g_nMaxThresh, on_ThreshChange );
	on_ThreshChange( 0, 0 );

	waitKey(0);
	return(0);
}

//-----------------------------------��on_ThreshChange( )������-------------------------------
//		�������ص�����
//-----------------------------------------------------------------------------------------------
void on_ThreshChange(int, void* )
{
	// ʹ��Canndy����Ե
	Canny( g_grayImage, g_cannyMat_output, g_nThresh, g_nThresh*2, 3 );
	imshow( WINDOW_NAME3, g_cannyMat_output );

	// �ҵ�����
	findContours( g_cannyMat_output, g_vContours, g_vHierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

	// �����
	vector<Moments> mu(g_vContours.size() );
	for(unsigned int i = 0; i < g_vContours.size(); i++ )
	{ mu[i] = moments( g_vContours[i], false ); }

	//  �������ľ�
	vector<Point2f> mc( g_vContours.size() );
	for( unsigned int i = 0; i < g_vContours.size(); i++ )
	{ mc[i] = Point2f( static_cast<float>(mu[i].m10/mu[i].m00), static_cast<float>(mu[i].m01/mu[i].m00 )); }

	// ��������
	Mat drawing = Mat::zeros( g_cannyMat_output.size(), CV_8UC3 );
	for( unsigned int i = 0; i< g_vContours.size(); i++ )
	{
		Scalar color = Scalar( g_rng.uniform(0, 255), g_rng.uniform(0,255), g_rng.uniform(0,255) );//���������ɫֵ
		drawContours( drawing, g_vContours, i, color, 2, 8, g_vHierarchy, 0, Point() );//���������ڲ�����
		circle( drawing, mc[i], 4, color, -1, 8, 0 );;//����Բ
	}

	// ��ʾ��������
	namedWindow( WINDOW_NAME2, WINDOW_AUTOSIZE );
	imshow( WINDOW_NAME2, drawing );

	//ͨ��m00��������������Һ�OpenCV�����Ƚ�
	//printf("\t �������: �������������\n");
	for(unsigned  int i = 0; i< g_vContours.size(); i++ )
	{
		//printf(" >ͨ��m00���������[%d]�����: (M_00) = %.2f \n OpenCV��������������=%.2f , ����: %.2f \n\n", i, mu[i].m00, contourArea(g_vContours[i]), arcLength( g_vContours[i], true ) );
		Scalar color = Scalar( g_rng.uniform(0, 255), g_rng.uniform(0,255), g_rng.uniform(0,255) );
		drawContours( drawing, g_vContours, i, color, 2, 8, g_vHierarchy, 0, Point() );
		circle( drawing, mc[i], 4, color, -1, 8, 0 );
	}
}

