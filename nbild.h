#ifndef NBILD_H
#define NBILD_H
#include <vector>
#include <fstream>
#include <ostream>
#include <map>
using namespace std;

class NBild
{
    ifstream myfile;

    enum color { black = 1, white = 0 };

    vector< vector<color> > data;

    vector< vector<color> > toColor(vector< string >);
    vector<color> toColor(string);
    color toColor(char);

public:
    NBild(const string infile) {
        myfile.open(infile, ios::in);
        this->import();
    }

    color operator() (size_t i, size_t j) const;
    color &operator() (size_t i, size_t j);

    vector< vector<color> > import();
    int writeToFile(string outfile);

    const size_t nrows = data.size();
    const size_t ncols = data[0].size();
};

#endif // NBILD_H
