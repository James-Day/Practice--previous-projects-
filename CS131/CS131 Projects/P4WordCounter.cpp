#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
//it is intended that words with a period at the end will be counted as a word with the period included. ex: pizza. = 6 letters
//I also just realized, that fin >> string will automatically skip spaces and read words at a time which would have made this much easier, but it's good enough for now.

class WordLengthCounter { //Still need to surround this in a while loop to continually do this.
public:
    void test() {
        int totalWords = 0;
        string testFile = "";
        string currentWord = "";
        char currentLetter = ' ';
        unordered_map<int, int> lookup;
        cout << "Please enter the name of the file you'd like to test: ";
        cin >> testFile;
        ifstream fin;
        ofstream fout;
        fin.open(testFile);
        if (fin.fail()) {
            cout << "opening file failed" << endl;
            exit(1);
        }
        while (!fin.eof()) {
            while (!fin.eof() && currentLetter != ' ' && currentLetter != '\n') {
                currentWord += currentLetter;
                currentLetter = fin.get();
            }

            if (currentWord.length() <= 8 && currentWord != "\n" && currentWord != "" && currentWord != " ") { //will count \n as a word but I will change this later
                lookup[currentWord.length()]++;
                totalWords++;
            }
            else if (currentWord.length() > 8) {
                lookup[9]++; //any words longer than 8 characters
                totalWords++;
            }

            if (!fin.eof()) {
                currentLetter = fin.get();
                currentWord = "";
            }
        }
        fin.close();

        cout << "Length:    Count:" << endl;
        for (int i = 1; i <= 8; i++) {
            cout << i << "      " << lookup[i] << endl;
        }
        cout << ">8" << "     " << lookup[9] << endl;
        cout << "Total words in the file: " << totalWords;
    }
};