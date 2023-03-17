//
// Created by Hugo on 03/03/2023.
//

#include "Complexe.h"
#include "cmath"
#include <regex>


using namespace std;


/**
 * @brief Constructeur utilisant des doubles en paramétres.
 * @param r La partie réel du complexe.
 * @param i La partie imaginaire du complexe.
 */
Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}


/**
 * @brief Le constructeur utilisant un string en paramétre.
 * @param s Le string à convertir en complexe.
 */
Complex::Complex(const string& s) {
    if (regex_match(s, regex(R"(^[-+]?\d*.?\d*i?[-+]?[-+]?\d*.?\d*i?$)"))) {
        string tmp, rString, iString;
        bool hasI = false;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 and s[i] == '+' or s[i] == '-') {
                rString = tmp;
                tmp = s[i];
            } else if (s[i] == 'i') {
                hasI = true;
                if (i == 0 or s[i-1] == '+') {
                    iString += "1";
                } else if (s[i-1] == '-') {
                    iString = "-1";
                }
            } else {tmp += s[i];}
        }
        if (not hasI) {
            real = stod(tmp);
            imaginary = 0;
        } else {
            if (iString.empty()) {iString = tmp;}
            if (rString.empty()) {real = 0;} else {real = stod(rString);}
            if (iString.empty()) {imaginary = 0;} else {imaginary = stod(iString);}
        }
    } else {
        throw invalid_argument("Le complexe renseigné n'est pas valide");
    }
}


/**
 * @brief Getter partie réel.
 * @return La partie réel du complexe.
 */
double Complex::getReal() const {
    return real;
}


/**
 * @brief Getter partie imaginaire.
 * @return La partie imaginaire du complexe.
 */
double Complex::getImaginary() const {
    return imaginary;
}


/**
 * @brief Setter partie réel.
 * @param real La partie réel à modifier.
 */
void Complex::setReal(double r) {
    Complex::real = r;
}


/**
 * @brief Setter partie imaginaire.
 * @param imaginary La partie imaginaire à modifier.
 */
void Complex::setImaginary(double i) {
    Complex::imaginary = i;
}


/**
 * @brief Surcharge opérateur +.
 * @param object Le complexe à ajouter au premier.
 * @return Le complexe resultant de l'addition des deux complexes.
 */
Complex Complex::operator +(Complex object) const {
    return Complex(real + object.real, imaginary + object.imaginary);
}


/**
 * @brief Surcharge opérateur -.
 * @param object Le complexe à soustraire au premier.
 * @return Le complexe resultant de la soustraction des deux complexes.
 */
Complex Complex::operator -(Complex object) const {
    return Complex(real - object.real, imaginary - object.imaginary);
}


/**
 * @brief Surcharge opérateur *.
 * @param object Le complexe à multiplier au premier.
 * @return Le complexe resultant de la multiplication des deux complexes.
 */
Complex Complex::operator *(Complex object) const {
    double r = real * object.real - imaginary * object.imaginary;
    double i = real * object.imaginary + imaginary * object.real;
    return Complex(r, i);
}


/**
 * @brief Surcharge opérateur /.
 * @param object Le complexe à diviser au premier.
 * @return Le complexe resultant de la division des deux complexes.
 */
Complex Complex::operator /(Complex object) const {
    Complex numerator = Complex(real, imaginary) * object.conjugue();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    double r = numerator.real / denominator;
    double i = numerator.imaginary / denominator;
    return Complex(r, i);
}


/**
 * @brief Surcharge opérateur +=.
 * @param object Le complexe à ajouter au premier.
 */
void Complex::operator +=(Complex object) {
    real = real + object.real;
    imaginary = imaginary + object.imaginary;
};


/**
 * @brief Surcharge opérateur -=.
 * @param object Le complexe à soustraire au premier.
 */
void Complex::operator -=(Complex object) {
    real = real - object.real;
    imaginary = imaginary - object.imaginary;
};


