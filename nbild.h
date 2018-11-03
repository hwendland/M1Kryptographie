#ifndef NBILD_H
#define NBILD_H
#include <vector>
#include <fstream>
#include <ostream>
using namespace std;

class NBild
{
    int toInt(char x);
    vector<int> toIntVec(string line);

    size_t nrows = 0;
    size_t ncols = 0;

public:
    NBild() {}

    vector<vector<int>> image;
    size_t getRows() {return this->nrows;}
    size_t getCols() {return this->ncols;}

    void writeToFile(string outfile);
    void import(const string filename);

    int operator() (size_t i, size_t j) const;
    int &operator() (size_t i, size_t j);
};

#endif // NBILD_H
