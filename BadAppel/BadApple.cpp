#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <Windows.h>
#include <iostream>

using namespace cv;
using namespace std;



int nScreenWidth = 960;
int nScreenHeight = 720;
int main() {
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;
    string path = "Resources/Bad Apple.mp4";
    VideoCapture cap(path);
    Mat img, graymat;
    int Pixel;
    int Frame = 0;
    while (cap.isOpened())
    {

        cap.read(img);
        cvtColor(img, graymat, COLOR_BGR2GRAY);

        int x = 0;
        for (int j = 0; j < graymat.rows; j=j+2)
        {


            for (int i = 0; i < graymat.cols; i++)
            {


                if (img.at<char>(j, i*3) == 0) {
                    screen[x] = ' ';
                }
                else if ((img.at<char>(j, i * 3) > 0) && (img.at<char>(j, i * 3) < 240)) {
                    screen[x] = '.';
                }
                else
                {
                    screen[x] = 'a';
                }

                x++;

            }
            
           


        }
        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);


        /*Naztar*/
    }
}