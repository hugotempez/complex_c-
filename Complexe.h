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
        Complex(double r=0, double i=0);                    //fonctionnel
        explicit Complex(const string& s);              //fonctionnel

        double getReal() const;                         //fonctionnel
        double getImaginary() const;                    //fonctionnel
        void setReal(double real);                      //fonctionnel
        void setImaginary(double imaginary);            //fonctionnel

        Complex operator +(Complex object) const;       //fonctionnel
        Complex operator -(Complex object) const;       //fonctionnel
        Complex operator *(Complex object) const;       //fonctionnel
        Complex operator /(Complex object) const;       //fonctionnel
        void operator +=(Complex object);
        void operator -=(Complex object);
        void operator *=(Complex object);
        void operator /=(Complex object);

        Complex conjugue() const;                       //fonctionnel
        double module() const;                          //fonctionnel a affiner
        Complex oppose() const;                         //fonctionnel
        Complex inverse() const;                        //fonctionnel
        string toString() const;                        //fonctionnel
};


#endif //OBJET_COMPLEXE_COMPLEXE_H