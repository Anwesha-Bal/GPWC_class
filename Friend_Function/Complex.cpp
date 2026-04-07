#include<iostream>
using namespace std;

class Complex; // Forward declaration
class D{
public:
    void display(Complex &x);
};


class Complex{
    float real,img;
public:
    Complex(); // Default constructor
    Complex(float i , float j); // Parameterized constructor
    Complex(Complex &obj); // Copy constructor (FIXED)

    friend Complex add(Complex &M , Complex &N); 

    // friend void D::display(Complex &x); //Friend function

    //Friend class
    friend class D;
};

Complex::Complex(){
    real = 0.0;
    img = 0.0;
}

Complex::Complex(float i, float j){
    real = i;
    img  = j;
}

Complex::Complex(Complex &obj){
    real = obj.real;
    img  = obj.img;
}

Complex add(Complex &M , Complex &N){
    Complex sum;
    sum.real = M.real + N.real;

    sum.img = M.img + N.img;
    return sum;
}


void D::display(Complex &x){
    cout << x.real << " + " << x.img << "i" << endl;
}

int main(){
    Complex a;              // Default constructor
    Complex b(2.0,3.0);    // Parameterized constructor
    Complex c(b);          // Copy constructor

    a = add(b,c);

    D dis;
    dis.display(b);
    dis.display(c);
    dis.display(a);

    return 0;
}