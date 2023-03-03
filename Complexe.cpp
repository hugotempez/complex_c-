//
// Created by Hugo on 03/03/2023.
//

#include "Complexe.h"


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
    if (imaginary > 0) {
        cout << real << "+i" << imaginary << endl;
    } else if (imaginary < 0) {
        cout << real << "-i" << -imaginary << endl;
    } else if (imaginary == 0) {
        cout << real << "+i" << endl;
    }
}


Complex Complex::operator+(Complex object) {
    return Complex(real + object.real, imaginary + object.imaginary);
}

Complex Complex::operator-(Complex object) {
    return Complex(real - object.real, imaginary - object.imaginary);
}

Complex Complex::operator*(Complex object) {}

//Complex Complex::operator/() {}