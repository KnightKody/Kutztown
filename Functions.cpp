#include <iostream>
#include <cmath>

using namespace std;

int multiply(int first, int second);
void printline();

int main()
{
  int x1,y1;
  printline();
  cin >> x1 >> y1;
  cout << "these are your 2 numbers! " << x1 << "," << y1 << endl;
  cout << x1 << " To the power of " << y1 << "= " << pow(x1,y1) << endl;
  cout << x1 << "times " << y1 << " is " << multiply(x1,y1) << endl;
  return 0;
}

int multiply(int first, int second)
{
  int answer;
  answer = first*second;
  return answer;
}

void printline();
{
  cout << "endter two numbers" << endl;
}
