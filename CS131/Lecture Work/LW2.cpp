#include <iostream>
using namespace std;

class LWTwo {
public:
    void PrintGrid(){
       
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                cout << i << "," << j << " ";
            }
            cout << endl;
        }
    }
};