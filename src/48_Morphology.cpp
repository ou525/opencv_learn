
//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������48
//		������������̬ѧͼ�����������㡢�����㡢��̬ѧ�ݶȡ���ñ����ñ
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------



//---------------------------------��ͷ�ļ��������ռ�������֡�----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;


//-----------------------------------��ȫ�ֱ����������֡�-----------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage, g_dstImage;//ԭʼͼ��Ч��ͼ
int g_nElementShape = MORPH_RECT;//Ԫ�ؽṹ����״

//�������յ�TrackBarλ�ò���
int g_nMaxIterationNum = 10;
int g_nOpenCloseNum = 0;
int g_nErodeDilateNum = 0;
int g_nTopBlackHatNum = 0;



//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
static void on_OpenClose(int, void*);//�ص�����
static void on_ErodeDilate(int, void*);//�ص�����
static void on_TopBlackHat(int, void*);//�ص�����


//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main( )
{
	//����ԭͼ
	g_srcImage = imread("./data/10.jpg");
	if( !g_srcImage.data ) { printf("read error!!! \n"); return false; }

	//��ʾԭʼͼ
	namedWindow("source image");
	imshow("source image", g_srcImage);

	//������������
	namedWindow("OpenClose",1);
	namedWindow("ErodeDilate",1);
	namedWindow("TopBlackHat",1);

	//������ֵ
	g_nOpenCloseNum=9;
	g_nErodeDilateNum=9;
	g_nTopBlackHatNum=2;

	//�ֱ�Ϊ�������ڴ���������
	createTrackbar("1", "OpenClose",&g_nOpenCloseNum,g_nMaxIterationNum*2+1,on_OpenClose);
	createTrackbar("2", "ErodeDilate",&g_nErodeDilateNum,g_nMaxIterationNum*2+1,on_ErodeDilate);
	createTrackbar("3", "TopBlackHat",&g_nTopBlackHatNum,g_nMaxIterationNum*2+1,on_TopBlackHat);

	//��ѯ��ȡ������Ϣ
	while(1)
	{
		int c;

		//ִ�лص�����
		on_OpenClose(g_nOpenCloseNum, 0);
		on_ErodeDilate(g_nErodeDilateNum, 0);
		on_TopBlackHat(g_nTopBlackHatNum,0);

		//��ȡ����
		c = waitKey(0);

		//���¼��̰���Q����ESC�������˳�
		if( (char)c == 'q'||(char)c == 27 )
			break;
		//���¼��̰���1��ʹ����Բ(Elliptic)�ṹԪ�ؽṹԪ��MORPH_ELLIPSE
		if( (char)c == 49 )//���̰���1��ASII��Ϊ49
			g_nElementShape = MORPH_ELLIPSE;
		//���¼��̰���2��ʹ�þ���(Rectangle)�ṹԪ��MORPH_RECT
		else if( (char)c == 50 )//���̰���2��ASII��Ϊ50
			g_nElementShape = MORPH_RECT;
		//���¼��̰���3��ʹ��ʮ����(Cross-shaped)�ṹԪ��MORPH_CROSS
		else if( (char)c == 51 )//���̰���3��ASII��Ϊ51
			g_nElementShape = MORPH_CROSS;
		//���¼��̰���space���ھ��Ρ���Բ��ʮ���νṹԪ����ѭ��
		else if( (char)c == ' ' )
			g_nElementShape = (g_nElementShape + 1) % 3;
	}

	return 0;
}


//-----------------------------------��on_OpenClose( )������----------------------------------
//		��������������/�����㡿���ڵĻص�����
//-----------------------------------------------------------------------------------------------
static void on_OpenClose(int, void*)
{
	//ƫ�����Ķ���
	int offset = g_nOpenCloseNum - g_nMaxIterationNum;//ƫ����
	int Absolute_offset = offset > 0 ? offset : -offset;//ƫ��������ֵ
	//�Զ����
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset*2+1, Absolute_offset*2+1), Point(Absolute_offset, Absolute_offset) );
	//���в���
	if( offset < 0 )
		//�˾�����OpenCV2��Ϊ��
		//morphologyEx(g_srcImage, g_dstImage, CV_MOP_OPEN, element);
		//�˾�����OpenCV3��Ϊ:
		morphologyEx(g_srcImage, g_dstImage, MORPH_OPEN, element);
	else
		//�˾�����OpenCV2��Ϊ��
		//morphologyEx(g_srcImage, g_dstImage, CV_MOP_CLOSE, element);
		//�˾�����OpenCV3��Ϊ:
		morphologyEx(g_srcImage, g_dstImage, MORPH_CLOSE, element);
		


	//��ʾͼ��
	imshow("OpenClose",g_dstImage);
}


//-----------------------------------��on_ErodeDilate( )������----------------------------------
//		����������ʴ/���͡����ڵĻص�����
//-----------------------------------------------------------------------------------------------
static void on_ErodeDilate(int, void*)
{
	//ƫ�����Ķ���
	int offset = g_nErodeDilateNum - g_nMaxIterationNum;	//ƫ����
	int Absolute_offset = offset > 0 ? offset : -offset;//ƫ��������ֵ
	//�Զ����
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset*2+1, Absolute_offset*2+1), Point(Absolute_offset, Absolute_offset) );
	//���в���
	if( offset < 0 )
		erode(g_srcImage, g_dstImage, element);
	else
		dilate(g_srcImage, g_dstImage, element);
	//��ʾͼ��
	imshow("ErodeDilate",g_dstImage);
}


//-----------------------------------��on_TopBlackHat( )������--------------------------------
//		����������ñ����/��ñ���㡿���ڵĻص�����
//----------------------------------------------------------------------------------------------
static void on_TopBlackHat(int, void*)
{
	//ƫ�����Ķ���
	int offset = g_nTopBlackHatNum - g_nMaxIterationNum;//ƫ����
	int Absolute_offset = offset > 0 ? offset : -offset;//ƫ��������ֵ
	//�Զ����
	Mat element = getStructuringElement(g_nElementShape, Size(Absolute_offset*2+1, Absolute_offset*2+1), Point(Absolute_offset, Absolute_offset) );
	//���в���
	if( offset < 0 )
		morphologyEx(g_srcImage, g_dstImage, MORPH_TOPHAT , element);
	else
		morphologyEx(g_srcImage, g_dstImage, MORPH_BLACKHAT, element);
	//��ʾͼ��
	imshow("TopBlackHat",g_dstImage);
}

