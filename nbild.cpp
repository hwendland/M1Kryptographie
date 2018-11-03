#include "nbild.h"
#include <iostream>
#include <string>
using namespace std;


void NBild::writeToFile(string outfile) {
    ofstream myOutfile;
    myOutfile.open(outfile, ios::out);
    cout << "Writing image" << endl;
    for (size_t i = 0; i < this->nrows; i++) {
        myOutfile << this->image[i] << endl;
    }
    myOutfile.close();
}


vector<string> NBild::import(const string filename) {
    ifstream myfile;
    string line;
    vector<string> image;
    myfile.open(filename);
    bool open = myfile.is_open();
    if (open)  {
        cout << "Starting import" << endl;
        while (myfile >> line) {
            image.emplace_back(line);
        }
    }
    myfile.close();
    return image;
}

void NBild::setPixel(size_t i, size_t j, int value) {
    assert(value == 0 | value == 1);
    string line = this->image[i];
    line.replace(j, 1, to_string(value));
    this->image.at(i) = line;
    cout << "New value is " << this->image[i][j] << endl;
}

char NBild::getPixel(size_t i, size_t j) {
    return this->image[i][j];
}

//char NBild::operator() (int i, int j) const {
//    return this->image[static_cast<size_t>(i)][static_cast<size_t>(j)];
//};
//char& NBild::operator() (int i, int j) {
//    return this->image[static_cast<size_t>(i)][static_cast<size_t>(j)];
//};



