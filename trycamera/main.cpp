#include "mainwindow.h"
#include <QApplication>

#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<iostream>

using namespace std;
using namespace cv;

#define CameraName "摄像头框"
#define PictureName "图片框"
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}
int main()
{
    VideoCapture capture(0);//从默认摄像头中读取
    if(capture.isOpened()==0)
    {
        cout<<"-1:Failed to open the camera"<<endl;
        return -1;
    }
    Mat viewframe;
    char keydown;//按下的按键
    char picname[256];//图片保存名
    namedWindow(CameraName);
    namedWindow(PictureName);
    for(int i=1;1;)
    {
        capture>>viewframe;
        imshow(CameraName,viewframe);//展示一帧
        keydown=waitKey(20);
        if(keydown=='s')
        {
            sprintf(picname,"camerashoot%d.jpg",i++);
            imwrite(picname,viewframe);//输出图片到文件
            imshow(PictureName,viewframe);
        }
    }
    return 0;
}
