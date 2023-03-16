//
// Created by Hugo on 03/03/2023.
//

#include "Complexe.h"
#include "cmath"
#include <regex>


using namespace std;


/**
 * Constructeur avec type double.
 * @param r Partie réel.
 * @param i Partie imaginaire.
 */
Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}


/**
 * Constructeur avec type string.
 * @param s Nombre complexe sous forme de string.
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
 * Getter partie réel.
 * @return La partie réel.
 */
double Complex::getReal() const {
    return real;
}


/**
 * Getter partie imaginaire.
 * @return La partie imaginaire.
 */
double Complex::getImaginary() const {
    return imaginary;
}


/**
 * Setter partie réel.
 * @param r Partie réel.
 */
void Complex::setReal(double r) {
    Complex::real = r;
}


/**
 * Setter partie imaginaire.
 * @param r Partie imaginaire.
 */
void Complex::setImaginary(double i) {
    Complex::imaginary = i;
}


/**
 * Surcharge opérateur +.
 * @param object Le complexe à additionner.
 * @return L'addition des deux complexes.
 */
Complex Complex::operator +(Complex object) const {
    return Complex(real + object.real, imaginary + object.imaginary);
}


/**
 * Surcharge opérateur -.
 * @param object Le complexe à soustraire.
 * @return La soustraction des deux complexes.
 */
Complex Complex::operator -(Complex object) const {
    return Complex(real - object.real, imaginary - object.imaginary);
}


/**
 * Surcharge opérateur *.
 * @param object Le complexe à multiplier.
 * @return La multiplication des deux complexes.
 */
Complex Complex::operator *(Complex object) const {
    double r = real * object.real - imaginary * object.imaginary;
    double i = real * object.imaginary + imaginary * object.real;
    return Complex(r, i);
}


/**
 * Surcharge opérateur /.
 * @param object Le complexe à diviser.
 * @return La division des deux complexes.
 */
Complex Complex::operator /(Complex object) const {
    Complex numerator = Complex(real, imaginary) * object.conjugue();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    double r = numerator.real / denominator;
    double i = numerator.imaginary / denominator;
    return Complex(r, i);
}


/**
 * Surcharge opérateur +=.
 * @param object Le complexe à additionner.
 */
void Complex::operator +=(Complex object) {
    real = real + object.real;
    imaginary = imaginary + object.imaginary;
};


/**
 * Surcharge opérateur -=.
 * @param object Le complexe à soustraire.
 */
void Complex::operator -=(Complex object) {
    real = real - object.real;
    imaginary = imaginary - object.imaginary;
};


/**
 * Surcharge opérateur *=.
 * @param object Le complexe à multiplier.
 */
void Complex::operator *=(Complex object) {
    real = real * object.real - imaginary * object.imaginary;
    imaginary = real * object.imaginary + imaginary * object.real;
};


/**
 * Surcharge opérateur /=.
 * @param object Le complexe à diviser.
 */
void Complex::operator /=(Complex object) {
    Complex numerator = Complex(real, imaginary) * object.conjugue();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    real = numerator.real / denominator;
    imaginary = numerator.imaginary / denominator;
};


/**
 * Calcule le conjugué du complexe.
 * @return Le conjugué du complexe.
 */
Complex Complex::conjugue() const {
    return Complex(real, -imaginary);
}


/**
 * Calcule le module du complexe.
 * @return Le module du complexe.
 */
double Complex::module() const {
    return sqrt(pow(real, 2) + pow(imaginary, 2));
}


/**
 * Calcule l'opposé du complexe.
 * @return L'opposé du complexe.
 */
Complex Complex::oppose() const {
    return Complex(-real, -imaginary);
}


/**
 * Calcule l'inverse du complexe.
 * @return L'inverse du complexe.
 */
Complex Complex::inverse() const {
    return Complex(real, imaginary).conjugue() / (Complex(real, imaginary) * Complex(real, imaginary).conjugue());
}


/**
 * Permet de supprimer les zeros inutiles de la conversion double -> string.
 * @param num Le double à convertir et formater.
 * @return Le nombre converti en string et formaté.
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
}