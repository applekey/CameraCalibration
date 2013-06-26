//
//#include <stdio.h>
//#include <opencv2/highgui/highgui.hpp>
//#include <string>
//#include <iostream>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <math.h>
//
//using namespace std;
//using namespace cv;
//
//
//
//#define DEBUG_PHASE 0
//
//int main()
//{
//	string rightVideoLocation = "C:\\Users\\linda\\Desktop\\FaceR15.avi";
//	string leftVideoLocation = "C:\\Users\\linda\\Desktop\\FaceL15.avi";
//
//	CvCapture* rightVideo = cvCaptureFromAVI(rightVideoLocation.c_str());
//	CvCapture* leftVideo = cvCaptureFromAVI(leftVideoLocation.c_str());
//
//	if(!rightVideo)
//		throw " right video problem";
//	if(! leftVideo)
//		throw "left video problem";
//
//	Mat rightFrames[4];
//	Mat leftFrames[4];
//
//	cout <<"Reading in frames.\n";
//	
//	for( int i =0; i<4; i++)
//	{
//		Mat frameR = cvQueryFrame( rightVideo );
//		Mat frameL =  cvQueryFrame( leftVideo );
//		
//		cvtColor(frameR, frameR, CV_BGR2GRAY);
//		cvtColor(frameL, frameL, CV_BGR2GRAY);
//
//		frameR.copyTo(rightFrames[i]);
//		frameL.copyTo(leftFrames[i]);
//	
//	}
//
//#ifdef DEBUG_CAPTURE 
//	namedWindow( "Frames", CV_WINDOW_AUTOSIZE );
//	for(int i =0; i<4;i++)
//	{
//		imshow( "Frames", rightFrames[i] );
//		waitKey(0);
//	}
//
//	for(int i =0; i<4;i++)
//	{
//		imshow( "Frames", leftFrames[i] );
//		waitKey(0);
//	}
//#endif
//
//	// unwrap
//	cv::Size s = leftFrames[1].size();
//	int rows = s.height;
//	int cols = s.width;
//
//	Mat phaseLeft(rows,cols,CV_8U);
//	Mat phaseRight(rows,cols,CV_8U);
//
//	for( int r =0; r<rows;r++)
//	{
//		for(int c =0;c<cols;c++)
//		{
//			char LI1 = leftFrames[0].at<char>(r,c);
//			char LI2 = leftFrames[1].at<char>(r,c);
//			char LI3 = leftFrames[2].at<char>(r,c);
//
//			char RI1 = rightFrames[0].at<char>(r,c);
//			char RI2 = rightFrames[1].at<char>(r,c);
//			char RI3 = rightFrames[2].at<char>(r,c);
//
//			phaseLeft.at<char>(r,c) = sqrt(3.0)*(LI1 - LI3)/(2.0*LI2-LI1-LI3);
//			phaseRight.at<char>(r,c) = sqrt(3.0)*(RI1 - RI3)/(2.0*RI2-RI1-RI3);
//		}
//	}
//
//#ifdef DEBUG_PHASE 
//
//	namedWindow( "Phase", CV_WINDOW_AUTOSIZE );
//
//	double min = 0;
//	double max = 255;
//	cv::minMaxIdx(phaseLeft, &min, &max);
//	cv::Mat adjMap;
//	cv::convertScaleAbs(phaseLeft, adjMap, 255 / max);
//	cv::imshow("Phase", adjMap);
//
//
//	
//	//
//	//imshow( "Phase", phaseLeft );
//	//waitKey(0);
//	//imshow( "Phase", phaseRight );
//	waitKey(0);
//#endif
//	 
//
//
//
//
//	// CLEAN up
//	cvReleaseCapture( &rightVideo );
//	cvReleaseCapture( &leftVideo );
//
//
//
//}