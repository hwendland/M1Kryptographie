#ifndef NBILD_H
#define NBILD_H
#include <vector>
#include <fstream>
#include <ostream>
#include <map>
using namespace std;

class NBild
{

public:
    NBild(const string infile) {
        this->image = import(infile);
        this->nrows = this->image.size();
        this->ncols = this->image[0].size();
    }

    vector<string> image;

    char operator() (int i, int j) const;
    char &operator() (int i, int j);

    vector<string> import(const string filename);
    void writeToFile(string outfile);

    size_t nrows;
    size_t ncols;
};

#endif // NBILD_H
