#include "nbild.h"
#include <iostream>
#include <string>
using namespace std;

void NBild::writeToFile(string outfile) {
    ofstream myOutfile;
    myOutfile.open(outfile, ios::out);
    cout << "Writing image" << endl;
    for (size_t i = 0; i < this->nrows; i++) {
        vector<int> line = this->image[i];
        for (size_t j=0; j<line.size(); j++) {
            int intAtJ = line[j];
            string insertChar = to_string(intAtJ);
            myOutfile << insertChar;
        }
        myOutfile << endl;
    }
    myOutfile.close();
}

void NBild::import(const string filename) {
    ifstream myfile;
    string line;
    vector<vector<int>> image;
    myfile.open(filename);
    bool open = myfile.is_open();
    if (open)  {
        cout << "Starting import" << endl;
        while (myfile >> line) {
            try {
                image.emplace_back(toIntVec(line));
            } catch (exception) {
                image = {{}};
                throw;
            }
        }
    } else {
        throw 1; //file doesnt exist
    }
    myfile.close();
    this->image = image;
    this->nrows = this->image.size();
    this->ncols = this->image[0].size();
    for (size_t i = 1; i < nrows; i++) {
        if (image[i].size() != ncols) throw 0;
    }
}

int NBild::toInt(char x) {
    if (!(x == '0' | x == '1')){
        throw 0; // isnt 0 or 1
    } else if (x == '0') {
        return 0;
    } else {
        return 1;
    }
}

vector<int> NBild::toIntVec(string line) {
    vector<int> lineVec;
    for (size_t j=0; j < line.size(); j++) {
        char charAtJ = line.at(j);
        lineVec.emplace_back(toInt(charAtJ));
    }
    return lineVec;
}

int NBild::operator() (size_t i, size_t j) const {
    return this->image[i][j];
};
int& NBild::operator() (size_t i, size_t j) {
    return this->image[i][j];
};

vector<vector<int>> NBild::getRandomImage(size_t nrows, size_t ncols) {
    vector<vector<int>> randomImage;
    for (size_t i=0; i<nrows; i++) {
        vector<int> randomInts;
        for (size_t j = 0; j < ncols; j++) {
            int randInt = rand() % 2;
            randomInts.emplace_back(randInt);
        }
       randomImage.emplace_back(randomInts);
    }
    return randomImage;
}



