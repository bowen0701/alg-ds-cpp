#ifndef DS_COMPLEX
#define DS_COMPLEX

#include <cmath>

class Ostream;

class Complex {
 public:
  // Constructor.
  Complex(double re = 0, double im = 0);
  Complex();

  // Deconstructor.
  virtual ~Complex();

  // Setters & getters.
  void SetReal(double re);
  double GetReal();
  void SetImag(double im);
  double GetImag();

 private:
   // Define real and image parts.
   double re, im;
};

#endif
