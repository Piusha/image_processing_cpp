//
//  WebCam.cpp
//  OpenCv
//
//  Created by Piusha Kalyana on 8/24/17.
//  Copyright © 2017 Piusha Kalyana. All rights reserved.
//

#include "WebCam.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
WebCam::WebCam()
{

    cout << "WebCam class Constructed";
    
}

bool WebCam::show()
{

    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    
    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
    

}
