#include <iostream>
#include <vector>
using namespace std;
const static int CLASS_SIZE = 30;
const static int NUM_CLASSES = 6;

class LWEleven {
public:
   
    void calculateClassAverage(vector<vector<int>> TWODVec) {
        double highestAverage = 0;
        int highestClassNumber = -1;
        for (int i = 0; i < TWODVec.size(); i++) {
            int total = 0;
            for (int j = 0; j < TWODVec[i].size(); j++) {
                total += TWODVec.at(i).at(j);
            }
            if (highestAverage < (double)total / TWODVec[i].size()) {
                highestAverage = (double)total / TWODVec[i].size();
                highestClassNumber = i;
            }
            cout << "Class " << i << "'s average: " << (double)total / TWODVec[i].size() << "%" << endl;
        }
        cout << "The class with the highest average is class #" << highestClassNumber << " with a average of: " << highestAverage << "%" << endl;
    }

    void test() {
        vector<vector<int>> TWODvec;
        for (int i = 0; i < NUM_CLASSES; i++) {
            vector<int> innerVector; //Could also just initialize the 2D vector to a size of six, but this method seems more general
            TWODvec.push_back(innerVector);
            for (int j = 0; j < CLASS_SIZE; j++) {
                TWODvec[i].push_back(rand() % 46 + 55);
            }
        }

        calculateClassAverage(TWODvec);
    }
     
};