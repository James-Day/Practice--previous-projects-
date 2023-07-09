#pragma once
#include <iostream>
using namespace std;

class JADString {
public:
    JADString();
    JADString(const JADString& mstr);
    JADString(const char*);
    ~JADString();
    JADString& operator = (const JADString& argStr);
    char& operator[](int index);
    friend istream& operator >> (istream& istrm, JADString& argStr);
    friend ostream& operator << (ostream& ostrm, const JADString& argStr);
    bool operator < (const JADString& argStr)const;
    bool operator > (const JADString& argStr)const;
    bool operator == (const JADString& argStr)const;
    JADString operator+ (const JADString& argStr);
    int length() const;
    int capacity() const;
    char at(int index) const;
    const char* c_str() const;
    static int getCurrentCount();
    static int getCreatedCount();

    void test() {};

private:
    static int createdCount;
    static int currentCount;
    char* str;
    int cap;
    int end; //index of the last character in the string (the null terminator)
};