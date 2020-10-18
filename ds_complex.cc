#include "ds_complex.h"

Complex::Complex(double re, double im) {
  this->re = re;
  this->im = im;
}

Complex::~Complex() = default;

void Complex::SetReal(double re) {
  this->re = re;
}

double Complex::GetReal() {
  return re;
}

void Complex::SetImag(double im) {
  this->im = im;
}

double Complex::GetImag() {
  return im;
}

int main() {
  // TODO: implement complex class.

  return 0;
}
