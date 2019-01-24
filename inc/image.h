#ifndef IMAGE
#define IMAGE
#include <string>
using namespace std;
class Image {
    public:
        Image();
        int getWidth();
        int getHeight();
        void setWidth(int width);
        void setHeight(int height);
        string getFileName();
        void setFileName(string finename);
        void sobel();
        int getValue(int a, int b);
        void setG(int a, int b, int c);
        long getFileSize(FILE *file);
        void initialize();
        int getG(int a, int b);
        void treshold(int val);
        int myCharToInteger(char c);
        void setPixel(int a,int b,int c);
        int getRes();
    private:
        string filename;
        int width;
        int height;
        int PxlPtr[250][250];
        int g[248][248];
        int ort;
};
#endif