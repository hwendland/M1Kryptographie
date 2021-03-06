#include <iostream>
#include <ostream>
#include <string>
#include "nbild.h"
#include "cbild.h"
#include <cstdlib>

using namespace std;

/*!
 * @brief a little console for accessing the functionality of the crytography
 */
void visualcrypt(){
    string user_input;
    vector<string> user_input_vec;
    cout << ">>> ";
    getline(cin, user_input);

    string delimiter = " ";

    size_t pos;
    string token;
    while ((pos = user_input.find(delimiter)) != string::npos) {
        token = user_input.substr(0, pos);
        user_input_vec.emplace_back(token);
        user_input.erase(0, pos + delimiter.length());
    }
    user_input_vec.emplace_back(user_input);

    if(user_input_vec[0] == "help"){
        cout << "visualcrypt encode <source> <result> <key>" << endl
             << "visualcrypt decode <image_a> <result> <key>" << endl
             << "visualcrypt overlay <image_a> <image_b> <result>" << endl
             << "exit" << endl;
    } else if(user_input_vec[0] == "exit"){
        exit(0);
    } else if ((user_input_vec.size() == 5) && (user_input_vec[0] == "visualcrypt")){
        if (user_input_vec[1] == "encode"){
            CBild crypt = CBild(user_input_vec[4]);
            NBild s_img;
            NBild r_img;
            s_img.import(user_input_vec[2]);
            r_img = crypt.encode(s_img);
            r_img.writeToFile(user_input_vec[3]);
        } else if (user_input_vec[1] == "decode"){
            CBild crypt = CBild(user_input_vec[4]);
            NBild s_img;
            NBild r_img;
            s_img.import(user_input_vec[2]);
            r_img = crypt.decode(s_img);
            r_img.writeToFile(user_input_vec[3]);
        } else if (user_input_vec[1] == "overlay"){
            CBild crypt = CBild("A");
            NBild img1;
            NBild img2;
            NBild r_img;
            img1.import(user_input_vec[2]);
            img2.import(user_input_vec[3]);
            r_img = crypt.overlay(img1, img2);
            r_img.writeToFile(user_input_vec[4]);
        } else {
            cout << "invalid input" << endl;
        }
    } else {
        cout << "invalid input" << endl;
    }
}

int main()
{
    while(true){
        try {
            visualcrypt();
        } catch (int e) {
            if (e == 0){
                cout << "invalid input" << endl;
            } else if (e == 1){
                cout << "input file doesnt exist" << endl;
            } else if (e == 2) {
                cout << "invalid key" << endl;
            }
        }

    }
}


