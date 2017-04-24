
//--------------------------------------������˵����-------------------------------------------
//		����˵������OpenCV3������š�OpenCV3���鱾����ʾ������71
//		����������͹��������
//		�����������ò���ϵͳ�� Windows 7 64bit
//		������������IDE�汾��Visual Studio 2010
//		������������OpenCV�汾��	3.0 beta
//		2014��11�� Created by @ǳī_ë����
//		2014��12�� Revised by @ǳī_ë����
//------------------------------------------------------------------------------------------------



//---------------------------------��ͷ�ļ��������ռ�������֡�----------------------------
//		����������������ʹ�õ�ͷ�ļ��������ռ�
//------------------------------------------------------------------------------------------------
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;



//--------------------------------------��main( )������-----------------------------------------
//          ����������̨Ӧ�ó������ں��������ǵĳ�������￪ʼִ��
//-----------------------------------------------------------------------------------------------
int main( )
{
	//��ʼ�����������ֵ
	Mat image(600, 600, CV_8UC3);
	RNG& rng = theRNG();

	//ѭ��������ESC,Q,q�������˳��������м����±�һֱ����
	while(1)
	{
		//������ʼ��
		char key;//��ֵ
		int count = (unsigned)rng%100 + 3;//������ɵ������
		vector<Point> points; //��ֵ

		//������ɵ�����
		for(int i = 0; i < count; i++ )
		{
			Point point;
			point.x = rng.uniform(image.cols/4, image.cols*3/4);
			point.y = rng.uniform(image.rows/4, image.rows*3/4);

			points.push_back(point);
		}

		//���͹��
		vector<int> hull;
		convexHull(Mat(points), hull, true);

		//���Ƴ������ɫ�ĵ�
		image = Scalar::all(0);
		for(int i = 0; i < count; i++ )
			circle(image, points[i], 3, Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), FILLED, LINE_AA);

		//׼������
		int hullcount = (int)hull.size();//͹���ı���
		Point point0 = points[hull[hullcount-1]];//����͹���ߵ������

		//����͹���ı�
		for(int  i = 0; i < hullcount; i++ )
		{
			Point point = points[hull[i]];
			line(image, point0, point, Scalar(255, 255, 255), 2, LINE_AA);
			point0 = point;
		}

		//��ʾЧ��ͼ
		imshow("111111", image);

		//����ESC,Q,����q�������˳�
		key = (char)waitKey();
		if( key == 27 || key == 'q' || key == 'Q' ) 
			break;
	}

	return 0;
}
