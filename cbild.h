#ifndef CBILD_H
#define CBILD_H
#include "nbild.h"


class CBild
{
    vector<vector<int>> A = {{0,1},{1,0}};
    vector<vector<int>> B = {{1,0},{0,1}};

public:
    CBild(string key) {
        if (key == "A"|key == "B"){
            this->key = key;
        } else {
            throw 2;
        }
    }

    string key;
    NBild originalImage;
    NBild encodedImage;

    void import(const string filename);
    void writeToFile(NBild imageToWrite, string outfile);

    NBild encode(NBild source_image);
    NBild overlay(NBild image1, NBild image2);

    NBild create_enc_image(size_t ncols, size_t nrows);

    NBild decode(NBild source_image);


};

#endif // CBILD_H
