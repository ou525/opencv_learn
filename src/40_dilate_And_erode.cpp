//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������40
//		����������ͼ��ʴ�������ۺ�ʾ��
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------



//---------------------------------��ͷ�ļ��������ռ�������֡�-----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage, g_dstImage;//ԭʼͼ��Ч��ͼ
int g_nTrackbarNumer = 0;//0��ʾ��ʴerode, 1��ʾ����dilate
int g_nStructElementSize = 3; //�ṹԪ��(�ں˾���)�ĳߴ�


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
void Process();//���ͺ͸�ʴ�Ĵ�����
void on_TrackbarNumChange(int, void *);//�ص�����
void on_ElementSizeChange(int, void *);//�ص�����

//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main( )
{

	//����ԭͼ
	g_srcImage = imread("./data/9.jpg");
	if( !g_srcImage.data ) { printf("read error \n"); return false; }

	//��ʾԭʼͼ
	namedWindow("source image");
	imshow("source image", g_srcImage);

	//���г��θ�ʴ��������ʾЧ��ͼ
	namedWindow("output image");
	//��ȡ�Զ����
	Mat element = getStructuringElement(MORPH_RECT, Size(2*g_nStructElementSize+1, 2*g_nStructElementSize+1),Point( g_nStructElementSize, g_nStructElementSize ));
	erode(g_srcImage, g_dstImage, element);
	imshow("output image", g_dstImage);

	//�����켣��
	createTrackbar("11111", "output image", &g_nTrackbarNumer, 1, on_TrackbarNumChange);
	createTrackbar("33333", "output image", &g_nStructElementSize, 21, on_ElementSizeChange);

	//��ѯ��ȡ������Ϣ������q���������˳�
	while(char(waitKey(1)) != 'q') {}

	return 0;
}

//-----------------------------��Process( )������------------------------------------
//		�����������Զ���ĸ�ʴ�����Ͳ���
//-----------------------------------------------------------------------------------------
void Process() 
{
	//��ȡ�Զ����
	Mat element = getStructuringElement(MORPH_RECT, Size(2*g_nStructElementSize+1, 2*g_nStructElementSize+1),Point( g_nStructElementSize, g_nStructElementSize ));

	//���и�ʴ�����Ͳ���
	if(g_nTrackbarNumer == 0) {    
		erode(g_srcImage, g_dstImage, element);
	}
	else {
		dilate(g_srcImage, g_dstImage, element);
	}

	//��ʾЧ��ͼ
	imshow("output image", g_dstImage);
}


//-----------------------------��on_TrackbarNumChange( )������------------------------------------
//		��������ʴ������֮���л����صĻص�����
//-----------------------------------------------------------------------------------------------------
void on_TrackbarNumChange(int, void *) 
{
	//��ʴ������֮��Ч���Ѿ��л����ص��������������һ��Process������ʹ�ı���Ч��������Ч����ʾ����
	Process();
}


//-----------------------------��on_ElementSizeChange( )������-------------------------------------
//		��������ʴ�����Ͳ����ں˸ı�ʱ�Ļص�����
//-----------------------------------------------------------------------------------------------------
void on_ElementSizeChange(int, void *)
{
	//�ں˳ߴ��Ѹı䣬�ص��������������һ��Process������ʹ�ı���Ч��������Ч����ʾ����
	Process();
}

