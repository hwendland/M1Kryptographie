#include "nbild.h"
#include <iostream>
#include <string>
#include <random>

using namespace std;

// Set up random number generator for random image generation
static random_device rd;
static mt19937 gen(rd());
static uniform_int_distribution<int> dis(0, 1);

// Random image generation (used to initialize image with fixed size)
vector<vector<int>> NBild::getRandomImage(size_t nrows, size_t ncols) {
    vector<vector<int>> randomImage;
    for (size_t i=0; i<nrows; i++) {
        vector<int> randomInts;
        for (size_t j = 0; j < ncols; j++) {
            int randInt = dis(gen);
            randomInts.emplace_back(randInt);
        }
       randomImage.emplace_back(randomInts);
    }
    this->image = randomImage;
    return randomImage;
}

// File export
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

// File import
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

// Utility function for safe conversion from char to int during import
int NBild::toInt(char x) {
    if (!(x == '0' | x == '1')){
        throw 0;
    } else if (x == '0') {
        return 0;
    } else {
        return 1;
    }
}

// Utility function to convert a string into a vector of integers
vector<int> NBild::toIntVec(string line) {
    vector<int> lineVec;
    for (size_t j=0; j < line.size(); j++) {
        char charAtJ = line.at(j);
        lineVec.emplace_back(toInt(charAtJ));
    }
    return lineVec;
}

// Read and write access for image fields
int NBild::operator() (size_t i, size_t j) const {
    return this->image[i][j];
}
int& NBild::operator() (size_t i, size_t j) {
    return this->image[i][j];
}
