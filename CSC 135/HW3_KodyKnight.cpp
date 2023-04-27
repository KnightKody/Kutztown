#include <iostream>
#include <iomanip>

using namespace std;
double instructions()
{
  double Square_Feet = -1;
  while(Square_Feet < 0)
  {
     cout << "How many Square feet of wall space needs to be painted?" << endl;
     cin >> Square_Feet;
  }
  return Square_Feet;
}

double paint(double Square_Feet)
{
  double PPG;
  while (PPG < 10.00)
  {
  cout << "What is the price per gallon of paint?\n(Must be greater then or equal to $10.00)" << endl;
  cin >> PPG;
  }
  double Space = (Square_Feet/120);
  return (Space * PPG);
}

double labor(double Square_Feet)
{
  double Space = (Square_Feet/120);
  double Time = (Space * 8);
  return Time;
}

double total_Cost(double Time, double Paint_Cost)
{
  double Cost = (20.00 * Time);
  return (Cost + Paint_Cost);
}

void output(double Total_Cost, double Paint_Cost, double Labor)
{
  cout << setprecision(2) << "\nThe total cost of paint will be $" << Paint_Cost << endl;

  cout << setprecision(2) << "\nThe total cost of labor will be $" << (Labor*20) << endl;

  cout << setprecision(2) << "\nThe total cost of the job will be $" << Total_Cost << endl;
}


int main() {
  cout << showpoint;
  cout << fixed << showpoint;

  double SF = instructions(); // squarefooting

  double PC = paint(SF); //Cost of paint

  double T = labor(SF); //Time

  double TC = total_Cost(T,PC); //Total Cost

  output(TC,PC,T);
  return 0;

}