#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

#define groupCSV 27;



int main(int argc, char* argv[]) {
    int* xArray = new int(1000000000);
    int* yArray = new int(1000000000);

    string data;
    ifstream infile(argv[1], ios::in);
    if (!infile) {
        cerr << "Cannot open file.\n";
    }
    int cur = 0;
    int arraySize = 0;
    while (getline(infile, data, ',')) {
        if (data == "x" || data == "y") continue;
        if (cur % 2 == 0) {
            xArray[cur] = stoi(data);
        }
        else {
            yArray[cur] = stoi(data);
        }
        cur++;
        arraySize++;
    }

    for (int i = 0; i < arraySize; i++) {
        cout << xArray[i];
    }
    
    return 0;   
}