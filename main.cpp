#include <iostream>

class Complex{
    int real, imaginary;
public:
    Complex(){
        //default constructor
        real = 0, imaginary = 0;
    }
    Complex(int r, int i){
        //Specified constructor
        real =  r, imaginary = i;
    }

    void set();
    void get();
    friend Complex add(Complex, Complex);
    friend Complex subtract(Complex, Complex);

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
        std::cout << "The complex number is: " << real << "" << imaginary << "j" << '\n';
    }
    else{
        std::cout << "The complex number is: " << real << "+" << imaginary << "j" << '\n';
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

int main() {
    Complex n1;
    n1.set();
    Complex n2(-4, -2);
    Complex diff = subtract(n1, n2);
    diff.get();
}
