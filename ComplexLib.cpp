#include <iostream>
#include <cmath>

class Complex{
public:
    double real, imaginary;
    Complex(){
        //default constructor
        real = 0, imaginary = 0;
    }
    Complex(double r, double i){
        //Parameterized constructor
        real =  r, imaginary = i;
    }

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
    //Constructors
    Phasors(){
        magnitude = 0, angle = 0;
    }
    Phasors(double Mag, double Ang){
        magnitude = Mag, angle =  Ang;
    }

    void get_phasor() const;
    friend Complex phasor_comp(Phasors);
    friend Phasors comp_phasors(Complex);
    friend Phasors add(Phasors, Phasors);
    friend Phasors subtract(Phasors, Phasors);
    friend Phasors multiply(Phasors, Phasors);
    friend Phasors divide(Phasors, Phasors);

};

void Complex::set() {
    std::cout << "Please enter the real part";
    std::cin >> real;
    std::cout << "The real part specified is " << real << '\n';
    std::cout << "Please enter the imaginary part";
    std::cin >> imaginary;
    std::cout << "The imaginary part specified is " <<imaginary <<'\n';
}

void Complex::get_complex() const{
    if(imaginary  < 0) {
        std::cout << "The complex number is: " << real << "-j" << -1*imaginary << '\n';
    }
    else{
        std::cout << "The complex number is: " << real << "+j" << imaginary << '\n';
        }
}

Complex add(Complex i1, Complex i2){
    Complex sum;
    sum.real = i1.real + i2.real;
    sum.imaginary = i1.imaginary + i2.imaginary;
    return sum;
}

Complex subtract(Complex i1, Complex i2){
    Complex diff;
    diff.real = i1.real - i2.real;
    diff.imaginary = i1.imaginary - i2.imaginary;
    return diff;
}

Complex multiply(Complex i1, Complex i2){
    Complex resultant;
    resultant.real = (i1.real*i2.real - i1.imaginary*i2.imaginary);
    resultant.imaginary = (i1.real*i2.imaginary + i1.imaginary*i2.real);
    return resultant;
}

Complex divide(Complex i1, Complex i2){
    Complex result;
    result.real = (i1.real*i2.real + i1.imaginary*i2.imaginary)/(pow(i2.real, 2) + pow(i2.imaginary, 2));
    result.imaginary = (i1.imaginary*i2.real - i1.real*i2.imaginary)/(pow(i2.real, 2) + pow(i2.imaginary, 2));
    return result;
}

Complex getConj(Complex c1){
    Complex conjugate;
    conjugate.real = c1.real;
    conjugate.imaginary = - c1.imaginary;
    return conjugate;
}

double getReal(Complex i1){
    return i1.real;
}

double getImag(Complex i1){
    return i1.imaginary;
}

double getMag(Complex i1){
    return sqrt(pow(i1.real,2 ) + pow(i1.imaginary, 2));
}

void Phasors::get_phasor() const{
    std::cout << "Phasor is: " << magnitude << " < " << angle << '\n';
}

Complex phasor_comp(Phasors p1){
    Complex comp;
    comp.real = p1.magnitude*cos(p1.angle*(M_PI/180));
    comp.imaginary = p1.magnitude*sin(p1.angle*(M_PI/180));
    return comp;
}

Phasors comp_phasors(Complex i1){
    Phasors phasor;
    phasor.magnitude = sqrt(pow(i1.real, 2) + pow(i1.imaginary, 2));
    phasor.angle = (atan2(i1.imaginary, i1.real))*(180/M_PI);
    return phasor;
}

Phasors add(Phasors p1, Phasors p2){
    Complex c1, c2;
    c1 = phasor_comp(p1);
    c2 = phasor_comp(p2);
    Complex sum = add(c1, c2);
    return comp_phasors(sum);
}

Phasors subtract(Phasors p1, Phasors p2){
    Complex c1, c2;
    c1 = phasor_comp(p1);
    c2 = phasor_comp(p2);
    Complex diff = subtract(c1, c2);
    return comp_phasors(diff);
}

Phasors multiply(Phasors p1, Phasors p2){
    Phasors result;
    result.magnitude = p1.magnitude*p2.magnitude;
    result.angle = p1.angle + p2.angle;
    return result;
}

Phasors divide(Phasors p1, Phasors p2){
    Phasors p3;
    p3.magnitude = p1.magnitude/p2.magnitude;
    p3.angle = p1.angle - p2.angle;
    return p3;
}

int main(){
    Complex c1(1, 4);
    Complex c1_prime = getConj(c1);
    Complex result = multiply(c1, c1_prime);
    result.get_complex();

}


