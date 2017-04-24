#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


int main( )
{

	Mat girl=imread("./data/girl.jpg"); //����ͼ��Mat
	namedWindow("girl"); //����һ����Ϊ "��1������ͼ"�Ĵ���  
	imshow("girl",girl);//��ʾ��Ϊ "��1������ͼ"�Ĵ���  

	Mat image= imread("./data/dota.jpg",1);
	Mat logo= imread("./data/dota_logo.jpg");

	//���������ʾ
	namedWindow("1");
	imshow("1",image);

	namedWindow("2");
	imshow("2",logo);

	// ����һ��Mat���ͣ����ڴ�ţ�ͼ���ROI
	Mat imageROI;
	//����һ
	imageROI= image(Rect(800,350,logo.cols,logo.rows));

	//imageROI= image(Range(350,350+logo.rows),Range(800,800+logo.cols));

	// ��logo�ӵ�ԭͼ��
	addWeighted(imageROI,0.5,logo,0.3,0.,imageROI);

	//��ʾ���
	namedWindow("3");
	imshow("3",image);

	//-----------------------------------������ͼ��������--------------------------------------
	//	��������һ��Matͼ�������ͼ���ļ�
	//-----------------------------------------------------------------------------------------------
	//���һ��jpgͼƬ������Ŀ¼��
	imwrite("./data/4.jpg",image);

	waitKey(0);

	return 0;
}
