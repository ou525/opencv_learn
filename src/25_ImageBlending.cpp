//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV2���鱾����ʾ������25
//		��������������ͼ����
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------


//---------------------------------��ͷ�ļ��������ռ�������֡�-------------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------                                                                                 
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//-----------------------------------��ȫ�ֺ����������֡�--------------------------------------
//	������ȫ�ֺ�������
//-----------------------------------------------------------------------------------------------
bool  ROI_AddImage();
bool  LinearBlending();
bool  ROI_LinearBlending();
void   ShowHelpText();

//-----------------------------------��main( )������--------------------------------------------
//	����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼ
//-----------------------------------------------------------------------------------------------
int main(   )
{
	// system("color 6F");

	if(ROI_AddImage( )&& LinearBlending( )&&ROI_LinearBlending( ))
	{
		cout<<endl<<"\neeeeeeeeeeeeeeeeeeeeeeee";
	}

	waitKey(0);
	return 0;
}

bool  ROI_AddImage()
{

	// ��1������ͼ��
	Mat srcImage1= imread("./data/dota_pa.jpg");
	Mat logoImage= imread("./data/dota_logo.jpg");
	if( !srcImage1.data ) { printf("11111111111 \n"); return false; }
	if( !logoImage.data ) { printf("22222222222 \n"); return false; }

	// ��2������һ��Mat���Ͳ������趨ROI����
	Mat imageROI= srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));

	// ��3��������ģ�������ǻҶ�ͼ��
	Mat mask= imread("./data/dota_logo.jpg",0);

	//��4������Ĥ������ROI
	logoImage.copyTo(imageROI,mask);

	// ��5����ʾ���
	//namedWindow("3333333333333333333333333");
	imshow("4444444444444444444444",srcImage1);

	return true;
}

bool  LinearBlending()
{
	//��0������һЩ�ֲ�����
	double alphaValue = 0.7; 
	double betaValue;
	Mat srcImage2, srcImage3, dstImage;

	// ��1����ȡͼ�� ( ����ͼƬ��Ϊͬ�������ͺͳߴ� )
	srcImage2 = imread("./data/mogu.jpg");
	srcImage3 = imread("./data/rain.jpg");

	if( !srcImage2.data ) { printf("5555555555555555555555 \n"); return false; }
	if( !srcImage3.data ) { printf("6666666666666666666666 \n"); return false; }

	// ��2������ͼ���ϼ�Ȩ����
	betaValue = ( 1.0 - alphaValue );
	addWeighted( srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);

	// ��3����ʾԭͼ����
	imshow( "7777777777777777777777", srcImage2 );
	imshow( "8888888888888888888888", dstImage );

	return true;

}

//---------------------------------��ROI_LinearBlending������-------------------------------------
// ��������ROI_LinearBlending����
// ���������Ի��ʵ�ֺ���,ָ����������ͼ����.����cv::addWeighted����������϶���
//			  ����Ȥ����ROI��ʵ���Զ�����������Ի��
//--------------------------------------------------------------------------------------------
bool  ROI_LinearBlending()
{

	//��1����ȡͼ��
	Mat srcImage4= imread("./data/dota_pa.jpg",1);
	Mat logoImage= imread("./data/dota_logo.jpg");

	if( !srcImage4.data ) { printf("999999999999999999999999999 \n"); return false; }
	if( !logoImage.data ) { printf("qqqqqqqqqqqqqqqqqqqqqqqqqqq \n"); return false; }

	//��2������һ��Mat���Ͳ������趨ROI����
	Mat imageROI;
	//����һ
	imageROI= srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));
	//������
	//imageROI= srcImage4(Range(250,250+logoImage.rows),Range(200,200+logoImage.cols));

	//��3����logo�ӵ�ԭͼ��
	addWeighted(imageROI,0.5,logoImage,0.3,0.,imageROI);

	//��4����ʾ���
	imshow("wwwwwwwwwwwwwwwwwwwwwwwwwwww",srcImage4);

	return true;
}

