#include <iostream>
#include <string>
#include "Complexe.h"


using namespace std;


void info() {
    cout << "!!!!!!!!!!!!!!!! INFO !!!!!!!!!!!!!!!!" << endl;
    cout << "Les accents sont absents car ne s'affichant pas correctement." << endl;
    cout << "Concernant le constructeur prenant un string en parametre :" << endl;
    cout << "\t- la virgule doit etre represente par un point UNIQUEMENT." << endl;
    cout << "\t- le \"i\" de le partie imaginaire doit etre place a la fin de cette partie imaginaire" << endl;
    cout << "\n";
}


string saisie() {
    string c;
    cout << "Saisissez un complexe valide : ";
    cin >> c;
    return c;
}


int calcul() {
    string c1string = saisie();
    int choice = 0;
    cout << "Saisissez le chiffre associe a l'operateur desire : " << endl;
    cout << "\t1. +" << "\n" << "\t2. -" << "\n" << "\t3. *" << "\n" << "\t4. /" << endl;
    cout << "Votre choix : ";
    try {
        cin >> choice;
    } catch (...) {
        cout << "Votre saisie n'est pas au format escompte (1, 2, 3 ou 4 uniquement)" << endl;
        return -1;
    }
    string c2string = saisie();
    switch (choice) {
        case 1:
            cout << "\n" << "(" << c1string << ")" << " + " << "(" << c2string << ")" << " = ";
            cout << Complex(Complex(c1string) + Complex(c2string)).toString() << "\n"  << endl;
            cout << "Retour au menu principal." << "\n" << endl;
            return 0;
        case 2:
            cout << "\n" << "(" << c1string << ")" << " - " << "(" << c2string << ")" << " = ";
            cout << Complex(Complex(c1string) - Complex(c2string)).toString() << "\n"  << endl;
            cout << "Retour au menu principal." << "\n" << endl;
            return 0;
        case 3:
            cout << "\n" << "(" << c1string << ")" << " * " << "(" << c2string << ")" << " = ";
            cout << Complex(Complex(c1string) * Complex(c2string)).toString() << "\n"  << endl;
            cout << "Retour au menu principal." << "\n" << endl;
            return 0;
        case 4:
            cout << "\n" << "(" << c1string << ")" << " / " << "(" << c2string << ")" << " = ";
            cout << Complex(Complex(c1string) / Complex(c2string)).toString() << "\n"  << endl;
            cout << "Retour au menu principal." << "\n" << endl;
            return 0;
        default:
            cout << "Choix non reconnu, retour au menu principal" << "\n" << endl;
            return -1;
    }
}


void menu() {
    while (true) {
        int choice = 0;
        cout << "Choisissez l'operation a effectuer :" << endl;
        cout << "\t1. Calcul Arithmetique." << "\n" << "\t2. Conjugue." << "\n" <<  "\t3. Module." << endl;
        cout << "\t4. Oppose." << "\n" << "\t5. Inverse." << "\n" << "\t6. Tests" << "\n" << "Votre choix : " << endl;
        try {
            cin >> choice;
        } catch (...) {
            cout << "Votre saisie n'est pas au format escompte (1, 2, 3, 4 ou 5 uniquement)" << endl;
            choice = 0;
        }
        system("cls");
        switch (choice) {
            case 1:
                calcul();
                break;
            case 2:
                cout << Complex(saisie()).conjugue().toString() << endl;
                break;
            case 3:
                cout << Complex(saisie()).module() << endl;
                break;
            case 4:
                saisie();
                cout << Complex(saisie()).oppose().toString() << endl;
                break;
            case 5:
                saisie();
                cout << Complex(saisie()).inverse().toString() << endl;
                break;
            case 6:
            {
                Complex comp = Complex(saisie());
                cout << "partie reel = " << comp.getReal() << "\n" << "partie imaginaire = " << comp.getImaginary() << endl;
                cout << comp.toString() << endl;
                break;
            }
            default:
                cout << choice << " n'est pas un nombre valide dans ce menu, veuillez recommencer votre saisie.\n" << endl;
                menu();
                break;
        }
    }
}


int main() {
    info();
    menu();
    return 0;
}