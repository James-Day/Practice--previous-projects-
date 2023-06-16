#include <iostream>
#include <fstream>

using namespace std;

class LWSix {
public:
    void copyFile() {
        ifstream fin;
        ofstream fout;
        char ch = ' ';

        fin.open("myFile.txt");
        if (fin.fail()) {
            cout << "opening file failed" << endl;
            exit(1);
        }
        fout.open("backup.txt");
        if (fout.fail()) {
            cout << "opening file failed" << endl;
            exit(1);
        }

        ch = fin.get();
        while (!fin.eof()) {
            fout << ch;
            ch = fin.get();
        }

        fin.close();
        fout.close();
    }
};