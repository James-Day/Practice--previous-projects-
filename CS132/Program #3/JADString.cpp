#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

#include "JADString.h"

using namespace std;

int JADString::currentCount = 0;
int JADString::createdCount = 0;

JADString::JADString() {
    cap = 20;
    str = new char[cap];
    end = 0;
    str[0] = '\0';
    currentCount++;
    createdCount++;
}

JADString::JADString(const JADString& mstr)
{
    currentCount++;
    createdCount++;
    cap = mstr.cap;
    str = new char[(cap / 20) + 1];
    for (int i = 0; i < mstr.end; i++) {
        str[i] = mstr.str[i];
    }
    end = mstr.end;
}

JADString::JADString(const char* input) { 
    cap = 20;
    str = new char[cap];
    int i = 0;
    for (; input[i] != '\0'; i++) {
        if (i % 20 == 0) {
            cap += 20;
            char* temp = new char[cap];
            for (int j = 0; j < i; j++) {
                temp[j] = str[j];
            }
            delete[] str;
            str = temp;
        }
        str[i] = input[i];
    }
    end = i;
    str[end] = '\0';
    currentCount++;
    createdCount++;
}

JADString::~JADString()
{
        currentCount--;
        delete[] str;
}

JADString& JADString::operator=(const JADString& argStr)
{
    delete str;
    cap = argStr.cap;
    end = argStr.end;
    str = new char[(cap / 20) + 1];
    for (int i = 0; i < argStr.end; i++) {
        str[i] = argStr.str[i];
    }
    return *this;
}

char& JADString::operator[](int index)
{
    return str[index];
}

bool JADString::operator<(const JADString& argStr) const
{
    for (int i = 0; i < cap && i < argStr.cap; i++) {
        if (str[i] < argStr.str[i]) {
            return true;
        }
    }
    return cap < argStr.cap;
}

bool JADString::operator>(const JADString& argStr) const
{
    for (int i = 0; i < cap && i < argStr.cap; i++) {
        if (str[i] > argStr.str[i]) {
            return true;
        }
    }
    return cap > argStr.cap;
}

bool JADString::operator==(const JADString& argStr) const
{
    for (int i = 0; i < cap && i < argStr.cap; i++) {
        if (str[i] != argStr.str[i]) {
            return false;
        }
    }
    return cap == argStr.cap;
}

JADString JADString::operator+(const JADString& argStr)
{
    char* temp = new char[cap];
    for (int i = 0; i < end; i++) {
        temp[i] = str[i];
    }
    delete[] str;
    str = new char[((cap + argStr.cap)/20) + 1];
    for (int i = 0; i < end; i++) {
        str[i] = temp[i];
    }
    for (int i = end; i < (argStr.end + end); i++) {
        str[i] = argStr.str[i];
    }
    end += argStr.end;
    str[end] = '\0';
    cap = (cap + argStr.cap);
    return *this;
}


int JADString::length() const {
    return end;
}

int JADString::capacity() const {
    return cap;
}

char JADString::at(int index) const {
    if (index >= end || index < 0) {
        return '\0';
    }
    return str[index];
}

const char* JADString::c_str() const
{
    return str;
}

int JADString::getCurrentCount()
{
    return currentCount;
}

int JADString::getCreatedCount()
{
    return createdCount;
}

void test() { // TODO this needs to be updated for the new JADString
  
};

istream& operator>>(istream& istrm, JADString& argStr) //fix this in the morning
{
    char temp[100];
    if (istrm >> temp) {
        int i = 0;
        for (; temp[i] != '\0'; i++) {
            if (argStr.cap == argStr.end + i) {
                argStr.cap += 20;
                char* temp = new char[argStr.cap];
                for (int j = 0; j < i; j++) {
                    temp[j] = argStr.str[j];
                }
                delete[] argStr.str;
                argStr.str = temp;
            }
            argStr.str[i] = temp[i];
        }
        argStr.end = i;
        argStr.str[argStr.end] = '\0';
        return istrm;
    }
    return istrm;
}

ostream& operator<<(ostream& ostrm, const JADString& argStr)
{
    ostrm << setw(13);
    ostrm << argStr.str; //do I need to convert this to a c_str? (only if I don't want it to be a friend?)
}
