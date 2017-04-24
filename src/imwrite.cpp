//--------------------------------------¡Ÿ³ÌÐòËµÃ÷¡¿-------------------------------------------
//		³ÌÐòËµÃ÷£º¡¶OpenCV3±à³ÌÈëÃÅ¡·OpenCV3°æÊé±ŸÅäÌ×ÊŸÀý³ÌÐò15
//		³ÌÐòÃèÊö£ºÀûÓÃimwriteº¯ÊýÉú³ÉŽøÍžÃ÷ÍšµÀµÄpngÍŒÏñ
//		¿ª·¢²âÊÔËùÓÃ²Ù×÷ÏµÍ³£º Windows 7 64bit
//		¿ª·¢²âÊÔËùÓÃIDE°æ±Ÿ£ºVisual Studio 2010
//		¿ª·¢²âÊÔËùÓÃOpenCV°æ±Ÿ£º	3.0 beta
//		2014Äê11ÔÂ Created by @Ç³Ä«_Ã«ÐÇÔÆ
//		2014Äê12ÔÂ Revised by @Ç³Ä«_Ã«ÐÇÔÆ
//------------------------------------------------------------------------------------------------


//---------------------------------¡ŸÍ·ÎÄŒþ¡¢ÃüÃû¿ÕŒä°üº¬²¿·Ö¡¿----------------------------
//		ÃèÊö£º°üº¬³ÌÐòËùÊ¹ÓÃµÄÍ·ÎÄŒþºÍÃüÃû¿ÕŒä
//-------------------------------------------------------------------------------------------------
#include <vector>
#include <stdio.h>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;


//--------------------------------¡ŸcreateAlphaMat( )º¯Êý¡¿--------------------------------
//		ÃèÊö£ºŽŽœšŽøalphaÍšµÀµÄMat
//-------------------------------------------------------------------------------------------------
void createAlphaMat(Mat &mat)
{
	for(int i = 0; i < mat.rows; ++i) {
		for(int j = 0; j < mat.cols; ++j) {
			Vec4b&rgba = mat.at<Vec4b>(i, j);
			rgba[0]= UCHAR_MAX;
			rgba[1]= saturate_cast<uchar>((float (mat.cols - j)) / ((float)mat.cols) *UCHAR_MAX);
			rgba[2]= saturate_cast<uchar>((float (mat.rows - i)) / ((float)mat.rows) *UCHAR_MAX);
			rgba[3]= saturate_cast<uchar>(0.5 * (rgba[1] + rgba[2]));
		}
	}
}



//-----------------------------------¡ŸShowHelpText( )º¯Êý¡¿----------------------------------
//          ÃèÊö£ºÊä³öÒ»Ð©°ïÖúÐÅÏ¢
//----------------------------------------------------------------------------------------------
void ShowHelpText()
{
	//Êä³ö»¶Ó­ÐÅÏ¢ºÍOpenCV°æ±Ÿ
	printf("\n\n\t\t\t·Ç³£žÐÐ»¹ºÂò¡¶OpenCV3±à³ÌÈëÃÅ¡·Ò»Êé£¡\n");
	printf("\n\n\t\t\tŽËÎª±ŸÊéOpenCV3°æµÄµÚ15žöÅäÌ×ÊŸÀý³ÌÐò\n");
	printf("\n\n\t\t\t   µ±Ç°Ê¹ÓÃµÄOpenCV°æ±ŸÎª£º" CV_VERSION );
	printf("\n\n  ----------------------------------------------------------------------------\n");
}



int main( )
{
	//ŽŽœšŽøalphaÍšµÀµÄMat
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);

	//ShowHelpText();

	vector<int>compression_params;
	//ŽËŸäŽúÂëµÄOpenCV2°æÎª£º
	//compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
	//ŽËŸäŽúÂëµÄOpenCV3°æÎª£º
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	//ÏÔÊŸÍŒÆ¬
	try{
		imwrite("out.png", mat, compression_params);
		imshow("out",mat);
		fprintf(stdout,"\n");
		waitKey(0);
	}
	catch(runtime_error& ex) {
		fprintf(stderr,"ÍŒÏñ×ª»»³ÉPNGžñÊœ·¢ÉúŽíÎó£º%s\n", ex.what());
		return 1;
	}

	return 0;
}