#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <Windows.h>
#include <iostream>

using namespace cv;
using namespace std;



int nScreenWidth = 48;
int nScreenHeight = 36;
int main() {
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;
    string path = "Resources/e.mp4";
    VideoCapture cap(path);
    Mat img, graymat;
    int Pixel;
    int Frame=0;
    while (cap.isOpened())
    {
        
        cap.read(img);
        cvtColor(img,graymat, COLOR_BGR2GRAY);

        int x = 0;
        for (int j = 0; j < graymat.rows; j++)
        {
            screen[x] = ';';
            x++;

            for (int i = 0; i < graymat.cols; i++)
            {

                
                if (img.at<char>(j, i) == 0) {
                    screen[x] = ' ';
                }
                else 
                {
                    screen[x] = 'a';
                }
             
                x++;
            
            }
                        screen[x] = ';';
            x++;


        }
        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
        imshow("My Image", graymat);
        waitKey(20);
       

      
    }
}