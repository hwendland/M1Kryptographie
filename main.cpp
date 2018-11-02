#include <iostream>
#include "nbild.h"

using namespace std;

int main()
{
    string filename = "beispielbild_1.txt";
    NBild test = NBild(filename);
    test.import();
    cout << test(0,0);
    cout << test.nrows;

    return 0; // main will always return int, if left out it will return 0 meaning that no errors occured during execution)
}

void visualcrypt()
{
   string filename;
   cout << "Enter path";
   cin >> filename;
}
