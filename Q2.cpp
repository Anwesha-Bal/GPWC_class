#include<iostream>
using namespace std;
class Complex{
	int real;
	int complex;
	
	public:
		void setComplex(int &x , int &y);
		void displayComplex();
		Complex AddComplex(Complex &c1 , Complex &c2);
		Complex SubComplex(Complex &c1 , Complex &c2);
		Complex MulComplex(Complex &c1 , Complex &c2);
		Complex DivComplex(Complex &c1 , Complex &c2);
};
void Complex::setComplex(int &x , int &y){
	real = x;
	complex = y;
}
void Complex::displayComplex(){
	cout<<"Resultant Complex number is: "<<real<<"+"<<"i"<<complex<<endl;
}
Complex Complex::AddComplex(Complex &c1 , Complex &c2){
	Complex sum;
	sum.real = c1.real + c2.real;
	return sum;
}
Complex Complex::SubComplex(Complex &c1 , Complex &c2){
	Complex dif;
	dif.real = c1.real - c2.real;
	dif.complex = c1.complex - c2.complex;
	return dif;
}
Complex Complex::MulComplex(Complex &c1 , Complex &c2){
	Complex mul;
	mul.real = c1.real * c2.real;
	mul.complex = c1.complex * c2.complex;
	return mul;
}
Complex Complex::DivComplex(Complex &c1 , Complex &c2){
	Complex div;
	div.real = c1.real / c2.real;
	div.complex = c1.complex / c2.complex;
	return div;
}
int main(){
	int x , y , m , n;
	cout<<"Enter the four values of x,y,m and n separated by enter"<<endl;
	cin>>x;
	cin>>y;
	cin>>m;
	cin>>n;
	Complex c1 , c2 , temp;
	c1.setComplex(x,y);
	c2.setComplex(m,n);
	c1.displayComplex();
	c2.displayComplex();
	temp=c1.AddComplex(c1,c2);
	cout<<"Addition: "<<endl;
	temp.displayComplex();
	temp=c1.SubComplex(c1,c2);
	cout<<"Substraction: "<<endl;
	temp.displayComplex();
	temp=c1.MulComplex(c1,c2);
	cout<<"Multiplication: "<<endl;
	temp.displayComplex();
	temp=c1.DivComplex(c1,c2);
	cout<<"Division: "<<endl;
	temp.displayComplex();
	return 0;
}
