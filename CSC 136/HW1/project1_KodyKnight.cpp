/*-----------------------------------------------------------
Author: Kody Knight                            
Major: Computer Science                        
Minor: Mathematics                             
Creation Date: February 6, 2023                
Course: CSC136 - 010                       
Professor Name: Dr. Zhang                      
Assignment: #1                                  
Filename: project1_KodyKnight.cpp               
Purpose: This program will take in a text file consisting of
         Student information, first name, last name, and test
         score, outputs neatly there grade, and highest
         scoring students.
-----------------------------------------------------------*/

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

/*-----------------------------------------------------------
Struct of studentType, processes information on students
-----------------------------------------------------------*/
struct studentType {
  string studentFName;
  string studentLName;
  int testScore;
  char grade;
};

/*-----------------------------------------------------------
  Reads in data from the file containing student informatio and
  puts it into a struct
-----------------------------------------------------------*/
void readIn(studentType[]);

/*-----------------------------------------------------------
  Takes in the tesScore and calculates the grades accordingly
-----------------------------------------------------------*/
void assignGrade(studentType[]);

/*-----------------------------------------------------------
  Finds the highest score and then returns it as a int
-----------------------------------------------------------*/
int findHighest(studentType[]);

/*-----------------------------------------------------------
  does any final calculations of searches before printing out 
  the final list of students along with those at the top of 
  there class
-----------------------------------------------------------*/
void printStudents(studentType[]);

/*-----------------------------------------------------------
  main runs the created cuntions and initilizes the struct
-----------------------------------------------------------*/
int main() {
  studentType students[20];
  readIn(students);
  assignGrade(students);
  printStudents(students);
}

/*-----------------------------------------------------------
Function name: readIn

Description: Reads in data from the file containing student
information and puts it into a struct

parameters: the student array of struct
-----------------------------------------------------------*/
void readIn(studentType students[]) {
  ifstream fp;
  //opens the file
  fp.open("studentData.txt");
  //if file doesnt open properly say so
  if (!fp) {
    cout << "Error opening file" << endl;
    exit(0);
  }

  //for loop to read in the line data in parts
  for (int i = 0; i < 20; i++) {
    getline(fp, students[i].studentFName, ' ');
    getline(fp, students[i].studentLName, ' ');
    string c;
    getline(fp, c);
    int d = atoi(c.c_str());
    students[i].testScore = d;
  }
}

/*-----------------------------------------------------------
function name: assignGrade

description: assigns the proper grade based on test score

parameters: takes in student array of struct
-----------------------------------------------------------*/
void assignGrade(studentType students[]) {
  for (int i = 0; i < 20; i++) {
    if (students[i].testScore >= 90) {
      students[i].grade = 'A';
    } else if (students[i].testScore >= 80) {
      students[i].grade = 'B';
    } else if (students[i].testScore >= 70) {
      students[i].grade = 'C';
    } else if (students[i].testScore >= 60) {
      students[i].grade = 'D';
    } else {
      students[i].grade = 'F';
    }
  }
}

/*-----------------------------------------------------------
  function name: findHighest

  description: finds the highest score in the group of students and saves it

  parameters: student array of struct

  returns: the highest school in the array
-----------------------------------------------------------*/
int findHighest(studentType students[]) {
  int score = 0;
  //for loop to check for the highest score among the students
  for (int i = 0; i < 20; i++) {
    if (students[i].testScore > score) {
      score = students[i].testScore;
    }
  }
  //returns the highest score
  return score;
}

/*-----------------------------------------------------------
  function name: printStudents

  description: calculate any final things and prints out the 
  students in a list, along with those with the highest grade 
  
  parameters: the students array of struct
-----------------------------------------------------------*/
void printStudents(studentType students[]) {
  int highest = findHighest(students); // returns the highest score
  int s = 0;
  // for loop that finds the length of all the strings and saves the longest string length
  for (int i = 0; i < 20; i++) {
    string str = (students[i].studentLName + ", " + students[i].studentFName);
    int k;
    for (k = 0; str[k]; k++)
      ;
    if (k >= s) {
      s = k;
    }
  }

  cout << "Student Name       Test Score     Grade" << endl;
  //for loop to print out all of the students data
  for (int i = 0; i < 20; i++) {
    string c = students[i].studentLName + ", " + students[i].studentFName;
    cout << c;
    int k;
    //for loop to find length of string
    for (k = 0; c[k]; k++);
    //for loop to determin how much spacing is needed by sutracing longest string length from current string length
    for (int j = 0; j < (s - k); j++) {
      cout << " ";
    }
    cout << "       " << students[i].testScore << setw(10) << students[i].grade << endl;
  }
  
  cout << endl;
  cout << "Highest score: " << highest << endl;
  cout << "\nStudents having the highest test score:" << endl;
  //for loop to print out students with the highest acheiving score by going through students list
  for (int i = 0; i < 20; i++) {
    //checks if the students score is the highest score then prints to screen
    if (students[i].testScore == highest) {
      cout << students[i].studentLName << ", ";
      cout << students[i].studentFName << endl;
    }
  }
}