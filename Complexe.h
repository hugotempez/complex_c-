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
        Complex(double r, double i);            //fonctionnel
        explicit Complex(string s);             //fonctionnel
        void humanReadable();                   //fonctionnel
        string toString();                      //fonctionnel
        Complex operator +(Complex object);     //fonctionnel
        Complex operator -(Complex object);     //fonctionnel
        Complex operator *(Complex object);     //fonctionnel
        Complex operator /(Complex object);     //fonctionnel
        Complex conjugué();                     //fonctionnel
        double module();                        //fonctionnel a affiner
        Complex opposé();                       //fonctionnel
        Complex inverse();                      //fonctionnel
};


#endif //OBJET_COMPLEXE_COMPLEXE_H
