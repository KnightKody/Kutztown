#ifndef H_fraction
#define H_fraction
  
#include <iostream>
#include <cmath>

using namespace std;

class fractionType
{

public:
  //Constructor
  fractionType(int num = 0, int den = 1);

  //Overloaded functions
  //Stream/unary operators
  ostream& operator<<(ostream& out);
  istream& operator>>(istream& out);
  //logic operators
  bool operator==(const fractionType& Num) const;
  bool operator!=(const fractionType& Num) const;
  bool operator>(const fractionType& Num) const;
  bool operator>=(const fractionType& Num) const;
  bool operator<(const fractionType& Num) const;
  bool operator<=(const fractionType& Num) const;
  //Arithmatic operators
  fractionType operator+(const fractionType& Num) const;
  fractionType operator-(const fractionType& Num) const;
  fractionType operator*(const fractionType& Num) const;
  fractionType operator/(const fractionType& Num) const;
  //Increment and decrement operators
  fractionType operator++();
  fractionType operator--();
  fractionType operator++(int);
  fractionType operator--(int);
  
private:
  int numerator;      //variable to store the numerator
  int denominator;    //variable to store the denominator

    
  //private method to compute and return the greatest
  //common divisor of the numerator and denominator
  int gcd() {

    //assign absolute values of numerator
    //and denominator into a and b
    int a = abs(numerator);
    int b = abs(denominator);

    //make sure a is greater than b
    if (a < b)
      {
	int temp = a;
	a = b;
	b = temp;
      }

    //use Euclid's algorithm to find and return
    //the greatest common divisor
    while (b != 0) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

};

#endif
