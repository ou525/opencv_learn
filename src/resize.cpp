#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char* argv[])
{
    // std::string path = "";
    int resize_height = 256;
    int resize_width = 256;
    cv::Mat src = cv::imread("./data/1.jpg"); 
    cv::Mat dst;
    imshow("src1", src);
    cv::resize(src, dst, cv::Size(src.rows*2, src.cols*2), (0, 0), (0, 0), cv::INTER_LINEAR);
    imshow("dst", dst);

    cv::waitKey(0);
    return 0;
}
