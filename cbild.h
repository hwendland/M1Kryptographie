#ifndef CBILD_H
#define CBILD_H
#include "nbild.h"


class CBild
{
    vector<vector<int>> A = {{0,1},{1,0}};
    vector<vector<int>> B = {{1,0},{0,1}};

public:
    CBild(char key) {
        this->key = key;
    }

    char key;
    NBild originalImage;
    NBild encodedImage;

    void import(const string filename);
    void writeToFile(NBild imageToWrite, string outfile);

    void encode();
    void decode();
};

#endif // CBILD_H
