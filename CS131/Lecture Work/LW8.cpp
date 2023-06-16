#include <iostream>
using namespace std;

class LWEight {
public:

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void bubbleSort(int arr[], int size) { //same as bubbleSort(int *arr)
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    void test() {
        int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
        int b[10] = { 9,8,7,6,5,4,3,2,1,0 };
        int c[10] = { 1,5,4,3,6,0,9,2,8,7 };

        bubbleSort(a, 10);
        bubbleSort(b, 10);
        bubbleSort(c, 10);

        for (int i = 0; i < 10; i++) {
            if (a[i] != i || b[i]!= i || c[i] != i) {
                cout << "Something is wrong with your sorting function." << endl;
            }
        }

    }
};

