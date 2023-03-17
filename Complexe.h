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

        /**
         * @brief Partie réel du complexe.
         */
        double real;

        /**
         * @brief Partie imaginaire du complexe.
         */
        double imaginary;

        /**
         * @brief Fonction supprimant les zéros inutiles lors de la conversion en string .
         * @param num Le double à convertir et formater.
         * @return Le string formaté.
         */
        static string stringFormater(double num);       //fonctionnel

    public:

        /**
         * @brief Constructeur utilisant des doubles en paramétres.
         * @param r La partie réel du complexe.
         * @param i La partie imaginaire du complexe.
         */
        explicit Complex(double r=0, double i=0);       //fonctionnel

        /**
         * @brief Le constructeur utilisant un string en paramétre.
         * @param s Le string à convertir en complexe.
         */
        explicit Complex(const string& s);              //fonctionnel

        /**
         * @brief Getter partie réel.
         * @return La partie réel du complexe.
         */
        double getReal() const;                         //fonctionnel

        /**
         * @brief Getter partie imaginaire.
         * @return La partie imaginaire du complexe.
         */
        double getImaginary() const;                    //fonctionnel

        /**
         * @brief Setter partie réel.
         * @param real La partie réel à modifier.
         */
        void setReal(double real);                      //fonctionnel

        /**
         * @brief Setter partie imaginaire.
         * @param imaginary La partie imaginaire à modifier.
         */
        void setImaginary(double imaginary);            //fonctionnel

        /**
         * @brief Surcharge opérateur +.
         * @param object Le complexe à ajouter au premier.
         * @return Le complexe resultant de l'addition des deux complexes.
         */
        Complex operator +(Complex object) const;       //fonctionnel

        /**
         * @brief Surcharge opérateur -.
         * @param object Le complexe à soustraire au premier.
         * @return Le complexe resultant de la soustraction des deux complexes.
         */
        Complex operator -(Complex object) const;       //fonctionnel

        /**
         * @brief Surcharge opérateur *.
         * @param object Le complexe à multiplier au premier.
         * @return Le complexe resultant de la multiplication des deux complexes.
         */
        Complex operator *(Complex object) const;       //fonctionnel

        /**
         * @brief Surcharge opérateur /.
         * @param object Le complexe à diviser au premier.
         * @return Le complexe resultant de la division des deux complexes.
         */
        Complex operator /(Complex object) const;       //fonctionnel

        /**
         * @brief Surcharge opérateur +=.
         * @param object Le complexe à ajouter au premier.
         */
        void operator +=(Complex object);               //fonctionnel

        /**
         * @brief Surcharge opérateur -=.
         * @param object Le complexe à soustraire au premier.
         */
        void operator -=(Complex object);               //fonctionnel

        /**
         * @brief Surcharge opérateur *=.
         * @param object Le complexe à multiplier au premier.
         */
        void operator *=(Complex object);               //fonctionnel

        /**
         * @brief Surcharge opérateur /=.
         * @param object Le complexe à diviser au premier.
         */
        void operator /=(Complex object);               //fonctionnel

        /**
         * @brief Surcharge opérateur ==.
         * @param object Le complexe à comparer au premier.
         * @return True si les deux complexes sont égaux, sinon faux.
         */
        bool operator ==(Complex object) const;         //fonctionnel

        /**
          * @brief Surcharge opérateur !=.
          * @param object Le complexe à comparer au premier.
          * @return True si les deux complexes sont différents, sinon faux.
          */
        bool operator !=(Complex object) const;         //fonctionnel

        /**
         * @brief Calcul le conjugué du complexe.
         * @return Le conjugué du complexe.
         */
        Complex conjugue() const;                       //fonctionnel

        /**
         * @brief Calcul le module du complexe.
         * @return Le module du complexe.
         */
        double module() const;                          //fonctionnel

        /**
         * @brief Calcul l'opposé du complexe.
         * @return L'opposé du complexe.
         */
        Complex oppose() const;                         //fonctionnel

        /**
         * @brief Calcul l'inverse du complexe.
         * @return L'inverse du complexe.
         */
        Complex inverse() const;                        //fonctionnel

        /**
         * @brief Renvoi le complexe sous forme de string.
         * @return Un string du complexe.
         */
        string toString() const;                        //fonctionnel

        /**
         * @brief Écris dans la console les propriétés de l'objet complexe.
         */
        void argumentsToString() const;                 //fonctionnel
};


#endif //OBJET_COMPLEXE_COMPLEXE_H