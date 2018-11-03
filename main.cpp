#include <iostream>
#include "nbild.h"

using namespace std;

int main()
{
    string filename = "../test.txt";

    NBild test = NBild(filename);
    cout << test.getRows() << endl;
    cout << test.getCols() << endl;

    cout << test(0,1) << endl;
    test(0,1) = 1;
    cout << test(0,1) << endl;
    test.writeToFile("../outTest.txt");

    return 0; // main will always return int, if left out it will return 0 meaning that no errors occured during execution)
}

void visualcrypt()
{
   string filename;
   cout << "Enter path";
   cin >> filename;
}


