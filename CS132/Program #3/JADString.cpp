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
    str = new char[((mstr.cap / 20) + 1) * 20];
    for (int i = 0; i <= mstr.end; i++) {
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
    if (this != &argStr) {
        delete[] str;
        cap = argStr.cap;
        end = argStr.end;
        str = new char[argStr.cap];
        for (int i = 0; i <= argStr.end; i++) {
            str[i] = argStr.str[i];
        }
    }
    return *this;
}

char& JADString::operator[](int index)
{
    return str[index];
}

bool JADString::operator<(const JADString& argStr) const
{
    for (int i = 0; i < end && i < argStr.end; i++) {
        if (str[i] < argStr.str[i]) {
            return true;
        }
        else if (str[i] != argStr.str[i]) {
            return false;
        }
    }
    return cap < argStr.cap;
}

bool JADString::operator>(const JADString& argStr) const
{
    for (int i = 0; i < end && i < argStr.end; i++) {
        if (str[i] > argStr.str[i]) {
            return true;
        }
        else if (str[i] != argStr.str[i]) {
            return false;
        }
    }
    return cap > argStr.cap;
}

bool JADString::operator==(const JADString& argStr) const
{
    for (int i = 0; i < end && i < argStr.end; i++) {
        if (str[i] != argStr.str[i]) {
            return false;
        }
    }
    return cap == argStr.cap;
}

JADString JADString::operator+(const JADString& argStr)
{
    JADString copy;
    delete[] copy.str;
    copy.cap = (((end + argStr.end) / 20) + 1) * 20;
    copy.str = new char[copy.cap];
    for (int i = 0; i < end; i++) {
        copy.str[i] = str[i];
    }
    for (int i = end; i < (argStr.end + end); i++) {
        copy.str[i] = argStr.str[i - end];
    }
    copy.end = argStr.end + end;
    copy.str[copy.end] = '\0';
    return copy;
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



istream& operator>>(istream& istrm, JADString& argStr) //could be better for memory optimization, but it should be fine for now
{
    char temp[100];
    if (istrm >> temp) {
        int i = 0;
        for (; temp[i] != '\0'; i++) {
            if (i >= argStr.cap) {
                    argStr.cap += 20;
                    char* temp2 = new char[argStr.cap];
                    for (int j = 0; j < i; j++) {
                        temp2[j] = argStr.str[j];
                    }
                    delete[] argStr.str;
                    argStr.str = temp2;
                }
                argStr.str[i] = temp[i];
        }
        argStr.end = i;
        argStr.str[argStr.end] = '\0';
    }
    return istrm;
}

ostream& operator<<(ostream& ostrm, const JADString& argStr)
{
    ostrm << argStr.str; //do I need to convert this to a c_str? (only if I don't want it to be a friend?)
    return ostrm;
}

void JADString::test() {
    {
        vector<JADString> strList(10);
        vector<JADString> jumboList(0);
        ifstream fin;
        fin.open("infile3.txt");
        if (fin.fail())
        {
            cout << "Couldn't open infile3.txt" << endl;
            system("pause");
            exit(1);
        }
        ofstream fout;
        fout.open("outfile2.txt");
        int jumb_inc = 0;
        while (!fin.eof()) {
            int wordCount;
            for (wordCount = 0; wordCount < 5 && !fin.eof(); ++wordCount) {
                fin >> strList[wordCount];
            }
            
            JADString JumboWord;
            for (int i = 0; i < wordCount; i++) {
                JumboWord = JumboWord + strList[i];
            }

            jumboList.push_back(JumboWord);

            cout << jumboList[jumb_inc] << endl;
            jumb_inc++;
            wordCount = 0;
            
        }
        JADString temp;

        
        //bubble sort  
        for (int i = 0; i < jumboList.size() - 1; i++) {
            for (int j = 0; j < jumboList.size() - i - 1; j++) {
                if (jumboList[j] > jumboList[j + 1]) {
                    temp = jumboList[j];
                    jumboList[j] = jumboList[j + 1];
                    jumboList[j + 1] = temp;
                }
            }
        }
        


        for (int i = 0; i < jumboList.size(); i++) { //OUTPUT

            fout << setw(40) << left << jumboList[i] << jumboList[i].capacity() << ":" << jumboList[i].length() << endl;
        }
        
        fin.close();
        fout.close();
        cout << endl << getCurrentCount() << endl << getCreatedCount() << endl;

    }
    cout << endl << getCurrentCount() << endl << getCreatedCount() << endl;
};
