#include "../inc/image.h"
#include "math.h"
#include "iostream"
#include "fstream"
typedef unsigned char BYTE;

long Image::getFileSize(FILE *file){
    long lCurPos, lEndPos;
    lCurPos = ftell(file);
    fseek(file, 0, 2);
    lEndPos = ftell(file);
    fseek(file, lCurPos, 0);
    return lEndPos;
};  
Image::Image(){};
int Image::myCharToInteger(char c){
  return int((c+256)%256);
};
void Image::initialize() {// Binary file reading
	streampos begin,end;
	ifstream myfile (getFileName(), ios::binary);
	begin = myfile.tellg();
	char *arr;
	arr = new char[2];
	myfile.read(arr,2);

	int n = int((arr[0]+256)%256);
  	int m = int((arr[1]+256)%256);
  	int imgSize = n * m;
  	delete arr;
  
  	myfile.seekg(2,ios::beg);
  	arr = new char[imgSize];
  	myfile.read(arr, imgSize);

  	int **img = new int*[n];
  	for(int i=0;i<n;i++){
		img[i] = new int[m];
	}

  	int ind=0;
  
  	int q=0;
	for(int i=0;i<getHeight();i++)
		for(int j=0;j<getWidth();j++){
			PxlPtr[j][i] = int(arr[q]);
			q++;
		}
		int ort = 0;
	for(int i=0;i<getHeight();i++)
		for(int j=0;j<getWidth();j++){
			ort += getValue(i,j);
		}
		int res = ort / getWidth()*getHeight();
		this->ort = res;
  	end = myfile.tellg();
  
  	myfile.close();
};
int Image::getRes() {return this->ort;} 
void Image::setWidth(int width) {this->width = width;}; // Setter
void Image::setHeight(int height) {this->height = height;}; // Setter
int Image::getWidth() {return this->width;};
int Image::getHeight() {return this->height;}; // Setter
string Image::getFileName() {return this->filename;}; // Setter
void Image::setFileName(string filename) {this->filename = filename;}; // Setter
int Image::getValue(int a, int b) {return PxlPtr[a][b];}
int Image::getG(int a, int b) {return g[a][b];}
void Image::setG(int a, int b, int c) {g[a][b] = c;};	
void Image::treshold(int val) {
	ofstream fout ("image.txt", std::ios_base::app);
	for(int i=0;i<getWidth()-2;i++){
		for(int j=0;j<getHeight()-2;j++) {
			if(g[i][j] > val) {fout << "1";setG(i,j,1);}
			else {fout << "0";setG(i,j,0);}
		}
		fout << endl;
	}
}
void Image::sobel() {
	int SUM, sumX, sumY, deger1,deger2,deger3;
	for(int i = 0; i < getHeight()-2 ; i++)
	    {
	        for(int j = 1; j < getWidth()-2 ; j++)
	        {
	            sumX = 0;
	            sumY = 0;
				deger1=getValue(i,j-1);
				deger2=getValue(i,j);
				deger3=getValue(i,j+1);
	                sumX = (deger1*1)+
						   (deger1 * 2)+
						   (deger1 * 1)+
						   (deger3 * -1)+
						   (deger3*-2)+
					       (deger3 *-1);

					sumY = (deger1*1)+
						   (deger2 * 2)+
						   (deger3 * 1)+
						   (deger1 * -1)+
						   (deger2*-2)+
						   (deger3 *-1);

	               SUM = sqrt(pow(sumX,2) + pow(sumY,2));
				   setG(i,j,SUM);
	        }
	    }
	      
}
void Image::setPixel(int a,int b,int c) {this->PxlPtr[a][b] = c;}