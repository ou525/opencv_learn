
//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������37
//		��������������ͼ���˲��ۺ�ʾ��
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------

//-----------------------------------��ͷ�ļ��������֡�---------------------------------------
//		����������������������ͷ�ļ�
//---------------------------------------------------------------------------------------------- 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

//-----------------------------------�������ռ��������֡�---------------------------------------
//		����������������ʹ�õ������ռ�
//-----------------------------------------------------------------------------------------------  
using namespace std;
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage,g_dstImage1,g_dstImage2,g_dstImage3,g_dstImage4,g_dstImage5;
int g_nBoxFilterValue=6;  //�����˲��ں�ֵ
int g_nMeanBlurValue=10;  //��ֵ�˲��ں�ֵ
int g_nGaussianBlurValue=6;  //��˹�˲��ں�ֵ
int g_nMedianBlurValue=10;  //��ֵ�˲�����ֵ
int g_nBilateralFilterValue=10;  //˫���˲�����ֵ


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
//�켣���ص�����
static void on_BoxFilter(int, void *);		//�����˲�
static void on_MeanBlur(int, void *);		//��ֵ���˲���
static void on_GaussianBlur(int, void *);			//��˹�˲���
static void on_MedianBlur(int, void *);			//��ֵ�˲���
static void on_BilateralFilter(int, void *);			//˫���˲���


//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main(   )
{
	// ����ԭͼ
	g_srcImage = imread( "./data/8.jpg", 1 );
	if( !g_srcImage.data ) { printf("no input \n"); return false; }

	//��¡ԭͼ���ĸ�Mat������
	g_dstImage1 = g_srcImage.clone( );
	g_dstImage2 = g_srcImage.clone( );
	g_dstImage3 = g_srcImage.clone( );
	g_dstImage4 = g_srcImage.clone( );
	g_dstImage5 = g_srcImage.clone( );

	//��ʾԭͼ
	namedWindow("source image", 1);
	imshow("source image",g_srcImage);


	//=================��<1>�����˲���=========================
	//��������
	namedWindow("output1 image", 1);
	//�����켣��
	createTrackbar("111111111111", "output1 image",&g_nBoxFilterValue, 50,on_BoxFilter );
	on_MeanBlur(g_nBoxFilterValue,0);
	imshow("output1 image", g_dstImage1);
	//=====================================================


	//=================��<2>��ֵ�˲���==========================
	//��������
	namedWindow("output2 image", 1);
	//�����켣��
	createTrackbar("2222222222222", "output2 image",&g_nMeanBlurValue, 50,on_MeanBlur );
	on_MeanBlur(g_nMeanBlurValue,0);
	//======================================================


	//=================��<3>��˹�˲���===========================
	//��������
	namedWindow("output3 image", 1);
	//�����켣��
	createTrackbar("33333333333333333", "output3 image",&g_nGaussianBlurValue, 50,on_GaussianBlur );
	on_GaussianBlur(g_nGaussianBlurValue,0);
	//=======================================================


	//=================��<4>��ֵ�˲���===========================
	//��������
	namedWindow("output4 image", 1);
	//�����켣��
	createTrackbar("44444444444444", "output4 image",&g_nMedianBlurValue, 50,on_MedianBlur );
	on_MedianBlur(g_nMedianBlurValue,0);
	//=======================================================


	//=================��<5>˫���˲���===========================
	//��������
	namedWindow("output5 image", 1);
	//�����켣��
	createTrackbar("55555555555555555", "output5 image",&g_nBilateralFilterValue, 50,on_BilateralFilter);
	on_BilateralFilter(g_nBilateralFilterValue,0);
	//=======================================================


	//���һЩ������Ϣ
	// cout<<endl<<"\t���гɹ���������������۲�ͼ��Ч��~\n\n"
	// 	<<"\t���¡�q����ʱ�������˳���\n";
	while(char(waitKey(1)) != 'q') {}

	return 0;
}

//-----------------------------��on_BoxFilter( )������------------------------------------
//		�����������˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_BoxFilter(int, void *)
{
	//�����˲�����
	boxFilter( g_srcImage, g_dstImage1, -1,Size( g_nBoxFilterValue+1, g_nBoxFilterValue+1));
	//��ʾ����
	imshow("output1 image", g_dstImage1);
}

//-----------------------------��on_MeanBlur( )������------------------------------------
//		��������ֵ�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_MeanBlur(int, void *)
{
	blur( g_srcImage, g_dstImage2, Size( g_nMeanBlurValue+1, g_nMeanBlurValue+1), Point(-1,-1));
	imshow("output2 image", g_dstImage2);

}

//-----------------------------��on_GaussianBlur( )������------------------------------------
//		��������˹�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_GaussianBlur(int, void *)
{
	GaussianBlur( g_srcImage, g_dstImage3, Size( g_nGaussianBlurValue*2+1, g_nGaussianBlurValue*2+1 ), 0, 0);
	imshow("output3 image", g_dstImage3);
}


//-----------------------------��on_MedianBlur( )������------------------------------------
//		��������ֵ�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_MedianBlur(int, void *)
{
	medianBlur ( g_srcImage, g_dstImage4, g_nMedianBlurValue*2+1 );
	imshow("output4 image", g_dstImage4);
}


//-----------------------------��on_BilateralFilter( )������------------------------------------
//		������˫���˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_BilateralFilter(int, void *)
{
	bilateralFilter ( g_srcImage, g_dstImage5, g_nBilateralFilterValue, g_nBilateralFilterValue*2, g_nBilateralFilterValue/2 );
	imshow("output5 image", g_dstImage5);
}




