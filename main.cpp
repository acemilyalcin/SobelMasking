/***********************************************************************
 * Adem Cemil YALÇIN
 * Mail: acemilyalcin@gmail.com
 * Purpose of Project: Sobel filtering and operator overloading.
 * *********************************************************************/
#include <iostream>
#include <fstream>
#include "arpa/inet.h"
#include "./inc/image.h"
using namespace std;
typedef unsigned char BYTE;

long getFileSize(FILE *file){
    long lCurPos, lEndPos;		
    lCurPos = ftell(file);
    fseek(file, 0, 2);
    lEndPos = ftell(file);
    fseek(file, lCurPos, 0);
    return lEndPos;
};

std::istream &operator>>(char *is, Image &filename) {
    filename.setFileName(is);
    FILE *file;
    BYTE *fileBuf;
    file = fopen(filename.getFileName().c_str(),"rb");
    unsigned int width, height;
    long fileSize = getFileSize(file);
    fileBuf = new BYTE[fileSize];
    fread(fileBuf, fileSize, 1, file);

    filename.setWidth((unsigned int)fileBuf[0]);
    filename.setHeight((unsigned int)fileBuf[1]);
    filename.initialize();
}
Image operator + (Image &img,Image &img2) {
    Image temp;
    for(int i=0;i<255;i++)
        for(int j=0;j<255;j++) {
            cout << img.getG(i,j) << " " << img2.getG(i,j) << endl;
            temp.setPixel(i,j,((img.getG(i,j)+img2.getG(i,j)%2)));
        }

    return temp;
}
Image operator * (Image &img,Image &img2) {
    Image temp;
    for(int i=0;i<255;i++)
        for(int j=0;j<255;j++) {
            temp.setPixel(i,j,(img.getG(i,j)*img2.getG(i,j)));
        }

    return temp;
}
Image operator ! (Image &img) {
    Image temp;
    for(int i=0;i<255;i++)
        for(int j=0;j<255;j++) {
            temp.setPixel(i,j,!(img.getG(i,j)));
        }

    return temp;
}
std::ostream &operator<<(char *is,Image &img) {
    ofstream fout ("image.txt", std::ios_base::app);
	for(int i=0;i<225;i++){
		for(int j=0;j<255;j++) {
				if(img.getValue(i,j) == 1) fout << "1";
				else fout << "0";
		}
		fout << endl;
	}
}
int main(int argc,char* args[]) {
    if(args[1] == NULL || args[2] == NULL || args[3] == NULL) { // Checking parameters
        cout << "Please check your parameters.";
        return 0;
    }

    Image i1,i2;
    args[1] >> i1;
    args[2] >> i2;
    i1.sobel();
    i1.treshold(100);
    i2.sobel();
    i2.treshold(100);

    Image i3;
    i3 = i1+i2;

    args[3] << i3;

    return 0;
}
