//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV2���鱾����ʾ������82
//		����������ֱ��ͼ�Ա�
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


//--------------------------------------��main( )������-----------------------------------------
//          ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-----------------------------------------------------------------------------------------------
int main( )
{

	//��1�����������׼ͼ����������ŶԱ�ͼ��ľ���( RGB �� HSV )
	Mat srcImage_base, hsvImage_base;
	Mat srcImage_test1, hsvImage_test1;
	Mat srcImage_test2, hsvImage_test2;
	Mat hsvImage_halfDown;

	//��2�������׼ͼ��(srcImage_base) �����Ų���ͼ��srcImage_test1��srcImage_test2������ʾ
	srcImage_base = imread( "./data/33.jpg",1 );
	srcImage_test1 = imread( "./data/34.jpg", 1 );
	srcImage_test2 = imread( "./data/35.jpg", 1 );
	//��ʾ�����3��ͼ��
	imshow("base",srcImage_base);
	imshow("base_test1",srcImage_test1);
	imshow("base_test2",srcImage_test2);

	// ��3����ͼ����BGRɫ�ʿռ�ת���� HSVɫ�ʿռ�
	cvtColor( srcImage_base, hsvImage_base,  COLOR_BGR2HSV );
	cvtColor( srcImage_test1, hsvImage_test1, COLOR_BGR2HSV );
	cvtColor( srcImage_test2, hsvImage_test2, COLOR_BGR2HSV );

	//��4������������׼ͼ���°벿�İ���ͼ��(HSV��ʽ)
	hsvImage_halfDown = hsvImage_base( Range( hsvImage_base.rows/2, hsvImage_base.rows - 1 ), Range( 0, hsvImage_base.cols - 1 ) );

	//��5����ʼ������ֱ��ͼ��Ҫ��ʵ��
	// ��hueͨ��ʹ��30��bin,��saturatoinͨ��ʹ��32��bin
	int h_bins = 50; int s_bins = 60;
	int histSize[] = { h_bins, s_bins };
	// hue��ȡֵ��Χ��0��256, saturationȡֵ��Χ��0��180
	float h_ranges[] = { 0, 256 };
	float s_ranges[] = { 0, 180 };
	const float* ranges[] = { h_ranges, s_ranges };
	// ʹ�õ�0�͵�1ͨ��
	int channels[] = { 0, 1 };

	// ��6����������ֱ��ͼ�� MatND ���ʵ��:
	MatND baseHist;
	MatND halfDownHist;
	MatND testHist1;
	MatND testHist2;

	// ��7�������׼ͼ�����Ų���ͼ�񣬰����׼ͼ���HSVֱ��ͼ:
	calcHist( &hsvImage_base, 1, channels, Mat(), baseHist, 2, histSize, ranges, true, false );
	normalize( baseHist, baseHist, 0, 1, NORM_MINMAX, -1, Mat() );

	calcHist( &hsvImage_halfDown, 1, channels, Mat(), halfDownHist, 2, histSize, ranges, true, false );
	normalize( halfDownHist, halfDownHist, 0, 1, NORM_MINMAX, -1, Mat() );

	calcHist( &hsvImage_test1, 1, channels, Mat(), testHist1, 2, histSize, ranges, true, false );
	normalize( testHist1, testHist1, 0, 1, NORM_MINMAX, -1, Mat() );

	calcHist( &hsvImage_test2, 1, channels, Mat(), testHist2, 2, histSize, ranges, true, false );
	normalize( testHist2, testHist2, 0, 1, NORM_MINMAX, -1, Mat() );


	//��8����˳��ʹ��4�ֶԱȱ�׼����׼ͼ���ֱ��ͼ�������ֱ��ͼ���жԱ�:
	for( int i = 0; i < 4; i++ )
	{ 
		//����ͼ��ֱ��ͼ�ĶԱ�
		int compare_method = i;
		double base_base = compareHist( baseHist, baseHist, compare_method );
		double base_half = compareHist( baseHist, halfDownHist, compare_method );
		double base_test1 = compareHist( baseHist, testHist1, compare_method );
		double base_test2 = compareHist( baseHist, testHist2, compare_method );
		//������
		printf( " method [%d] compute result \n\n base-base: %f, base-half: %f, base-test1: %f, base-test2: %f \n-----------------------------------------------------------------\n", i, base_base, base_half , base_test1, base_test2 );
	}

	printf( "game over" );
	waitKey(0);
	return 0;
}