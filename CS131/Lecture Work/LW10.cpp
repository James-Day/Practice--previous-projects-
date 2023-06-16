#include <iostream>
using namespace std;
const static int CLASS_SIZE = 30;
const static int NUM_CLASSES = 6;
class LWTen {
    
public:
    void calculateClassAverage(int arr[][CLASS_SIZE], int numberClasses) {
        double highestAverage = 0;
        int highestClassNumber = -1;
        for (int i = 0; i < NUM_CLASSES; i++) {
            int total = 0;
            for (int j = 0; j < CLASS_SIZE; j++) {
                total += arr[i][j];
            }
            if (highestAverage < (double)total / CLASS_SIZE) {
                highestAverage = (double)total / CLASS_SIZE;
                highestClassNumber = i;
            }
            cout << "Class " << i << "'s average: " << (double)total / CLASS_SIZE << "%" << endl;
        }
        cout << "The class with the highest average is class #" << highestClassNumber << " with a average of: " << highestAverage << "%" << endl;
    }

    void test() {
        int TWODarr[6][CLASS_SIZE] = { { 0 } };
        for (int (&arra)[30] : TWODarr) {
            for (int &score: arra) {
                score = rand() % 46 + 55;
            }
        }

        calculateClassAverage(TWODarr, NUM_CLASSES);
    }

};