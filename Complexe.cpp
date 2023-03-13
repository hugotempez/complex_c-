//
// Created by Hugo on 03/03/2023.
//

#include "Complexe.h"
#include "cmath"


using namespace std;


Complex::Complex(double r, double i) {
    real = r;
    imaginary = i;
}


Complex::Complex(string s) {
    string realStr;
    string imaginaryStr;
    string tmp;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '+' and s[i] != '-' and s[i] != 'i') {
            tmp += s[i];
        } else if (s[i] == '+') {
            realStr = tmp;
            tmp = "";
        } else if (s[i] == '-') {
            realStr = tmp;
            tmp = "";
            imaginaryStr += "-";
        } else if (s[i] == 'i') {
            continue;
        }
    }
    imaginaryStr = tmp;
    real = stod(realStr);
    imaginary = stod(imaginaryStr);
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


string Complex::toString() {
    if (imaginary == 1) {
        return to_string(real) + "+i";
    } else if (imaginary == 0) {
        return to_string(real);
    } else if (imaginary > 0) {
        return to_string(real) + "+i" + to_string(imaginary);
    } else if (imaginary < 0) {
        return to_string(real) + "-i" + to_string(imaginary);
    }
}


Complex Complex::operator +(Complex object) {
    return Complex(real + object.real, imaginary + object.imaginary);
}


Complex Complex::operator -(Complex object) {
    return Complex(real - object.real, imaginary - object.imaginary);
}


Complex Complex::operator *(Complex object) {
    double r = real * object.real - imaginary * object.imaginary;
    double i = real * object.imaginary + imaginary * object.real;
    return Complex(r, i);
}


Complex Complex::operator /(Complex object) {
    Complex numerator = Complex(real, imaginary) * object.conjugue();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    double r = numerator.real / denominator;
    double i = numerator.imaginary / denominator;
    return Complex(r, i);
}


Complex Complex::conjugue() {
    return Complex(real, -imaginary);
}


double Complex::module() {
    return sqrt(pow(real, 2) + pow(imaginary, 2));
}


Complex Complex::oppose() {
    return Complex(-real, -imaginary);
}


Complex Complex::inverse() {
    return Complex(real, imaginary).conjugue() / (Complex(real, imaginary) * Complex(real, imaginary).conjugue());
}