#include <iostream>
#include <iomanip>
#include "JDString.h"
using namespace std;

JDString::JDString() {
    cap = 20;
    str = new char[cap];
    end = 0;
    str[0] = '\0';
}

JDString::JDString(const char* input) {
    cap = 20;
    str = new char[cap];
    int i = 0;
    for (; input[i] != '\0'; i++) {
        str[i] = input[i];
    }
    end = i;
    str[end] = '\0';
}

int JDString::length() const {
    return end;
}

int JDString::capacity() const {
    return cap;
}

char JDString::at(int index) const {
    if (index >= end || index < 0) {
        return '\0';
    }
    return str[index];
}

bool JDString::read(istream& istrm) 
{
    char temp[100];
    if (istrm >> temp) {
        int i = 0;
        for (; temp[i] != '\0'; i++) { 
            str[i] = temp[i];
        }
        end = i;
        str[end] = '\0';
        return true;
    }
    return false;
}

void JDString::write(ostream& ostream) const
{
    ostream << setw(13);
    ostream << str;
}

int JDString::compareTo(const JDString& argStr) const
{
    int thisLength = end;
    int argLength = argStr.length();
    for (int i = 0; i < thisLength && i < argLength; i++) {
        if (str[i] < argStr.at(i)) { // we can also acess the cstring like *lstr and lstr++
            return -1;
        }
        else if (str[i] > argStr.at(i)) {
            return 1;
        }
    }
    if (thisLength < argLength) {
        return -1;
    }
    else if (thisLength > argLength) {
        return 1;
    }
    return 0;
}

const char* JDString::c_str() const
{
    return str;
}

void JDString::setEqualTo(const JDString& argStr)
{   
    int i = 0;
    for (; argStr.at(i) != '\0'; i++) {
        str[i] = argStr.at(i);
    }
    end = i;
    str[i] = '\0';
}
