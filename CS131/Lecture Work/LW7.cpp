#include <iostream>
using namespace std;

class LWSeven {
public:
    void RandomNums() {
        int arr[11] = {0};

        for (int i = 0; i < 10000; i++) {
            arr[(rand() % 10 + 1)]++;
        }
        for (int i = 1; i < 11; i++) {
            cout << i << "'s: " << arr[i] << endl;
        }
    }
};