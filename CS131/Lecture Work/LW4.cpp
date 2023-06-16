#include <iostream>
using namespace std;

class LWFour {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void sort(int &a, int &b, int &c) {
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
    }

    void testSort() {
        //TEST 1
        int a = 1;
        int b = 2;
        int c = 3;

        sort(a,b,c);
        if (a == 1 && b == 2 && c == 3) {
        cout << "Test 1 Passed" << endl;
        }

        //Test 2
        a = 1;
        b = 3;
        c = 2;

        sort(a, b, c);
        if (a == 1 && b == 2 && c == 3) {
            cout << "Test 2 Passed" << endl;
        }

        //Test 3
        a = 2;
        b = 1;
        c = 3;

        sort(a, b, c);
        if (a == 1 && b == 2 && c == 3) {
            cout << "Test 3 Passed" << endl;
        }

        //Test 4
        a = 2;
        b = 3;
        c = 1;

        sort(a, b, c);
        if (a == 1 && b == 2 && c == 3) {
            cout << "Test 4 Passed" << endl;
        }

        //Test 5
        a = 3;
        b = 1;
        c = 2;

        sort(a, b, c);
        if (a == 1 && b == 2 && c == 3) {
            cout << "Test 5 Passed" << endl;
        }

        //Test 5
        a = 3;
        b = 2;
        c = 1;

        sort(a, b, c);
        if (a == 1 && b == 2 && c == 3) {
            cout << "Test 5 Passed" << endl;
        }
    }
};