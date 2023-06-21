#include <iostream>
using namespace std;

class LWThreePFive {
public:
    void printBanner(string msg, char ch = '~', int hdFtLines = 3, int width = 60) {
        printHalfBanner(ch, hdFtLines, width);
        cout << "                    " << msg << endl;
        printHalfBanner(ch, hdFtLines, width);
    }

private:
    void printHalfBanner(char ch, int hdFtLines, int width) {
        for (int i = 0; i < hdFtLines; i++) {
            for (int j = 0; j < width; j++) {
                cout << ch;
            }
            cout << endl;
        }
    }

};