
//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������54
//		����������ͼ���������resize�ۺ�ʾ��
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


//-----------------------------------���궨�岿�֡�--------------------------------------------
//	����������һЩ������
//------------------------------------------------------------------------------------------------
#define WINDOW_NAME "source"		//Ϊ���ڱ��ⶨ��ĺ�


//-----------------------------------��ȫ�ֱ����������֡�--------------------------------------
//		������ȫ�ֱ�������
//-----------------------------------------------------------------------------------------------
Mat g_srcImage, g_dstImage, g_tmpImage;


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//		������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
static void ShowHelpText();

//-----------------------------------��main( )������--------------------------------------------
//		����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main( )
{
	//����ԭͼ
	g_srcImage = imread("./data/15.jpg");//����Ŀ¼����Ҫ��һ����Ϊ1.jpg�Ĳ���ͼ������ߴ��豻2��N�η�������NΪ�������ŵĴ���
	if( !g_srcImage.data ) { printf("read error!!! \n"); return false; }

	// ������ʾ����
	namedWindow( WINDOW_NAME, WINDOW_AUTOSIZE );
	imshow(WINDOW_NAME, g_srcImage);

	//������ֵ
	g_tmpImage = g_srcImage;
	g_dstImage = g_tmpImage;

	int key =0;

	//��ѯ��ȡ������Ϣ
	while(1)
	{
		key=waitKey(9) ;//��ȡ��ֵ��key������

		//����key������ֵ�����в�ͬ�Ĳ���
		switch(key)
		{
			//======================�������˳���ؼ�ֵ����=======================  
		case 27://����ESC
			return 0;
			break; 

		case 'q'://����Q
			return 0;
			break; 

			//======================��ͼƬ�Ŵ���ؼ�ֵ����=======================  
		case 'a'://����A���£�����pyrUp����
			pyrUp( g_tmpImage, g_dstImage, Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ) );
			printf( "pyrUp pyrUp pyrUp pyrUp \n" );		
			break; 

		case 'w'://����W���£�����resize����
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ));
			printf( "wwwwwwwwwwwwww \n" );		
			break; 

		case '1'://����1���£�����resize����
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ));
			printf( "11111111111111 \n" );
			break; 

		case '3': //����3���£�����pyrUp����
			pyrUp( g_tmpImage, g_dstImage, Size( g_tmpImage.cols*2, g_tmpImage.rows*2 ));
			printf( "33333333333333333 \n" );
			break; 
			//======================��ͼƬ��С��ؼ�ֵ����=======================  
		case 'd': //����D���£�����pyrDown����
			pyrDown( g_tmpImage, g_dstImage, Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ));
			printf( "ddddddddddddddddddddddddddddd\n" );
			break; 

		case  's' : //����S���£�����resize����
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ));
			printf( "sssssssssssssssssssss\n" );
			break; 

		case '2'://����2���£�����resize����
			resize(g_tmpImage,g_dstImage,Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ));
			printf( "22222222222222222222222222222\n" );
			break; 

		case '4': //����4���£�����pyrDown����
			pyrDown( g_tmpImage, g_dstImage, Size( g_tmpImage.cols/2, g_tmpImage.rows/2 ) );
			printf( "4444444444444444444444444444444\n" );
			break; 
		}

		//������������ʾ�仯���ͼ
		imshow( WINDOW_NAME, g_dstImage );

		//��g_dstImage����g_tmpImage��������һ��ѭ��
		g_tmpImage = g_dstImage;
	}

	return 0;
}
