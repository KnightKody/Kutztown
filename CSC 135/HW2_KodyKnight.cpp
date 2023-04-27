#include <iostream>
#include <iomanip>

using namespace std;

int Instructions()
{
  int num1;
  cout << "There is 15% off of eBooks Right now!\nHow many would you like to order?" << endl;
  cin >> num1;
  if (num1 < 0)
  {
    exit(0);
  }

  cout << "\n" << endl;
  cout << "You have ordered " << setprecision(2) << num1 << " eBooks!" << endl;
  return num1;
}

double SubTotal(int eBooks, double cost)
{
  double Total = eBooks * cost;
  cout << "Your SubTotal is $" << setprecision(2) << Total << endl;
  return Total;
}

double Discount(int Total, double Disc)
{
  double Disc1 = (Total*Disc);
  cout << "The total Discount for the books is $" << setprecision(2) << Disc1 << endl;
  return Disc1;
}

double TotalifyMe(double Disc1, double Total)
{
  double Super_Total = Total-Disc1;
  return Super_Total;
}



int main() {
  
  const double Cost = 8.99;
  const double Discounted = 0.15;
  cout << showpoint;
  cout << fixed << showpoint;
  int Total_Books = Instructions();
  cout << "\n" << endl;
  int Total1 = SubTotal(Total_Books,Cost);
  cout << "\n" << endl;
  double Total_Discount = Discount(Total1,Discounted);
  cout << "\n" << endl;
  double Total = TotalifyMe(Total_Discount,Total1);
  cout << "The Total cost of your eBooks today is $" << setprecision(2) << Total << ". Have a nice day!" << endl;

}
