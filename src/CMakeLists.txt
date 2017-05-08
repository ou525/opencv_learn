find_package( OpenCV REQUIRED )

#添加头文件和库文件
#ADD_DEFINITIONS( ${PCL_DEFINITIONS} )
#INCLUDE_DIRECTORIES( ${PCL_INCLUDE_DIRS} )
#LINK_LIBRARIES( ${PCL_LIBRARY_DIRS} )

#ADD_EXECUTABLE( main main.cpp )
#ADD_EXECUTABLE(pcl_pass_filter pcl_pass_filter.cpp)
#TARGET_LINK_LIBRARIES( pcl_pass_filter ${PCL_LIBRARIES} )

find_package( OpenCV REQUIRED )

ADD_EXECUTABLE(imwrite imwrite.cpp)
TARGET_LINK_LIBRARIES( imwrite ${OpenCV_LIBS} )


ADD_EXECUTABLE(16_LoadShowOutputImage 16_LoadShowOutputImage.cpp)
TARGET_LINK_LIBRARIES( 16_LoadShowOutputImage ${OpenCV_LIBS} )

ADD_EXECUTABLE(17_CreateTrackbar 17_CreateTrackbar.cpp)
TARGET_LINK_LIBRARIES( 17_CreateTrackbar ${OpenCV_LIBS} )

ADD_EXECUTABLE(18_UseMouse 18_UseMouse.cpp)
TARGET_LINK_LIBRARIES( 18_UseMouse ${OpenCV_LIBS} )

ADD_EXECUTABLE(19_UseMat 19_UseMat.cpp)
TARGET_LINK_LIBRARIES( 19_UseMat ${OpenCV_LIBS} )

ADD_EXECUTABLE(20_DrawImage 20_DrawImage.cpp)
TARGET_LINK_LIBRARIES( 20_DrawImage ${OpenCV_LIBS} )

ADD_EXECUTABLE(21_UsePointerAccessPixel 21_UsePointerAccessPixel.cpp)
TARGET_LINK_LIBRARIES( 21_UsePointerAccessPixel ${OpenCV_LIBS} )

ADD_EXECUTABLE(25_ImageBlending 25_ImageBlending.cpp)
TARGET_LINK_LIBRARIES( 25_ImageBlending ${OpenCV_LIBS} )

ADD_EXECUTABLE(27_ChangeContrastAndBright 27_ChangeContrastAndBright.cpp)
TARGET_LINK_LIBRARIES( 27_ChangeContrastAndBright ${OpenCV_LIBS} )

ADD_EXECUTABLE(28_DFT 28_DFT.cpp)
TARGET_LINK_LIBRARIES( 28_DFT ${OpenCV_LIBS} )

ADD_EXECUTABLE(29_Write_XML_and_YAML_File 29_Write_XML_and_YAML_File.cpp)
TARGET_LINK_LIBRARIES( 29_Write_XML_and_YAML_File ${OpenCV_LIBS} )

ADD_EXECUTABLE(30_Read_XML_and_YAML_File 30_Read_XML_and_YAML_File.cpp)
TARGET_LINK_LIBRARIES( 30_Read_XML_and_YAML_File ${OpenCV_LIBS} )

ADD_EXECUTABLE(31_boxFilter 31_boxFilter.cpp)
TARGET_LINK_LIBRARIES( 31_boxFilter ${OpenCV_LIBS} )

ADD_EXECUTABLE(34_LinearImageFilter 34_LinearImageFilter.cpp)
TARGET_LINK_LIBRARIES( 34_LinearImageFilter ${OpenCV_LIBS} )

ADD_EXECUTABLE(37_ImageFiltering 37_ImageFiltering.cpp)
TARGET_LINK_LIBRARIES( 37_ImageFiltering ${OpenCV_LIBS} )

ADD_EXECUTABLE(40_dilate_And_erode 40_dilate_And_erode.cpp)
TARGET_LINK_LIBRARIES( 40_dilate_And_erode ${OpenCV_LIBS} )

ADD_EXECUTABLE(48_Morphology 48_Morphology.cpp)
TARGET_LINK_LIBRARIES( 48_Morphology ${OpenCV_LIBS} )

ADD_EXECUTABLE(49_floodFill 49_floodFill.cpp)
TARGET_LINK_LIBRARIES( 49_floodFill ${OpenCV_LIBS} )

ADD_EXECUTABLE(50_floodFill2 50_floodFill2.cpp)
TARGET_LINK_LIBRARIES( 50_floodFill2 ${OpenCV_LIBS} )

ADD_EXECUTABLE(51_resize 51_resize.cpp)
TARGET_LINK_LIBRARIES( 51_resize ${OpenCV_LIBS} )

ADD_EXECUTABLE(52_pyrUp 52_pyrUp.cpp)
TARGET_LINK_LIBRARIES( 52_pyrUp ${OpenCV_LIBS} )

