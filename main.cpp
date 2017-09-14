#include "opencv2/opencv.hpp"
#include <iostream>
#include <unistd.h> 
using namespace std;
using namespace cv;
 

int i = 0;

int main(){
 
  // Create a VideoCapture object and use camera to capture the video
  VideoCapture cap(1); 
 
  // Check if camera opened successfully
  if(!cap.isOpened())
  {
    cout << "Error opening video stream" << endl; 
    return -1; 
  } 
 
  // Default resolution of the frame is obtained.The default resolution is system dependent. 
  int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH); 
  int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT); 
   
  // Define the codec and create VideoWriter object.The output is stored in 'outcpp.avi' file. 
  
  while(1)
  { 
    Mat frame; 
     
    // Capture frame-by-frame 
    cap >> frame;
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
     
    
    // Display the resulting frame    
    imshow( "Frame", frame );

    
    stringstream ss;
    ss << i;
    string str = ss.str();
    imwrite("/home/eirik/Sorting_robot/images/" + ss.str()+ ".jpg", frame );
    i++;
    // Press  ESC on keyboard to  exit
    usleep(1000*200);
    if(i == 25)
      break;
    char c = (char)waitKey(1);
    if( c == 27 ) 
      break;
  }
 
  // When everything done, release the video capture and write object
  cap.release();
  //video.release();
 
  // Closes all the windows
  destroyAllWindows();
  return 0;
}