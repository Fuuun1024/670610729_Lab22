#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){

	return ComplexNumber( real*c.real - imag*c.imag  ,  real*c.imag + imag*c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
    
    double x2 = c.real;
    double y2 = c.imag;
    double r = pow(x2,2) + pow(y2,2);
    
	return ComplexNumber( (real*c.real + imag* c.imag )/r  ,  imag* c.real/r - real* c.imag/r);
}

bool ComplexNumber::operator==(const ComplexNumber &c){
 if(real == c.real && imag == c.imag) return true;
 else return false;
}

double ComplexNumber::abs(){
    return sqrt( pow(real,2)+pow(imag,2) );
}

double ComplexNumber::angle(){
    return atan2 (imag,real) * 180 / M_PI;
}

ComplexNumber operator+(double s, const ComplexNumber &c){
	return ComplexNumber(s+c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c){
    return ComplexNumber(s-c.real,0-c.imag);
// 	return ComplexNumber(s-c.real, c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c){
	return ComplexNumber(s*c.real, s*c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c){
    double x2 = c.real;
    double y2 = c.imag;
    double r = pow(x2,2) + pow(y2,2);
    
	return ComplexNumber( s* c.real/r + 0* c.imag/r  ,  0* c.real/r - s* c.imag/r);
}

bool operator==(double s, const ComplexNumber &c){
 if(s == c.real && 0 == c.imag) return true;
 else return false;
}

ostream & operator<<(ostream &os, const ComplexNumber &c){
    if(c.real != 0 and c.imag == 0) return os << c.real;
    else if(c.real == 0 and c.imag != 0)  return os << c.imag << "i";
    
    else if(c.real == 0 and c.imag == 0)  return os << c.real;
    else if(c.real != 0 and c.imag < 0) return os << c.real << c.imag << "i";
    else return os << c.real << "+" << c.imag << "i";
    
}