ADD_EXECUTABLE(54_PyrAndResize 54_PyrAndResize.cpp)
TARGET_LINK_LIBRARIES( 54_PyrAndResize ${OpenCV_LIBS} )

ADD_EXECUTABLE(55_threshold 55_threshold.cpp)
TARGET_LINK_LIBRARIES( 55_threshold ${OpenCV_LIBS} )

ADD_EXECUTABLE(56_canny 56_canny.cpp)
TARGET_LINK_LIBRARIES( 56_canny ${OpenCV_LIBS} )

ADD_EXECUTABLE(57_sobel 57_sobel.cpp)
TARGET_LINK_LIBRARIES( 57_sobel ${OpenCV_LIBS} )

ADD_EXECUTABLE(60_EdgeDetection 60_EdgeDetection.cpp)
TARGET_LINK_LIBRARIES( 60_EdgeDetection ${OpenCV_LIBS} )

ADD_EXECUTABLE(61_HoughLines 61_HoughLines.cpp)
TARGET_LINK_LIBRARIES( 61_HoughLines ${OpenCV_LIBS} )

ADD_EXECUTABLE(62_HoughLinesP 62_HoughLinesP.cpp)
TARGET_LINK_LIBRARIES( 62_HoughLinesP ${OpenCV_LIBS} )

ADD_EXECUTABLE(63_HoughCircles 63_HoughCircles.cpp)
TARGET_LINK_LIBRARIES( 63_HoughCircles ${OpenCV_LIBS} )

ADD_EXECUTABLE(65_remap 65_remap.cpp)
TARGET_LINK_LIBRARIES( 65_remap ${OpenCV_LIBS} )

ADD_EXECUTABLE(66_remap2 66_remap2.cpp)
TARGET_LINK_LIBRARIES( 66_remap2 ${OpenCV_LIBS} )

ADD_EXECUTABLE(67_AffineTransform 67_AffineTransform.cpp)
TARGET_LINK_LIBRARIES( 67_AffineTransform ${OpenCV_LIBS} )

ADD_EXECUTABLE(68_equalizeHist 68_equalizeHist.cpp)
TARGET_LINK_LIBRARIES( 68_equalizeHist ${OpenCV_LIBS} )

ADD_EXECUTABLE(69_findContours 69_findContours.cpp)
TARGET_LINK_LIBRARIES( 69_findContours ${OpenCV_LIBS} )

ADD_EXECUTABLE(71_convexHull 71_convexHull.cpp)
TARGET_LINK_LIBRARIES( 71_convexHull ${OpenCV_LIBS} )

ADD_EXECUTABLE(72_convexHull2 72_convexHull2.cpp)
TARGET_LINK_LIBRARIES( 72_convexHull2 ${OpenCV_LIBS} )

ADD_EXECUTABLE(76_ContourMoment 76_ContourMoment.cpp)
TARGET_LINK_LIBRARIES( 76_ContourMoment ${OpenCV_LIBS} )

ADD_EXECUTABLE(77_watershed 77_watershed.cpp)
TARGET_LINK_LIBRARIES( 77_watershed ${OpenCV_LIBS} )

ADD_EXECUTABLE(78_inpaint 78_inpaint.cpp)
TARGET_LINK_LIBRARIES( 78_inpaint ${OpenCV_LIBS} )

ADD_EXECUTABLE(79_H-S-Histogram 79_H-S-Histogram.cpp)
TARGET_LINK_LIBRARIES( 79_H-S-Histogram ${OpenCV_LIBS} )

ADD_EXECUTABLE(80_Histogram2 80_Histogram2.cpp)
TARGET_LINK_LIBRARIES( 80_Histogram2 ${OpenCV_LIBS} )

ADD_EXECUTABLE(82_compareHist 82_compareHist.cpp)
TARGET_LINK_LIBRARIES( 82_compareHist ${OpenCV_LIBS} )

ADD_EXECUTABLE(83_calcBackProject 83_calcBackProject.cpp)
TARGET_LINK_LIBRARIES( 83_calcBackProject ${OpenCV_LIBS} )

ADD_EXECUTABLE(84_matchTemplate 84_matchTemplate.cpp)
TARGET_LINK_LIBRARIES( 84_matchTemplate ${OpenCV_LIBS} )

ADD_EXECUTABLE(orb orb.cpp)
TARGET_LINK_LIBRARIES( orb ${OpenCV_LIBS} )

ADD_EXECUTABLE(gama gama.cpp)
TARGET_LINK_LIBRARIES( gama ${OpenCV_LIBS} )

ADD_EXECUTABLE(gray gray.cpp)
TARGET_LINK_LIBRARIES( gray ${OpenCV_LIBS} )

ADD_EXECUTABLE(resize resize.cpp)
TARGET_LINK_LIBRARIES( resize ${OpenCV_LIBS} )
