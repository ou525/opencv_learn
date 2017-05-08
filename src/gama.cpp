#include <opencv2/highgui/highgui.hpp>      
#include <opencv2/imgproc/imgproc.hpp>  
  
using namespace cv;

void MyGammaCorrection(Mat& src, Mat& dst, float fGamma)  
{  
    CV_Assert(src.data);  
  
    // accept only char type matrices  
    CV_Assert(src.depth() != sizeof(uchar));  
  
    // build look up table  
    unsigned char lut[256];  
    for( int i = 0; i < 256; i++ )  
    {  
        lut[i] = saturate_cast<uchar>(pow((float)(i/255.0), fGamma) * 255.0f);  
    }  
  
    dst = src.clone();  
    const int channels = dst.channels();  
    switch(channels)  
    {  
        case 1:  
            {  
  
                MatIterator_<uchar> it, end;  
                for( it = dst.begin<uchar>(), end = dst.end<uchar>(); it != end; it++ )  
                    //*it = pow((float)(((*it))/255.0), fGamma) * 255.0;  
                    *it = lut[(*it)];  
  
                break;  
            }  
        case 3:   
            {  
  
                MatIterator_<Vec3b> it, end;  
                for( it = dst.begin<Vec3b>(), end = dst.end<Vec3b>(); it != end; it++ )  
                {  
                    //(*it)[0] = pow((float)(((*it)[0])/255.0), fGamma) * 255.0;  
                    //(*it)[1] = pow((float)(((*it)[1])/255.0), fGamma) * 255.0;  
                    //(*it)[2] = pow((float)(((*it)[2])/255.0), fGamma) * 255.0;  
                    (*it)[0] = lut[((*it)[0])];  
                    (*it)[1] = lut[((*it)[1])];  
                    (*it)[2] = lut[((*it)[2])];  
                }  
  
                break;  
  
            }  
    }  
}   
  
int main(int argc, char *argv[])  
{  
    Mat image = imread("./data/img_gray_screenshot_03.05.2017.png");  
    Mat imageGamma(image.size(), CV_32FC3);  
    // for (int i = 0; i < image.rows; i++)  
    // {  
    //     for (int j = 0; j < image.cols; j++)  
    //     {  
    //         imageGamma.at<Vec3f>(i, j)[0] = (image.at<Vec3b>(i, j)[0])*(image.at<Vec3b>(i, j)[0]);//*(image.at<Vec3b>(i, j)[0]);  
    //         imageGamma.at<Vec3f>(i, j)[1] = (image.at<Vec3b>(i, j)[1])*(image.at<Vec3b>(i, j)[1]);//*(image.at<Vec3b>(i, j)[1]);  
    //         imageGamma.at<Vec3f>(i, j)[2] = (image.at<Vec3b>(i, j)[2])*(image.at<Vec3b>(i, j)[2]);//*(image.at<Vec3b>(i, j)[2]);  
    //     }  
    // }  
    // //归一化到0~255    
    // normalize(imageGamma, imageGamma, 0, 255, CV_MINMAX);  
    // //转换成8bit图像显示    
    // convertScaleAbs(imageGamma, imageGamma);

    MyGammaCorrection(image, imageGamma, 1.3);

    imshow("source", image);  
    imshow("gama output", imageGamma);  
    waitKey();  
    return 0;  
}  
