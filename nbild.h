#ifndef NBILD_H
#define NBILD_H
#include <vector>
#include <fstream>
#include <ostream>
#include <stdlib.h>
using namespace std;

class NBild
{
    int toInt(char x);
    vector<int> toIntVec(string line);



    vector<vector<int>> getRandomImage(size_t nrows, size_t ncols);

public:
    NBild() {}
    NBild(size_t nrows, size_t ncols) {
        this->image = getRandomImage(nrows, ncols);
        this->ncols = ncols;
        this->nrows = nrows;
    }

    vector<vector<int>> image;
    size_t getRows() {return this->nrows;}
    size_t getCols() {return this->ncols;}

    void writeToFile(string outfile);
    void import(const string filename);

    int operator() (size_t i, size_t j) const;
    int &operator() (size_t i, size_t j);

    size_t nrows = 0;
    size_t ncols = 0;
};

#endif // NBILD_H
