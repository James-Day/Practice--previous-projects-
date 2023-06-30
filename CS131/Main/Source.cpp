#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <crtdbg.h>

#include "LW1.cpp"
#include "LW1.5.cpp"
#include "LW3.5.cpp"
#include "LW2.cpp"
#include "LW3.cpp"
#include "LW4.cpp"
#include "LW5.cpp"
#include "LW6.cpp"
#include "LW7.cpp"
#include "LW8.cpp"
#include "LW9.cpp"
#include "LW10.cpp"
#include "LW11.cpp"



#include "P1ChangeMachine.cpp"
#include "P2DiceGame.cpp"
#include "P2.5NumberDiamond.cpp"
#include "P3WeightConverter.cpp"
#include "P4WordCounter.cpp"
#include "P5EmployeeData.cpp"
#include "P6EmployeeData.cpp"


using namespace std;

int main() {
    /*cout << "LW1" << endl;
    LWOne lecture1Ass = LWOne();
    lecture1Ass.PrintRandomNums();

    cout << "LW1.5" << endl;
    LWonePFive lecture1P5Ass = LWonePFive();
    lecture1P5Ass.test();

    cout << endl << "LW2" << endl;
    LWTwo lecture2Ass = LWTwo();
    lecture2Ass.PrintGrid();

    cout << endl << "LW3" << endl;
    LWThree lecture3Ass = LWThree();
    lecture3Ass.testOverLoad();

    cout << "LW3.5" << endl;
    LWThreePFive lecture3P5Ass = LWThreePFive();
    lecture3P5Ass.printBanner("I love my job!");
    lecture3P5Ass.printBanner("I hate my job!", '-');
    lecture3P5Ass.printBanner("I dont know how I feel about my job!", '.', 5, 80);


    cout << endl << "LW4" << endl;
    LWFour lecture4Ass = LWFour();
    lecture4Ass.testSort();
    
    cout << endl << "LW5" << endl;
    LWFive lecture5Ass = LWFive();
    lecture5Ass.readFromFile();

    cout << endl << "LW6" << endl;
    LWSix lecture6Ass = LWSix();
    lecture6Ass.copyFile();

    cout << endl << "LW7" << endl;
    LWSeven lecture7Ass = LWSeven();
    lecture7Ass.RandomNums();

    cout << endl << "LW8" << endl;
    LWEight lecture8Ass = LWEight();
    lecture8Ass.test();

    cout << endl << "LW9" << endl;
    LWNine lecture9Ass = LWNine();
    lecture9Ass.test();

    cout << endl << "LW10" << endl;
    LWTen lecture10Ass = LWTen();
    lecture10Ass.test();

    cout << endl << "LW11" << endl;
    LWEleven lecture11Ass = LWEleven();
    lecture11Ass.test();
    */
    
    cout << endl << "Program #1" << endl;
    ChangeMachine machineOne = ChangeMachine();
   // machineOne.test();

    cout << endl << "Program #2" << endl;   
    DiceGame diceGameOne = DiceGame();
    //diceGameOne.playGame();

    

    cout << endl << "Program 2.5" << endl;
    NumberDiamond numberDiamondOne = NumberDiamond();
    numberDiamondOne.printDiamond(2);
    numberDiamondOne.printDiamond(5);
    numberDiamondOne.printDiamond(9);

    cout << endl << "Program 3" << endl;
    WeightConverter weightConverterOne = WeightConverter();
    //weightConverterOne.main();

    cout << endl << "Program 4" << endl;
    WordLengthCounter WordCounterOne = WordLengthCounter();
    //WordCounterOne.test();

    {
    cout << endl << "Program 5" << endl;
    EmployeeData employeeDataOne = EmployeeData();
    employeeDataOne.organizeData();

    
    cout << endl << "Program 6" << endl;
    EmployeeDataV2 employeeDataTwo = EmployeeDataV2();
     employeeDataTwo.organizeData(); 
    }
    _CrtDumpMemoryLeaks(); //no memory leak for program #6 (and technically program 5 because it uses vectors.)
}
