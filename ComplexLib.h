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
    void get_complex() const;
    friend Complex add(Complex, Complex);
    friend Complex subtract(Complex, Complex);
    friend Complex multiply(Complex, Complex);
    friend Complex divide(Complex, Complex);
    friend double getReal(Complex);
    friend double getImag(Complex);
    friend double getMag(Complex);
    friend Complex getConj(Complex);
};

class Phasors : public Complex{
private:
    double magnitude, angle;
public:
    Phasors(){
        magnitude = 0, angle = 0;
    };
    Phasors(double Mag, double Ang){
        magnitude = Mag, angle =  Ang;
    };

    void get_phasor();
    friend Complex phasor_comp(Phasors);
    friend Phasors comp_phasors(Complex);
    friend Phasors add(Phasors, Phasors);
    friend Phasors subtract(Phasors, Phasors);
    friend Phasors multiply(Phasors, Phasors);
    friend Phasors divide(Phasors, Phasors);
};


#endif //UNTITLED3_COMPLEXLIB_H