/**
 * @brief Surcharge opérateur *=.
 * @param object Le complexe à multiplier au premier.
 */
void Complex::operator *=(Complex object) {
    double rA = real * object.real;
    double rB = imaginary * object.imaginary;
    double iA = real * object.imaginary;
    double iB = imaginary * object.real;
    real = rA - rB;
    imaginary = iA + iB;
};


/**
 * @brief Surcharge opérateur /=.
 * @param object Le complexe à diviser au premier.
 */
void Complex::operator /=(Complex object) {
    Complex numerator = Complex(real, imaginary) * object.conjugue();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    real = numerator.real / denominator;
    imaginary = numerator.imaginary / denominator;
};


/**
 * @brief Surcharge opérateur ==.
 * @param object Le complexe à comparer au premier.
 * @return True si les deux complexes sont égaux, sinon faux.
 */
bool Complex::operator ==(Complex object) const {
    if (real == object.real and imaginary == object.imaginary){
        return true;
    } else {
        return false;
    }
}


/**
  * @brief Surcharge opérateur !=.
  * @param object Le complexe à comparer au premier.
  * @return True si les deux complexes sont différents, sinon faux.
  */
bool Complex::operator !=(Complex object) const {
    if (real != object.real or imaginary != object.imaginary) {
        return true;
    } else {
        return false;
    }
}


/**
 * @brief Calcul le conjugué du complexe.
 * @return Le conjugué du complexe.
 */
Complex Complex::conjugue() const {
    return Complex(real, -imaginary);
}


/**
 * @brief Calcul le module du complexe.
 * @return Le module du complexe.
 */
double Complex::module() const {
    return sqrt(pow(real, 2) + pow(imaginary, 2));
}


/**
 * @brief Calcul l'opposé du complexe.
 * @return L'opposé du complexe.
 */
Complex Complex::oppose() const {
    return Complex(-real, -imaginary);
}


/**
 * @brief Calcul l'inverse du complexe.
 * @return L'inverse du complexe.
 */
Complex Complex::inverse() const {
    return Complex(real, imaginary).conjugue() / (Complex(real, imaginary) * Complex(real, imaginary).conjugue());
}


/**
 * @brief Renvoi le complexe sous forme de string.
 * @return Un string du complexe.
 */
string Complex::stringFormater(double num) {
    string s = to_string(num);
    string returned;
    int lastZero = 0;
    for (int i = s.size()-1; i > 0; i--) {
        if (s[i] != '0') {
            lastZero = i;
            break;
        }
    }
    if (lastZero == 0) {
        returned = s[0];
    } else {
        if (s[lastZero] == '.') {
            returned = s.substr(0, lastZero);
        } else {
            returned = s.substr(0, lastZero+1);
        }
    }
    return returned;
}


/**
 * Renvoi un complexe sous la forme la plus lisible possible.
 * @return Le complexe sous forme de string.
 */
string Complex::toString() const {
    string r = stringFormater(real);
    string i = stringFormater(imaginary);
    string iAbs = stringFormater(abs(imaginary));
    if (real == 0 and imaginary == 0) {
        return "0";
    } else if (real == 0 and imaginary != 0) {
        if (imaginary == 1) {return "i";}
        else if (imaginary == -1) {return "-i";}
        return i + "i";
    } else if (real != 0 and imaginary == 0) {
        return r;
    } else {
        if (imaginary == 1) {return r + "+i";}
        else if (imaginary == -1) {return r + "-i";}
        else if (imaginary > 0) {return r + "+" + i + "i";}
        else if (imaginary < 0) {return r + "-" + iAbs + "i";}
    }
    return "Division par 0 impossible";
}


/**
 * @brief Écris dans la console les propriétés de l'objet complexe.
 */
void Complex::argumentsToString() const {
    cout << "Partie reel : " << real << endl;
    cout << "Partie imaginaire : " << imaginary << endl;
}