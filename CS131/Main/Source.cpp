#include <iostream>
#include <cstdlib>
#include <time.h>
#include "LW1.cpp"
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


using namespace std;

int main() {
    cout << "LW1" << endl;
    LWOne lecture1Ass = LWOne();
    lecture1Ass.PrintRandomNums();

    cout << endl << "LW2" << endl;
    LWTwo lecture2Ass = LWTwo();
    lecture2Ass.PrintGrid();

    cout << endl << "LW3" << endl;
    LWThree lecture3Ass = LWThree();
    lecture3Ass.testOverLoad();

    cout << endl << "LW4" << endl;
    LWFour lecture4Ass = LWFour();
    lecture4Ass.testSort();

    cout << endl << "Program #1" << endl;
    ChangeMachine machineOne = ChangeMachine();
    machineOne.test();

    cout << endl << "Program #2" << endl;
    DiceGame diceGameOne = DiceGame();
    //diceGameOne.playGame();

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
}