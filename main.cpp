#include <iostream>
#include "nbild.h"
#include "cbild.h"

using namespace std;

int main()
{
    string filename = "../beispielbild_2.txt";

    NBild test = NBild(10,20);
    NBild test2 = NBild(5,6);

    NBild b;
    test.import(filename);
    cout << test.getRows() << endl;
    cout << test.getCols() << endl;

    cout << test(0,1) << endl;
    test.writeToFile("../outTest1.txt");
    test2.writeToFile("../outTest2.txt");

    CBild a = CBild('B');

    a.decode(a.encode(test)).writeToFile("../outTest.txt");

    //a.create_enc_image(5,5).writeToFile("../outTest.txt");
    return 0; // main will always return int, if left out it will return 0 meaning that no errors occured during execution)
}

void visualcrypt()
{
   string filename;
   cout << "Enter path";
   cin >> filename;
}


