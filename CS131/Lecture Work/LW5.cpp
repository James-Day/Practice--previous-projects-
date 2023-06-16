#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class LWFive {
public:
    void readFromFile(){
        ifstream fin;

        int curNum = 0;
        int totalNum = 0;
        fin.open("myFile.txt");
        if (fin.fail()) {
            cout << "opening file failed" << endl;
            exit(1);
        }
        while (!fin.eof()) {
           fin >> curNum;
           if (!fin.eof()) {
               totalNum += curNum;
           }
        } 
        fin.close();
        cout << "Total: " << totalNum << endl;
    }
};