#include <iostream>
# include<math.h>
using namespace std;

class Complex {
	long double real, imag;
public:
	Complex();
	Complex(double r, double i);
	void    setVals(double r, double i) { real = r;imag = i; };
	double  getReal() { return real; };
	double  getImag() { return imag; };
	double  getMag() { return sqrt(real * real + imag * imag); };
	Complex operator+(Complex r);
	Complex operator-(Complex r);
	Complex operator*(Complex r);
	Complex operator/(Complex r);
};

ostream& operator<<(ostream& out, Complex z) {
	if (z.getImag() >= 0)
		return out << z.getReal() << " + " << z.getImag() << "i";
	else
		return out << z.getReal() << " - " << -1 * z.getImag() << "i";
}

Complex operator/(double x, Complex c) {
	Complex numer(x, 0);
	return numer / c;
}

Complex::Complex() {
	real = imag = 0;
}

Complex::Complex(double r, double i) {
	real = r; imag = i;
}

Complex Complex::operator+(Complex z) {
	Complex temp;
	temp.real = real + z.real;
	temp.imag = imag + z.imag;
	return temp;
}

Complex Complex::operator*(Complex z) {
	Complex temp;
	temp.real = real * z.real - imag * z.imag;
	temp.imag = real * z.imag + imag * z.real;
	return temp;
}

Complex Complex::operator/(Complex z) {
	z.imag *= -1;
	Complex temp = (*this) * z;
	temp.real /= z.real * z.real + z.imag * z.imag;
	temp.imag /= z.real * z.real + z.imag * z.imag;
	return temp;
}

Complex Complex::operator-(Complex z) {
	Complex temp;
	temp.real = real - z.real;
	temp.imag = imag - z.imag;
	return temp;
}
