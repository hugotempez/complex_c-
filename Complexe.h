//
// Created by Hugo on 03/03/2023.
//

#ifndef OBJET_COMPLEXE_COMPLEXE_H
#define OBJET_COMPLEXE_COMPLEXE_H


#include <string>
#include <iostream>


using namespace std;


/**
 * @class Permet de manipuler des nombres complexes.
 */
class Complex {
    private:
        double real;
        double imaginary;
        static string stringFormater(double num);

    public:
        explicit Complex(double r=0, double i=0);       //fonctionnel
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
        double module() const;                          //fonctionnel (sous forme de racine ou double ?)
        Complex oppose() const;                         //fonctionnel
        Complex inverse() const;                        //fonctionnel (sous forme de fraction ou reel ?)
        string toString() const;                        //fonctionnel
};


#endif //OBJET_COMPLEXE_COMPLEXE_H