#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace cv;

int red, green, blue;

void paint(Mat &image, int row, int col){

    row = row * 2 + 1;
    col = col * 2 + 1;

    MatIterator_<Vec3b> p = image.begin<Vec3b>();

    for(int i = 0; i < 2; i++){

        for(int j = 0; j < 2; j++){

            (*(p + ((row + i) * image.cols + (col + j))))[0] = blue;
            (*(p + ((row + i) * image.cols + (col + j))))[1] = green;
            (*(p + ((row + i) * image.cols + (col + j))))[2] = red;

            (*(p + ((row + i) * image.cols + (image.cols - 1 - (col + j)))))[0] = blue;
            (*(p + ((row + i) * image.cols + (image.cols - 1 - (col + j)))))[1] = green;
            (*(p + ((row + i) * image.cols + (image.cols - 1 - (col + j)))))[2] = red;

        }

    }

}

int main() {

    Mat image(Size(12, 12), CV_8UC3, Scalar(240, 240, 240));

    time_t curTime;
    srand(time(&curTime) + clock());

    string fileName = asctime(localtime(&curTime));
    fileName.pop_back();
    fileName += ".png";

    red = random() % 256;
    green = random() % 256;
    blue = random() % 256;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            if( random() & 1 )
                paint(image, i, j);
        }
    }

    resize(image, image, Size(420, 420), 0, 0, INTER_NEAREST);

    if( imwrite(fileName, image) ){
        cout <<"File saved as : \"" <<fileName <<"\"\n";
    }
    else {
        cout <<"ERROR Saving file\n";
    }

    return 0;

}
