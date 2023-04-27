#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

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
  int people;
  double SubTotal = 0;
  string First_Line;
  ifstream inData;
  string File_Name;
  cout << "What is the name of your file?" << endl;
  cin >> File_Name;

  inData.open(File_Name);
  cout << showpoint << fixed;
  if(!inData)
  {
    cout << "File Not Found" << endl;
    return 0;
  }
  else
  {
    while(!inData.eof())
    {
      inData >> First_Line;
      people = stoi(First_Line);
      if(people <= 0)
      {
        cout << "There are zero people at this table, please wait to be seated!" << endl;

      }
      else
      {
        for(int i = 0; i < people; i++)
        {
          inData >> First_Line;
          SubTotal =SubTotal + stod(First_Line);
        }
        cout << "The Subtotal is: " << setprecision(2) << SubTotal << endl;
        cout << "The Sales Tax is: " << setprecision(2) << SalesTax(SubTotal) << endl;
        cout << "The Tip will be: " << setprecision(2) << Tip(SubTotal, people) << endl;
        cout << "The total cost is: " << setprecision(2) << FinalCost(SubTotal, SalesTax(SubTotal), Tip(SubTotal,people)) << endl;
      }
      cout << "-------------------------------------------" << endl;
      SubTotal = 0;
      people = 0;
    }
    inData.close();
  }
  return 0;
}
