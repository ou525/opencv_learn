#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


int main( )
{

	Mat girl=imread("./data/girl.jpg"); //载入图像到Mat
	namedWindow("girl"); //创建一个名为 "【1】动漫图"的窗口  
	imshow("girl",girl);//显示名为 "【1】动漫图"的窗口  

	Mat image= imread("./data/dota.jpg",1);
	Mat logo= imread("./data/dota_logo.jpg");

	//载入后先显示
	namedWindow("1");
	imshow("1",image);

	namedWindow("2");
	imshow("2",logo);

	// 定义一个Mat类型，用于存放，图像的ROI
	Mat imageROI;
	//方法一
	imageROI= image(Rect(800,350,logo.cols,logo.rows));

	//imageROI= image(Range(350,350+logo.rows),Range(800,800+logo.cols));

	// 将logo加到原图上
	addWeighted(imageROI,0.5,logo,0.3,0.,imageROI);

	//显示结果
	namedWindow("3");
	imshow("3",image);

	//-----------------------------------【三、图像的输出】--------------------------------------
	//	描述：将一个Mat图像输出到图像文件
	//-----------------------------------------------------------------------------------------------
	//输出一张jpg图片到工程目录下
	imwrite("./data/4.jpg",image);

	waitKey(0);

	return 0;
}
