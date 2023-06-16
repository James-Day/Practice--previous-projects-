#include <iostream>
using namespace std;

class LWThree {
public:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    double max(double a, double b) {
        return a > b ? a : b;
    }

    string max(string a, string b) {
        return a.size() > b.size() ? a : b;
    }

    void testOverLoad() {
        cout << max(2, 2) << endl;
        cout << max(1, 2) << endl;
        cout << max(3, 2) << endl;
        cout << max(2, 4) << endl;
        cout << max(2.01, 2.01) << endl;
        cout << max(1.01, 2.05) << endl;
        cout << max(3.07, 2.02) << endl;
        cout << max(2.82, 4.05) << endl;
        cout << max("b", "1") << endl;
        cout << max("abc", "bcdas") << endl;
        cout << max("abd", "mn") << endl;
        cout << max("lm", "1235") << endl;
    }
};