#include <iostream>
#include <math.h>

class Complex{
    double real, imaginary;
public:
    Complex(){
        //default constructor
        real = 0, imaginary = 0;
    }
    Complex(double r, double i){
        //Specified constructor
        real =  r, imaginary = i;
    }

    void set();
    void get();
    friend Complex add(Complex, Complex);
    friend Complex subtract(Complex, Complex);
    friend Complex multiply(Complex, Complex);
    friend Complex divide(Complex, Complex);
};

void Complex::set() {
    std::cout << "Please enter the real part";
    std::cin >> real;
    std::cout << "The real part specified is " << real << '\n';
    std::cout << "Please enter the imaginary part";
    std::cin >> imaginary;
    std::cout << "The imaginary part specified is " <<imaginary <<'\n';
}

void Complex::get(){
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

int main() {
    Complex n1(6.5, -6);
    Complex n2(24, 7);
    Complex val = divide(n1, n2);
    val.get();

}
