#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  cout << fixed;
  cout << showpoint;
  
  float a = 57.9999;
  double b = 200;
  double c = 200;

  cout << setprecision(3);
  cout << "a = " << a << " b =  " << b << " c =  " << c << endl;
  cout << left << setw(10) << a << " " << b << " " << c << endl;
  cout << right << setw(10) <<  a << " " << b << " " << c << endl;
  cout << internal << setw(10) << a << " " << b << " " << c << endl;
  for(int i = 0; i < 10; i++)
    {
      cout << setw(3) << "-";
    }
  cout << endl;
  if (b > c)
    {
      cout << b <<  " is greater than ." << c << endl;
    }
  else
    {
      cout << b <<  " is less than " << c << endl;
    }
  if (b==c)
    {
      cout << b << " is equal to " << c << endl;
    }
  
  char letter;
  cin >> letter;
  letter = toupper(letter);
  
  switch(letter)
    {
    case 'A':
      cout << "Avacodos" << endl;
      break;
    case 'B':
      cout << "Bananas" << endl;
      break;
    default:
      cout << "Not a valid answer" << endl;
    }
  return 0;
}
