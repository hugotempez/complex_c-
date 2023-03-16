//
// Created by Hugo on 03/03/2023.
//

#include "Complexe.h"
#include "cmath"
#include <regex>


using namespace std;


Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}


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


double Complex::getReal() const {
    return real;
}


double Complex::getImaginary() const {
    return imaginary;
}


void Complex::setReal(double r) {
    Complex::real = r;
}


void Complex::setImaginary(double i) {
    Complex::imaginary = i;
}


Complex Complex::operator +(Complex object) const {
    return Complex(real + object.real, imaginary + object.imaginary);
}


Complex Complex::operator -(Complex object) const {
    return Complex(real - object.real, imaginary - object.imaginary);
}


Complex Complex::operator *(Complex object) const {
    double r = real * object.real - imaginary * object.imaginary;
    double i = real * object.imaginary + imaginary * object.real;
    return Complex(r, i);
}


Complex Complex::operator /(Complex object) const {
    Complex numerator = Complex(real, imaginary) * object.conjugue();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    double r = numerator.real / denominator;
    double i = numerator.imaginary / denominator;
    return Complex(r, i);
}


void Complex::operator +=(Complex object) {
    real = real + object.real;
    imaginary = imaginary + object.imaginary;
};


void Complex::operator -=(Complex object) {
    real = real - object.real;
    imaginary = imaginary - object.imaginary;
};


void Complex::operator *=(Complex object) {
    real = real * object.real - imaginary * object.imaginary;
    imaginary = real * object.imaginary + imaginary * object.real;
};


void Complex::operator /=(Complex object) {
    Complex numerator = Complex(real, imaginary) * object.conjugue();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    real = numerator.real / denominator;
    imaginary = numerator.imaginary / denominator;
};


Complex Complex::conjugue() const {
    return Complex(real, -imaginary);
}


double Complex::module() const {
    return sqrt(pow(real, 2) + pow(imaginary, 2));
}


Complex Complex::oppose() const {
    return Complex(-real, -imaginary);
}


Complex Complex::inverse() const {
    return Complex(real, imaginary).conjugue() / (Complex(real, imaginary) * Complex(real, imaginary).conjugue());
}


string Complex::toString() const {
    if (real == 0 and imaginary == 0) {
        return "0";
    } else if (real == 0 and imaginary != 0) {
        if (imaginary == 1) {return "i";}
        else if (imaginary == -1) {return "-i";}
        return to_string(imaginary) + "i";
    } else if (real != 0 and imaginary == 0) {
        return to_string(real);
    } else {
        if (imaginary == 1) {return to_string(real) + "+i";}
        else if (imaginary == -1) {return to_string(real) + "-i";}
        else if (imaginary > 0) {return to_string(real) + "+" + to_string(imaginary) + "i";}
        else if (imaginary < 0) {return to_string(real) + "-" + to_string(abs(imaginary)) + "i";}
    }
}