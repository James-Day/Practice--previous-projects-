#include <iostream>
using namespace std;

class ProgramOne {
public:
    void test() {
        char str1[] = "batman";
        char str2[] = "cat";
        char str3[] = "cast";
        char str4[] = "catagory";
        char str5[] = "ZIP";

        cout << "batman " << length(str1) << endl;
        cout << "cat " << length(str2) << endl;

        cout << "comparing " << str1 << " & " << str2 << " " << compareTo(str1, str2) << endl;
        cout << "comparing " << str2 << " & " << str1 << " " << compareTo(str2, str1) << endl;

        cout << "comparing " << str3 << " & " << str2 << " " << compareTo(str3, str2) << endl;
        cout << "comparing " << str2 << " & " << str3 << " " << compareTo(str2, str3) << endl;

        cout << "comparing " << str4 << " & " << str2 << " " << compareTo(str4, str2) << endl;
        cout << "comparing " << str2 << " & " << str4 << " " << compareTo(str2, str4) << endl;

        cout << "comparing " << str2 << " & " << str2 << " " << compareTo(str2, str2) << endl;

        cout << "comparing " << str2 << " & " << str5 << " " << compareTo(str2, str5) << endl;    
    }
    int compareTo(const char* lstr, const char* rstr)
    {
        int lstrLength = length(lstr);
        int rstrLength = length(rstr);
        for (int i = 0; i < lstrLength && i < rstrLength; i++) {
            if (lstr[i] < rstr[i]) { // we can also acess the cstring like *lstr and lstr++
                return -1;
            }
            else if (lstr[i] > rstr[i]) {
                return 1;
            }
        }
        if (lstrLength < rstrLength) {
            return -1;
        }
        else if (lstrLength > rstrLength) {
            return 1;
        }
        return 0;

    }
    int length(const char* str) {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }
};