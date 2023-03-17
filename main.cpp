#include <iostream>
#include <string>
#include "Complexe.h"


using namespace std;


/**
 * @brief Print des informations générales sur l'utilisation et la visualisation du programme.
 */
void info() {
    cout << "!!!!!!!!!!!!!!!! INFO !!!!!!!!!!!!!!!!" << endl;
    cout << "Les accents sont absents car ne s'affichant pas correctement." << endl;
    cout << "Concernant le constructeur prenant un string en parametre :" << endl;
    cout << "\t- la virgule doit etre represente par un point UNIQUEMENT." << endl;
    cout << "\t- le \"i\" de le partie imaginaire doit etre place a la fin de cette partie imaginaire" << endl << endl;
}


/**
 * @brief Permet à l'utilisateur de saisir un double.
 * @return Le double saisie par l'utilisateur.
 */
double saisieDouble() {
    double r;
    cout << "Saisissez un double valide : ";
    cin >> r;
    return r;
}


/**
 * @brief Permet à l'utilisateur de saisir un nombre complexe.
 * @return La saisie de l'utilisateur.
 */
string saisieComplexe() {
    string c;
    cout << "Saisissez un complexe valide : ";
    cin >> c;
    return c;
}


/**
 * @brief Permet à l'utilisateur de faire du calcul arithmétique complexe.
 * @return 0 si le calcul s'est bien passé ou -1 dans le cas contraire.
 */
int calcul() {
    try {
        string c1string = saisieComplexe();
        int choice = 0;
        cout << "Saisissez le chiffre associe a l'operateur desire : " << endl;
        cout << "\t1. +" << "\n" << "\t2. -" << "\n" << "\t3. *" << "\n" << "\t4. /" << endl;
        cout << "Votre choix : ";
        cin >> choice;
        string c2string = saisieComplexe();
        switch (choice) {
            case 1:
                cout << "\n" << "(" << c1string << ")" << " + " << "(" << c2string << ")" << " = ";
                cout << Complex(Complex(c1string) + Complex(c2string)).toString() << "\n" << endl;
                cout << "Retour au menu principal." << "\n" << endl;
                return 0;
            case 2:
                cout << "\n" << "(" << c1string << ")" << " - " << "(" << c2string << ")" << " = ";
                cout << Complex(Complex(c1string) - Complex(c2string)).toString() << "\n" << endl;
                cout << "Retour au menu principal." << "\n" << endl;
                return 0;
            case 3:
                cout << "\n" << "(" << c1string << ")" << " * " << "(" << c2string << ")" << " = ";
                cout << Complex(Complex(c1string) * Complex(c2string)).toString() << "\n" << endl;
                cout << "Retour au menu principal." << "\n" << endl;
                return 0;
            case 4:
                cout << "\n" << "(" << c1string << ")" << " / " << "(" << c2string << ")" << " = ";
                cout << Complex(Complex(c1string) / Complex(c2string)).toString() << "\n" << endl;
                cout << "Retour au menu principal." << "\n" << endl;
                return 0;
            default:
                cout << "Choix non reconnu, retour au menu principal" << "\n" << endl;
                return -1;
        }
    } catch (...) {
        cout << "Votre saisie n'est pas au format escompte (1, 2, 3 ou 4 uniquement)" << endl;
        return -1;
    }
}


/**
 * @brief Permet à l'utilisateur de tester tous les opérateurs.
 */
void menuOperateurs() {
    string c1 = saisieComplexe();
    int choice = 0;
    cout << "Choisissez l'operateur :" << endl;
    cout << "\t1. +\n" << "\t2. -\n" << "\t3. *\n" << "\t4. /\n";
    cout << "\t5. +=\n" << "\t6. -=\n" << "\t7. *=\n" << "\t8. /=\n";
    cout << "\t9. ==\n" << "\t10. !=\n";
    cout << "Votre choix : ";
    try {cin >> choice;}
    catch (...) {
        cout << "Choix non reconnu";
        choice = 0;
    }
    string c2 = saisieComplexe();
    switch (choice) {
        case 1:
        {
            cout << Complex(Complex(c1) + Complex(c2)).toString() << endl;
            break;
        }
        case 2:
        {
            cout << Complex(Complex(c1) - Complex(c2)).toString() << endl;
            break;
        }
        case 3:
        {
            cout << Complex(Complex(c1) * Complex(c2)).toString() << endl;
            break;
        }
        case 4:
        {
            cout << Complex(Complex(c1) / Complex(c2)).toString() << endl;
            break;
        }
        case 5:
        {
            Complex result(c1);
            result += Complex(c2);
            cout << result.toString() << endl;
            break;
        }
        case 6:
        {
            Complex result(c1);
            result -= Complex(c2);
            cout << result.toString() << endl;
            break;
        }
        case 7:
        {
            Complex result(c1);
            result *= Complex(c2);
            cout << result.toString() << endl;
            break;
        }
        case 8:
        {
            Complex result(c1);
            result /= Complex(c2);
            cout << result.toString() << endl;
            break;
        }
        case 9:
        {
            if (Complex(c1) == Complex(c2)) {
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
            break;
        }
        case 10:
        {
            if (Complex(c1) != Complex(c2)) {
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
            break;
        }
        default:
        {
            cout << "Choix invalide" << endl;
            break;
        }
    }
    cout << "\n";
}


/**
 * @brief Menu permettant à l'utilisateur de choisir ce qu'il veux faire.
 * @return void.
 */
void menu() {
    try {
        int choice = 0;
        cout << "Choisissez l'operation a effectuer :" << endl;
        cout << "\t1. Calcul Arithmetique.\n" << "\t2. Conjugue.\n" <<  "\t3. Module.\n";
        cout << "\t4. Oppose.\n" << "\t5. Inverse.\n" << "\t6. Test constructeur doubles.\n";
        cout << "\t7. Test constructeur string.\n" <<  "\t8. Test operateurs.\n" << "Votre choix : ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                cout << "Calcul Arithmetique" << endl;
                calcul();
                break;
            case 2:
                cout << "Conjugue" << endl;
                cout << Complex(saisieComplexe()).conjugue().toString() << endl;
                break;
            case 3:
                cout << "Module" << endl;
                cout << Complex(saisieComplexe()).module() << endl;
                break;
            case 4:
                cout << "Oppose" << endl;
                cout << Complex(saisieComplexe()).oppose().toString() << endl;
                break;
            case 5:
                cout << "Inverse" << endl;
                cout << Complex(saisieComplexe()).inverse().toString() << endl;
                break;
            case 6:
            {
                cout << "Test constructeur doubles" << endl;
                double r = saisieDouble();
                double i = saisieDouble();
                Complex c = Complex(r, i);
                c.argumentsToString();
                cout << c.toString() << endl;
                break;
            }
            case 7:
            {
                cout << "Test constructeur string" << endl;
                Complex c = Complex(saisieComplexe());
                c.argumentsToString();
                cout << c.toString() << endl;
                break;
            }
            case 8:
                cout << "Test operateurs" << endl;
                menuOperateurs();
                break;
            default:
                cout << choice << " n'est pas un nombre valide dans ce menu, veuillez recommencer votre saisie.\n" << endl;
                menu();
                break;
        }
    } catch (...) {
        cout << "Votre saisie n'est pas au format escompte (1, 2, 3, 4 ou 5 uniquement)" << endl;
        int choice = 0;
    }
    
}


/**
 * @brief Programme principal.
 * @return 0.
 */
int main() {
    info();
    while (true) {
        menu();
    }
    return 0;
}