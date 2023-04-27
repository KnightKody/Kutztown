#include <iostream>
#include <iomanip>

using namespace std;

int instructions()
{
  int People;
  cout << "How many people are at the table?" << endl;
  cin >> People;
  if(People <= 0)
  {
    exit(0);
  }
  else
  {
    return People;
  }
}

double SubTotal(int people)
{
  double SubTotal;
  double Holder;
  for(int i = 0; i < people;i++)
  {
    cout << "What is the price of meal " << (i+1) << endl;
    cin >> Holder;
    SubTotal = (SubTotal + Holder);
  }
  return SubTotal;
}

double SalesTax(double SubT)
{
  return (SubT*.05);
}

double Tip(double Taxed, int people)
{
  if(people < 5)
  {
    return (Taxed*0.16);
  }
  else
  {
    return (Taxed *0.20);
  }
}

double FinalCost(double SubT, double SalesT, double T)
{
  return (SubT + SalesT + T);
}

int main() {
  cout << showpoint << fixed;
  while(true)
  {
    cout << "Enter a value equal to or less then 0 to quit the program." << endl;
    int peep = instructions();
    double SB = SubTotal(peep);
    cout << "The SubTotal is $" << setprecision(2) << SB << endl;
    double ST = SalesTax(SB);
    cout << "The Sales tax is $" << setprecision(2) << ST << endl;
    double T = Tip(SB, peep);
    cout << "The tip is $" << setprecision(2) << T << endl;
    double FT = FinalCost(SB, ST, T);
    cout << "The Final Total is $" << setprecision(2) << FT << endl;
    cout << "\n" << endl;
  }
}