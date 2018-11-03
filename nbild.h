#ifndef NBILD_H
#define NBILD_H
#include <vector>
#include <fstream>
#include <ostream>
using namespace std;

class NBild
{
    vector<string> import(const string filename);
    size_t nrows;
    size_t ncols;

public:
    NBild(const string infile) {
        this->image = import(infile);
        this->nrows = this->image.size();
        this->ncols = this->image[0].size();
    }

    vector<string> image;
    size_t getRows() {return this->nrows;}
    size_t getCols() {return this->ncols;}

    void writeToFile(string outfile);

    char operator() (size_t i, size_t j) const;
    char &operator() (size_t i, size_t j);

    void setPixel(size_t i, size_t j, int value);
    char getPixel(size_t i, size_t j);
};

#endif // NBILD_H
