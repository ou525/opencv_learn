//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������65
//		����������remap�����÷�ʾ��
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


//-----------------------------------��main( )������--------------------------------------------
//          ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-----------------------------------------------------------------------------------------------
int main(  )
{
	//��0����������
	Mat srcImage, dstImage1, dstImage2;
	Mat map_x, map_y;

	//��1������ԭʼͼ
	srcImage = imread( "./data/22.jpg", 1 );
	if(!srcImage.data ) { printf("read error!!! \n"); return false; }  
	imshow("source",srcImage);

	//��2��������ԭʼͼһ����Ч��ͼ��x��ӳ��ͼ��y��ӳ��ͼ
	dstImage1.create( srcImage.size(), srcImage.type() );
	dstImage2.create( srcImage.size(), srcImage.type() );
	map_x.create( srcImage.size(), CV_32FC1 );
	map_y.create( srcImage.size(), CV_32FC1 );

	//��3��˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ
	for( int j = 0; j < srcImage.rows;j++)
	{ 
		for( int i = 0; i < srcImage.cols;i++)
		{
			//�ı�map_x & map_y��ֵ. 
			map_x.at<float>(j,i) = static_cast<float>(i);
			map_y.at<float>(j,i) = static_cast<float>(srcImage.rows - j);
			// map_y.at<float>(j,i) = static_cast<float>(j);
		} 
	}

	//��4��������ӳ�����
	//�˾�����OpenCV2��Ϊ��
	//remap( srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0, 0) );
	//�˾�����OpenCV3��Ϊ��
	remap( srcImage, dstImage1, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0, 0) );

	//��5����ʾЧ��ͼ
	imshow( "dstImage1", dstImage1 );

	//��3��˫��ѭ��������ÿһ�����ص㣬�ı�map_x & map_y��ֵ
	for( int j = 0; j < srcImage.rows;j++)
	{ 
		for( int i = 0; i < srcImage.cols;i++)
		{
			//�ı�map_x & map_y��ֵ. 
			map_x.at<float>(j,i) = static_cast<float>(srcImage.cols - i);
			map_y.at<float>(j,i) = static_cast<float>(srcImage.rows - j);
			// map_y.at<float>(j,i) = static_cast<float>(j);
		} 
	}
	remap( srcImage, dstImage2, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0, 0) );
	imshow( "dstImage2", dstImage2 );
	waitKey();

	return 0;
}

