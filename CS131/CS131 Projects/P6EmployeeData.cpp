#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

class EmployeeDataV2 {
public:
    EmployeeDataV2() {
        employees = vector<Employee *>();
    }

    void organizeData() {
        readHoursFromFile();
        calculateTotalHours();
        bubbleSort();
        printResults();
    }

private:
    struct Employee {
        string name;
        vector<int> hours;
        int totalHrs;

        Employee(const string& name, const vector<int>& hours, int totalHrs)
            : name(name), hours(hours), totalHrs(totalHrs)
        {
        }
    };
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
            string curEmployeeName = "";
            while (!fin.eof() && !isdigit(nextChar)) { //could also do this using ascii values (this will include spaces at end of names)
                 curEmployeeName += nextChar;
                nextChar = fin.get();
            }

            vector<int> curEmployeeHours = vector<int>(7);
            for (int j = 0; j < 7 && !fin.eof(); j++) {
                while (isdigit(nextChar)) {
                    curEmployeeHours[j] = curEmployeeHours[j] * 10 + nextChar - '0';   //converts this char to int
                    nextChar = fin.get();
                }
                nextChar = fin.get(); //not a digit
            }
            Employee* curEmployee = new Employee(curEmployeeName, curEmployeeHours, 0);
          employees.push_back(curEmployee);
        }
        fin.close();
    }
    void calculateTotalHours() {
        for (int i = 0; i < employees.size(); i++) {
            int totalHours = 0;
            for (int j = 0; j < employees[i]->hours.size(); j++) {
                totalHours += employees[i]->hours[j];
            }
            employees[i]->totalHrs = totalHours;
        }
    }

    void printResults() {
        cout << "Employee Weekly Hours:" << endl;
        cout << setw(20) << left << "Name:" << right << setw(3) << "S" << setw(3) << "M" << setw(3) << "T" << setw(3) << "W" << setw(3) << "T" << setw(3) << "F" << setw(3) << "S" << setw(5) << "TTL" << endl;
            for (int i = 0; i < employees.size(); i++) {
                cout << setw(20) << left << employees[i]->name << right;
                for (int j = 0; j < employees[i]->hours.size(); j++) {
                    cout << setw(3) << employees[i]->hours[j];
                }
                cout << setw(5) << employees[i]->totalHrs;
                cout << endl;
            }
    }

    void bubbleSort() {
        for (int i = 0; i < employees.size() - 1; i++) {
            for (int j = 0; j < employees.size() - i - 1; j++) {
                if (employees[j]->totalHrs < employees[j + 1]->totalHrs) {
                    Employee* temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    vector<Employee*> employees;
};