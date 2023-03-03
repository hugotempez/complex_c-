//
// Created by Hugo on 03/03/2023.
//

#ifndef OBJET_COMPLEXE_COMPLEXE_H
#define OBJET_COMPLEXE_COMPLEXE_H


#include <string>
#include <iostream>


using namespace std;


class Complex {
    private:
        double real;
        double imaginary;

    public:
        Complex(double r, double i);
        explicit Complex(string s);
        void humanReadable();
        Complex operator+(Complex object);
        Complex operator-(Complex object);
        Complex operator*(Complex object);
        //Complex operator/();
};


#endif //OBJET_COMPLEXE_COMPLEXE_H
