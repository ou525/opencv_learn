//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������80
//		����������һάֱ��ͼ�Ļ���
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

//--------------------------------------��main( )������-----------------------------------------
//          ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-------------------------------------------------------------------------------------------------
int main()
{
	//��1������ԭͼ����ʾ
	Mat srcImage = imread("./data/32.jpg", 0);
	imshow("src",srcImage);
	if(!srcImage.data) {cout << "fail to load image" << endl; 	return 0;}

	//��2���������
	MatND dstHist;       // ��cv����CvHistogram *hist = cvCreateHist
	int dims = 1;
	float hranges[] = {0, 255};
	const float *ranges[] = {hranges};   // ������ҪΪconst����
	int size = 256;
	int channels = 0;

	//��3������ͼ���ֱ��ͼ
	calcHist(&srcImage, 1, &channels, Mat(), dstHist, dims, &size, ranges);    // cv ����cvCalcHist
	int scale = 1;

	Mat dstImage(size * scale, size, CV_8U, Scalar(0));
	//��4����ȡ���ֵ����Сֵ
	double minValue = 0;
	double maxValue = 0;
	minMaxLoc(dstHist,&minValue, &maxValue, 0, 0);  //  ��cv���õ���cvGetMinMaxHistValue

	//��5�����Ƴ�ֱ��ͼ
	int hpt = saturate_cast<int>(0.9 * size);
	for(int i = 0; i < 256; i++)
	{
		float binValue = dstHist.at<float>(i);           //   ע��hist����float����    ����OpenCV1.0������cvQueryHistValue_1D
		int realValue = saturate_cast<int>(binValue * hpt/maxValue);
		rectangle(dstImage,Point(i*scale, size - 1), Point((i+1)*scale - 1, size - realValue), Scalar(255));
	}
	imshow("dst", dstImage);
	waitKey(0);
	return 0;
}