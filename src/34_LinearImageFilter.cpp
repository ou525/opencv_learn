
//------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//	������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage,g_dstImage1,g_dstImage2,g_dstImage3;//�洢ͼƬ��Mat����
int g_nBoxFilterValue=3;  //�����˲�����ֵ
int g_nMeanBlurValue=3;  //��ֵ�˲�����ֵ
int g_nGaussianBlurValue=3;  //��˹�˲�����ֵ


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//	������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
//�ĸ��켣���Ļص�����
static void on_BoxFilter(int, void *);		//��ֵ�˲�
static void on_MeanBlur(int, void *);		//��ֵ�˲�
static void on_GaussianBlur(int, void *);			//��˹�˲�

//-----------------------------------��main( )������--------------------------------------------
//	����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main(   )
{

	system("color5E");

	// ����ԭͼ
	g_srcImage = imread( "./data/7.jpg", 1 );
	if( !g_srcImage.data ) { printf("read source image error  \n"); return false; }

	//��¡ԭͼ������Mat������
	g_dstImage1 = g_srcImage.clone( );
	g_dstImage2 = g_srcImage.clone( );
	g_dstImage3 = g_srcImage.clone( );

	//��ʾԭͼ
	namedWindow("source", 1);
	imshow("source",g_srcImage);


	//=================��<1>�����˲���==================
	//��������
	namedWindow("out_box", 1);
	//�����켣��
	createTrackbar("boxFilter", "out_box", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_BoxFilter(g_nBoxFilterValue, 0);
	//================================================

	//=================��<2>��ֵ�˲���==================
	//��������
	namedWindow("out_Blur", 1);
	//�����켣��
	createTrackbar("blur", "out_Blur",&g_nMeanBlurValue, 40,on_MeanBlur );
	on_MeanBlur(g_nMeanBlurValue,0);
	//================================================

	//=================��<3>��˹�˲���=====================
	//��������
	namedWindow("out_GaussianBlur", 1);
	//�����켣��
	createTrackbar("GaussianBlur", "out_GaussianBlur",&g_nGaussianBlurValue, 40,on_GaussianBlur );
	on_GaussianBlur(g_nGaussianBlurValue,0);
	//================================================


	// //���һЩ������Ϣ
	// cout<<endl<<"\t���гɹ���������������۲�ͼ��Ч��~\n\n"
	// 	<<"\t���¡�q����ʱ�������˳���\n";

	//���¡�q����ʱ�������˳�
	while(char(waitKey(1)) != 'q') {}

	return 0;
}


//-----------------------------��on_BoxFilter( )������------------------------------------
//	�����������˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_BoxFilter(int, void *)
{
	//�����˲�����
	boxFilter( g_srcImage, g_dstImage1, -1,Size( g_nBoxFilterValue+1, g_nBoxFilterValue+1));
	//��ʾ����
	imshow("out_box", g_dstImage1);
}


//-----------------------------��on_MeanBlur( )������------------------------------------
//	��������ֵ�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_MeanBlur(int, void *)
{
	//��ֵ�˲�����
	blur( g_srcImage, g_dstImage2, Size( g_nMeanBlurValue+1, g_nMeanBlurValue+1), Point(-1,-1));
	//��ʾ����
	imshow("out_Blur", g_dstImage2);
}


//-----------------------------��ContrastAndBright( )������------------------------------------
//	��������˹�˲������Ļص�����
//-----------------------------------------------------------------------------------------------
static void on_GaussianBlur(int, void *)
{
	//��˹�˲�����
	GaussianBlur( g_srcImage, g_dstImage3, Size( g_nGaussianBlurValue*2+1, g_nGaussianBlurValue*2+1 ), 0, 0);
	//��ʾ����
	imshow("out_GaussianBlur", g_dstImage3);
}


