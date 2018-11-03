#include <iostream>
#include "nbild.h"

using namespace std;

int main()
{
    string filename = "../M1Kryptographie/test.txt";

    NBild test = NBild(filename);
    cout << test.nrows << endl;
    test.writeToFile("../M1Kryptographie/outTest.txt");

    return 0; // main will always return int, if left out it will return 0 meaning that no errors occured during execution)
}

void visualcrypt()
{
   string filename;
   cout << "Enter path";
   cin >> filename;
}


