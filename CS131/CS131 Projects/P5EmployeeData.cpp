#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

/// <summary>
/// A better version of this can be seen in P6EmployeeData.cpp where I sort using pointers instead to reduce the number of swaps.
/// </summary>

using namespace std;

class EmployeeData {
public:
    EmployeeData() {
        employeeTotalhours = vector<int>();
        employeeNames = vector<string>();
        employeeHours = vector<vector<int>>(0, vector<int>(7)); // 7 days in a week
    }
    
    void organizeData() {
        readHoursFromFile();
        calculateTotalHours();
        bubbleSort();
        printResults();
    }

private:
    void readHoursFromFile() {
        ifstream fin;
        fin.open("empdata4.txt");
        if (fin.fail()) {
            cout << "opening file failed" << endl;
            exit(1);
        }
        char nextChar = ' ';

          while (!fin.eof() && nextChar != '\n') { //skip the first line (we don't need to know the number of employees in the file.)
              nextChar = fin.get();
          }
         
        for (int i = 0; !fin.eof(); i++) {
            if (nextChar == '\n') {
                nextChar = fin.get();
                i--;
                continue;
            } //skip empty lines
            while (!fin.eof() && !isdigit(nextChar)) { //could also do this using ascii values (this will include spaces at end of names)
                if (employeeNames.size() <= i) {
                    employeeNames.push_back("");
                }
                employeeNames[i] += nextChar;
                nextChar = fin.get();
            }

            vector<int> curPersonHours = vector<int>(7);
            for (int j = 0; j < 7 && !fin.eof(); j++) {
                while (isdigit(nextChar)) { 
                    curPersonHours[j] = curPersonHours[j] * 10 + nextChar - '0';   //converts this char to int
                    nextChar = fin.get();
                }
                nextChar = fin.get(); //not a digit
            }
            employeeHours.push_back(curPersonHours);
        }
        fin.close();
    }
    void calculateTotalHours() {
        for (int i = 0; i < employeeHours.size(); i++) {
            int totalHours = 0;
            for (int j = 0; j < employeeHours[i].size(); j++) {
                totalHours += employeeHours[i][j];
            }
            employeeTotalhours.push_back(totalHours);
        }
    }

    void printResults() {
        cout << "Employee Weekly Hours:" << endl;
        cout << setw(20) << left << "Name:" << right << setw(3) << "S" << setw(3) << "M" << setw(3) << "T" << setw(3) << "W" << setw(3) << "T" << setw(3) << "F" << setw(3) << "S" << setw(5) << "TTL" << endl;
        if (employeeTotalhours.size() == employeeNames.size()) {
            for (int i = 0; i < employeeTotalhours.size(); i++) {
                cout << setw(20) << left << employeeNames[i] << right << setw(3) << employeeHours[i][0] << setw(3) << employeeHours[i][1] << setw(3) << employeeHours[i][2] << setw(3) << employeeHours[i][3] << setw(3) << employeeHours[i][4] << setw(3) << employeeHours[i][5] << setw(3) << employeeHours[i][6] << setw(5) << employeeTotalhours[i] << endl;
            }
        }
    }

    void bubbleSort() {
        for (int i = 0; i < employeeTotalhours.size(); i++) {
            for (int j = 0; j < employeeTotalhours.size() - i - 1; j++) {
                if (employeeTotalhours[j] < employeeTotalhours[j + 1]) {
                    swap(employeeTotalhours[j], employeeTotalhours[j + 1]);
                    swap(employeeNames[j], employeeNames[j + 1]);
                    swap(employeeHours[j], employeeHours[j + 1]);
                }
            }
        }
    }
    
    vector<int> employeeTotalhours;
    vector<string> employeeNames;
    vector<vector<int>> employeeHours;

};