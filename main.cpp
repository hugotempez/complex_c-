#include <iostream>
#include <string>
#include "Complexe.h"


using namespace std;


void info() {
    cout << "Concernant le constructeur prenant un string en paramétre :" << endl;
    cout << "\t- La virgule doit être représenté par un point UNIQUEMENT." << endl;
    cout << "\t- le \"i\" de le partie imaginaire peut être placé aprés l'operateur ou a la fin de la partie imaginaire" << endl;
    cout << "\n";
}


int main() {
    info();
    Complex testComplexDouble = Complex(1.1, -2.1);
    testComplexDouble.humanReadable();

    Complex testComplexString = Complex("8.1+3.9i");
    testComplexString.humanReadable();

    Complex add = testComplexDouble + testComplexString;
    add.humanReadable();

    Complex min = testComplexDouble - testComplexString;
    min.humanReadable();

    /** Permet uniquement d'empécher le programme de se fermer */
    int stopQuit;
    cin >> stopQuit;
    return 0;
}
