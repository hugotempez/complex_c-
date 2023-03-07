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


void Complex::humanReadable() {
    if (imaginary == 1) {
        cout << real << "+i" << endl;
    } else if (imaginary == 0) {
        cout << real << endl;
    } else if (imaginary > 0) {
        cout << real << "+i" << imaginary << endl;
    } else if (imaginary < 0) {
        cout << real << "-i" << -imaginary << endl;
    }
}


string Complex::toString() {
    if (imaginary == 1) {
        return to_string(real) + "+i";
    } else if (imaginary == 0) {
        return to_string(real);
    } else if (imaginary > 0) {
        return to_string(real) + "+i" + to_string(imaginary);
    } else if (imaginary < 0) {
        return to_string(real) + "-i" + to_string(-imaginary);
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
    Complex numerator = Complex(real, imaginary) * object.conjugué();
    double denominator = pow(object.real, 2) + pow(object.imaginary, 2);
    double r = numerator.real / denominator;
    double i = numerator.imaginary / denominator;
    return Complex(r, i);
}


Complex Complex::conjugué() {
    return Complex(real, -imaginary);
}


double Complex::module() {
    return sqrt(pow(real, 2) + pow(imaginary, 2));
}


Complex Complex::opposé() {
    return Complex(-real, -imaginary);
}


Complex Complex::inverse() {
    return Complex(real, imaginary).conjugué() / (Complex(real, imaginary) * Complex(real, imaginary).conjugué());
}