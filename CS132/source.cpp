#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

#include "ProgramOne.cpp"
#include "JDString.h"

using namespace std;


int main() {

   ProgramOne program1;
  // program1.test();

   vector<JDString> strList(100);
   ifstream fin;
   fin.open("infile2.txt");
   ofstream fout;
   fout.open("outfile.txt");
   int wordCount;
   for (wordCount = 0; wordCount < strList.size(); wordCount++) { //Reading file
       if (strList.at(wordCount).read(fin)) {
       }
       else {
           strList.resize(wordCount);
       }
   }
   int words_to_check = wordCount;
   JDString temp;
   for (int inc = 0; inc < wordCount; inc++) {
       for (int i = 0; i < words_to_check - 2; i++) {
           if (strList.at(i).compareTo(strList.at(i + 1)) == 1) { //Bubble Sort
                   temp.setEqualTo(strList.at(i));
               strList.at(i).setEqualTo(strList.at(i + 1));
               strList.at(i + 1).setEqualTo(temp);
           }
       }
       words_to_check--;
   }
   int inc = 1;
   for (int i = 0; i < strList.size(); i++) { //output
       strList.at(i).write(fout);
       if (inc > 5) { //creating a new line every 6 words
           fout << endl;
           inc = 0;
       }
       inc++;
   }
   fin.close();
   fout.close();
   system("pause");
}




