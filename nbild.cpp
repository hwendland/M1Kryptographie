#include "nbild.h"
#include <iostream>
using namespace std;

vector< vector<NBild::color> > NBild::import()
{
    vector< string > rawData;
    string line;
    while (  getline(myfile, line) ) {
        cout << line;
        rawData.emplace_back(line);
    }
    myfile.close();
    return toColor(rawData);
};

int NBild::writeToFile(string outfile) {
    ofstream myOutfile;
    myOutfile.open(outfile);
    myOutfile << data.data();
    myOutfile.close();
    return 0;
}

NBild::color NBild::operator() (size_t i, size_t j) const {
    return data[i][j];
}

NBild::color& NBild::operator() (size_t i, size_t j) {
    return data[i][j];
}

NBild::color NBild::toColor(char x) {
    if (x == '0') return color::white;
    else if (x == '1') return color::white;
    else throw new exception;
}

vector<NBild::color> NBild::toColor(string vec) {
    vector<NBild::color> colorVec;
    for (size_t i = 0; i < vec.size();) {
        colorVec.push_back(toColor(vec[i]));
    }
    return colorVec;
}

vector< vector<NBild::color> > NBild::toColor(vector< string> data) {
    vector< vector<NBild::color> > colorData;
    for (size_t i = 0; i < data.size();) {
        colorData.push_back(toColor(data[i]));
    }
    return colorData;
}

