#include "nbild.h"
#include <iostream>
using namespace std;


void NBild::writeToFile(string outfile) {
    ofstream myOutfile;
    myOutfile.open(outfile, ios::out);
    cout << this->nrows;
    for (size_t i = 0; i < this->nrows; i++) {
        myOutfile << this->image[i] << endl;
        cout << "wrote line" << i << endl;
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
        cout << "Open" << endl;
        while (myfile >> line) {
            image.emplace_back(line);
        }
    }
    return image;
}

//char NBild::operator() (int i, int j) const {
//    return this->image[static_cast<size_t>(i)][static_cast<size_t>(j)];
//};
//char& NBild::operator() (int i, int j) {
//    return this->image[static_cast<size_t>(i)][static_cast<size_t>(j)];
//};



