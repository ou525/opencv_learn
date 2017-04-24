//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV2���鱾����ʾ������18
//		����������HelloOpenCV
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------

//---------------------------------��ͷ�ļ��������ռ�������֡�-----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//-------------------------------------------------------------------------------------------------
#include <opencv2/opencv.hpp>
using namespace cv;

//-----------------------------------���궨�岿�֡�--------------------------------------------
//  ����������һЩ������ 
//------------------------------------------------------------------------------------------------ 
#define WINDOW_NAME "xxxxxxxxxx"        //Ϊ���ڱ��ⶨ��ĺ� 


//-----------------------------------��ȫ�ֺ����������֡�------------------------------------
//		������ȫ�ֺ���������
//------------------------------------------------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle( cv::Mat& img, cv::Rect box );
void ShowHelpText( );

//-----------------------------------��ȫ�ֱ����������֡�-----------------------------------
//		������ȫ�ֱ���������
//-----------------------------------------------------------------------------------------------
Rect g_rectangle;
bool g_bDrawingBox = false;//�Ƿ���л���
RNG g_rng(12345);



//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-------------------------------------------------------------------------------------------------
int main( int argc, char** argv ) 
{
	//��0���ı�console������ɫ
	system("color 9F"); 

	//��1��׼������
	g_rectangle = Rect(-1,-1,0,0);
	Mat srcImage(600, 800,CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	g_rectangle = Rect(-1,-1,0,0);
	srcImage = Scalar::all(0);

	//��2�������������ص�����
	namedWindow( WINDOW_NAME );
	setMouseCallback(WINDOW_NAME,on_MouseHandle,(void*)&srcImage);

	//��3��������ѭ���������л��Ƶı�ʶ��Ϊ��ʱ�����л���
	while(1)
	{
		srcImage.copyTo(tempImage);//����Դͼ����ʱ����
		if( g_bDrawingBox ) DrawRectangle( tempImage, g_rectangle );//�����л��Ƶı�ʶ��Ϊ�棬����л���
		imshow( WINDOW_NAME, tempImage );
		if( waitKey( 10 ) == 27 ) break;//����ESC���������˳�
	}
	return 0;
}



//--------------------------------��on_MouseHandle( )������-----------------------------
//		���������ص����������ݲ�ͬ������¼����в�ͬ�Ĳ���
//-----------------------------------------------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{

	Mat& image = *(cv::Mat*) param;
	switch( event)
	{
		//����ƶ���Ϣ
	case EVENT_MOUSEMOVE: 
		{
			if( g_bDrawingBox )//����Ƿ���л��Ƶı�ʶ��Ϊ�棬���¼�³��Ϳ���RECT�ͱ�����
			{
				g_rectangle.width = x-g_rectangle.x;
				g_rectangle.height = y-g_rectangle.y;
			}
		}
		break;

		//���������Ϣ
	case EVENT_LBUTTONDOWN: 
		{
			g_bDrawingBox = true;
			g_rectangle =Rect( x, y, 0, 0 );//��¼��ʼ��
		}
		break;

		//���̧����Ϣ
	case EVENT_LBUTTONUP: 
		{
			g_bDrawingBox = false;//�ñ�ʶ��Ϊfalse
			//�Կ��͸�С��0�Ĵ���
			if( g_rectangle.width < 0 )
			{
				g_rectangle.x += g_rectangle.width;
				g_rectangle.width *= -1;
			}

			if( g_rectangle.height < 0 ) 
			{
				g_rectangle.y += g_rectangle.height;
				g_rectangle.height *= -1;
			}
			//���ú������л���
			DrawRectangle( image, g_rectangle );
		}
		break;

	}
}



//-----------------------------------��DrawRectangle( )������------------------------------
//		�������Զ���ľ��λ��ƺ���
//-----------------------------------------------------------------------------------------------
void DrawRectangle( cv::Mat& img, cv::Rect box )
{
	cv::rectangle(img,box.tl(),box.br(),cv::Scalar(g_rng.uniform(0, 255), g_rng.uniform(0,255), g_rng.uniform(0,255)));//�����ɫ
}
