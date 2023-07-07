#pragma once
#include <iostream>
using namespace std;

class JDString {
public:
    JDString();
    JDString(const char*);
    int length() const;
    int capacity() const;
    char at(int index) const;
    bool read(istream& istrm);
    void write(ostream& ostream) const;
    int compareTo(const JDString& argStr) const;
    const char* c_str() const;
    void setEqualTo(const JDString& argStr);

private:
    char* str;
    int cap;
    int end; //index of the last character in the string (the null terminator)
};