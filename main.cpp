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

    Complex testComplexDouble = Complex(1.1, 1);
    cout << "Test constructeur double = " << testComplexDouble.toString() << endl;

    Complex testComplexString = Complex("1.1+1i");
    cout << "Test constructeur string = " << testComplexString.toString() << endl;

    Complex add = testComplexDouble + testComplexString;
    cout << "Test addition = " << add.toString() << endl;

    Complex min = testComplexDouble - testComplexString;
    cout << "Test soustraction = " << min.toString() << endl;

    Complex time = Complex(-3, 1) * Complex(2, 5);
    cout << "Test multiplication = " << time.toString() << endl;

    Complex division = Complex(1, 2) / Complex(3, -1);
    cout << "Test division = " << division.toString() << endl;
    division.humanReadable();

    double module = Complex(3, -5).module();
    cout << module << endl;

    Complex opposé = Complex(2, -6).opposé();
    cout << opposé.toString() << endl;

    Complex inverse = Complex(3, -5).inverse();
    cout << inverse.toString() << endl;

    /** Permet uniquement d'empécher le programme de se fermer */
    int stopQuit;
    cin >> stopQuit;
    return 0;
}
