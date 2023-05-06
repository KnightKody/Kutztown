/**********************************************************************
    Author: Kody Knight
    Major: Computer Science
    Creation Date: 5/2/23
    Course: CSC136 010
    Professor Name: Zhang
    Assignment: CSC 136 Project 5
    Filename: project5_KodyKnight.cpp
    Purpose: To split a string using a linked list and return the pig 
             latin form of it to the user
**********************************************************************/
#include "linkedList.h"
#include <iostream>

using namespace std;

/***********************************************************************
    Function name:
    returns: 0, essentially an exit code
    Purpose: to take in a string, split it and rotate it with linked 
             list, then print the pig latin version of the word using 
             a string iterator
***********************************************************************/
int main() {
    string IN;
    char Vowles[12] = {'a','e','i','o','u','y','A','E','I','O','U','Y'};
    char way[4] = {'-','w','a','y'};
    linkedListType<char> charList;
    cout << "Enter a string: ";
    cin >> IN;
    cout << "\nThe string you entered is: " << IN << endl;
    int i;
    //add each char to the linked list
    for (i = 0; i < IN.length(); i++){
        charList.insertLast(IN[i]);
    }
    //I use goto here because I cant think of another way to do it, giving it a final use case it will ever have
    //I learned goto when I first started coding on my graphing calculator back in highschool
    for (i = 0; i < IN.length(); i++){
        for(int j = 0; j < 12; j++){
            if(IN[i] == Vowles[j]){
                goto Rotator;
            }
        }
    }
    i++;
    goto Rotator;
    
    Rotator:
        if(i == 0){ //case 1: if the vowel is the first letter
            for(int k = 0; k < 4; k++){
                charList.insertLast(way[k]);
            }
        }
        else if(i > IN.length()){ //case 2: if vowel is located somewhere in the linked list
            for(int k = 0; k < 4; k++){
                charList.insertLast(way[k]);
            }
        }
        else{ //case 3: if there is no vowel in the list at all
            charList.insertLast(way[0]);
            for(int j = 0; j < i; j++){
                charList.rotate();
            }
            charList.insertLast(way[2]);
            charList.insertLast(way[3]);
        }
    linkedListIterator<char> LLI(charList.begin());
    cout << "The pig latin form of the string: ";
    for(int i = 0; i < charList.length(); i++){ //Iterate through linked list and print one after the other
        cout << *LLI;
        ++LLI;
    }
    cout << endl;

    charList;
    return 0;
}
