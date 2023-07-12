#include <iostream>
#include <crtdbg.h>


#include "ProgramOne.cpp"
#include "JDString.h" //program 2
#include "JADString.h" //program 3

using namespace std;


/*I know it's a bit weird to have a test function in the class, but I wanted
to keep the code in the same file for simplicity */

int main() {
    {
        ProgramOne program1;
        // program1.test();

        //JDString program2;    //supposed to have memory leak, prof didn't ask for a destructor yet
         //program2.test(); 

         JADString program3;
         program3.test();

    }
   _CrtDumpMemoryLeaks(); 
}




