#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

bool calc[20];

void Scoring(double count, int student)
{
  for(int i = 0; i < 20; i++)
  {
    count = count + calc[i];
  }
    if(count >= 15)
    {
      cout << "student " << student << "\t\t Passed ";
      cout << "\t\t " << setprecision(2) << count;
      cout << "\t\t " << setprecision(2) << 20-count << "\t\t ";
    }
    else
    {
      cout << "student " << student << "\t\t Failed ";
      cout << "\t\t " << setprecision(2) << count;
      cout << "\t\t " << setprecision(2) << 20-count << "\t\t ";
    }
    for(int i = 0;i < 20;i++)
    {
      if(calc[i] == 0)
      {
        cout << i+1 << ","; 
      }
    }
    cout << endl;
    student = student+1;
}


int main() {
  char Answers[] = {'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A'};

  ifstream inData;
  char First_char;
  char Student_Answers[20];
  double counter;
  int student = 1;
  double score;
  cout << showpoint << fixed;

  cout << "Student Name\t Student Status\t Correct\t Incorrect\t Problem Questions." << endl;

  inData.open("driving.dat");
  while(!inData.eof())
  {
    counter = 0;
    for(int i = 0;i < 20;i++)
    {
      inData >> First_char;
      Student_Answers[i] = First_char;
    }
    for(int i = 0; i < 20;i++)
    {
      if(Answers[i] == Student_Answers[i])
      {
        calc[i] = true;
      }
      else
      {
        calc[i] = false;
      }
    }
    Scoring(counter,student);
    student = student+1;
  }
} 