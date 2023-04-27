#include <iostream>
#include <cmath> //Imports math
#include <iomanip> //Imports setprecision

using namespace std;

int main() {
  double Principal;
  double Intrest;
  int Compounded;
  double Amount;

  cout << "What is the Principle amount?" << endl;
  cin >> Principal;

  cout << "What is the intrest rate?" << endl;
  cin >> Intrest;
  Intrest = Intrest/100;

  cout << "How many times is it compounded?" << endl;
  cin >> Compounded;

  Amount = Principal * pow((1+ (Intrest/Compounded)),Compounded);

  cout << "The total amount is: " <<  fixed << setprecision(2) << Amount << endl;

  //Problem: decimals further out
  //Solution: setprecision(2): sets the decimal to be two out
}