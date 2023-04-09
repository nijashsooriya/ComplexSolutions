//
// Created by Nijash Sooriya on 2023-04-08.
//

#ifndef UNTITLED3_COMPLEXLIB_H
#define UNTITLED3_COMPLEXLIB_H

#include <iostream>
#include <vector>

class Complex{
private:
    double real, imaginary;
public:
    Complex();
    Complex(double r, double i){
        real = r, imaginary = i;
    };
    void set();
    void get();
    friend Complex add(Complex, Complex);
    friend Complex subtract(Complex, Complex);
    friend Complex multiply(Complex, Complex);
    friend Complex divide(Complex, Complex);
    friend double getReal(Complex);
    friend double getImag(Complex);
    friend double getMag(Complex);
};


#endif //UNTITLED3_COMPLEXLIB_H


