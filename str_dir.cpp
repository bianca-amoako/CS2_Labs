//
//  main.cpp
//  cs2_string_dir
//
//  Created by Bianca Amoako on 6/15/23.
//

#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int main() {
    string name = "Bianca Marie Amoako ";
    double length = name.size();
    cout << length << endl;
    
    //using assertion
        //a way to check your orogram is on track
    assert(length == 0); //causes the program to fail
    return 0;
}
