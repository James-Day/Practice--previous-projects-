#include <iostream>
using namespace std;

static const double GRAMS_IN_POUND = 453.6;
static const double GRAMS_IN_OUNCE = 28.3495;
/// <summary>
/// rounds to nearest gram
/// 5 Pounds, 4 Ounces = 2 Kilograms, 381 grams
/// 13 Pounds, 11 Ounces = 6 Kilograms, 209 grams
/// </summary>
class WeightConverter {
public:
    void main() {

        int pounds, ounces, grams;

        cout << " Welcome message..........\n";

        pounds = promptAndGetInt("Pounds: ");
        ounces = promptAndGetInt("Ounces: ");
        grams = convertToGrams(pounds, ounces);

        outputResults(pounds, ounces, grams);
    }

    int promptAndGetInt(string promtMessage) {
        int returnVal = 0;
        cout << "please input the number of " << promtMessage;
        cin >> returnVal;
        return returnVal;
    }
    int convertToGrams(int pounds, int ounces) {
        double totalGrams = 0;
        totalGrams += pounds * GRAMS_IN_POUND;
        totalGrams += ounces * GRAMS_IN_OUNCE;

        return (int)(totalGrams + 0.5);
    }
    void outputResults(int pounds, int ounces, int grams) {
        int kiloGrams = grams / 1000;
        grams %= 1000;

        cout << "your input of " << pounds << " Pounds, and " << ounces << " Ounces is equal to " << kiloGrams
            << " Kilograms and " << grams << " Grams";
    }
   

};