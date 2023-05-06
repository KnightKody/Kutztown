/***************************************/
/* Author: Kody Knight                 */
/* Major: Computer Science             */
/* Creation Date: 2/17/2023            */
/* Due Date: Febuary 27, 2023          */
/* Course CSC136 010                   */
/* Professor Name: Dr. Zhang           */
/* Filename: project2_KodyKnight.cpp   */
/* Purpose: This program will read     */
/*          in a file containing the   */
/*          number of books, and there */
/*          information and display    */
/*          them accordingly           */
/***************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "bookTypeImp_KodyKnight.cpp"

using namespace std;

//Reads in the data from the file
void readData(ifstream & fp, int lineNumber, bookType books[]);
//Prints options to prefore on each book
void bookOptions(int lineNumber, bookType books[]);


/************************************/
/* Function name: Main              */
/* Description: initalizes array of */
/*              booktype that is of */
/*              size how many books */
/*              there are in a file */
/*                                  */
/* Parameters: none                 */
/************************************/
int main(){
    ifstream fp;
    int lineNumber;
    fp.open("bookData.txt");
    if(!fp){
        cout << "Error opening file." << endl;
        exit(0);
    }

    fp >> lineNumber;
    bookType books[lineNumber];

    readData(fp, lineNumber, books);

    bookOptions(lineNumber, books);
    return 0;
}

/*************************************/
/* Function name: readData           */
/* Description: initalizes array of  */
/*              booktype that is of  */
/*              size how many books  */
/*              there are in a file  */
/*                                   */
/* Parameters: ifstream of file, how */
/*             many books there are, */
/*             array of booktype     */
/*************************************/
void readData(ifstream & fp, int lineNumber, bookType books[]){
    string BT, BI, BP, Author, Auth[4], PLACEHOLDER;
    int BPY, Q, NumA;
    double P;
    getline(fp,PLACEHOLDER);
    for(int i = 0; i < lineNumber;i++){
        getline(fp,PLACEHOLDER);
        BT = PLACEHOLDER;
        getline(fp,PLACEHOLDER);
        BI = PLACEHOLDER;
        getline(fp,PLACEHOLDER);
        BP = PLACEHOLDER;
        getline(fp,PLACEHOLDER);
        BPY = atoi(PLACEHOLDER.c_str());
        getline(fp,PLACEHOLDER);
        P = atof(PLACEHOLDER.c_str());
        getline(fp,PLACEHOLDER);
        Q = atoi(PLACEHOLDER.c_str());
        getline(fp,PLACEHOLDER);
        NumA = atoi(PLACEHOLDER.c_str());
        
        for(int j = 0; j < NumA; j++){
            getline(fp,PLACEHOLDER);
            Author = PLACEHOLDER;
            Auth[j] = Author;
        }
        books[i].setBookInfo(BT, BI, BP, BPY, Auth, P, Q, NumA);
    }
    fp.close();
}

/*************************************/
/* Function name: bookOptions        */
/* Description: display information  */
/*              on selected books    */
/*                                   */
/* Parameters: number of books,      */
/*             books array           */
/*************************************/
void bookOptions(int lineNumber, bookType books[]){
    string input;
    bool exist = false;
    char c;

    while(true){
        cout << "\n======================================" << endl;
        cout << "[1] print a list of books" << endl;
        cout << "[2] Print a list of books and ISBN numbers" << endl;
        cout << "[3] To search a book by ISBN" << endl;
        cout << "[4] To update the number of copies" << endl;
        cout << "[5] To print books data" << endl;
        cout << "[6] Exit the program" << endl;
        cout << "======================================" << endl;
        cin >> c;
        system("clear");
        switch(c){
            case '1':
                cout << "======================================" << endl;
                for(int i = 0; i < lineNumber; i++){
                    books[i].printbookTitle();
                }
                cout << "======================================" << endl;
                break;
            case '2':
                cout << "======================================" << endl;
                for(int i = 0; i < lineNumber; i++){
                    books[i].printbookTitleAndISBN();
                }
                cout << "======================================" << endl;
                break;
            case '3':
                exist = false;
                cout << "Enter the ISBN of a book:" << endl;
                cin >> input;
                for(int i = 0; i < lineNumber; i++){
                    if(books[i].isISBN(input) == true){
                        cout << "======================================" << endl;
                        books[i].printInfo();
                        cout << "======================================" << endl;
                        exist = true;
                        break;
                    }
                }
                if(exist != true){
                    cout << "\nBook does not exist." << endl;
                }
                break;
            case '4':
                exist = false;
                cout << "Enter the ISBN of a book:" << endl;
                cin >> input;
                for(int i = 0; i < lineNumber; i++){
                    
                    if(books[i].isISBN(input) == true){
                        cout << "======================================" << endl;
                        books[i].printInfo();
                        cout << "======================================" << endl;
                        cout << "Enter amount of copies" << endl;
                        cin >> input;
                        books[i].updateQuantity(atoi(input.c_str()));
                        cout << "======================================" << endl;
                        books[i].printInfo();
                        cout << "======================================" << endl;
                        exist = true;
                        break;
                    }
                }
                if(exist != true){
                    cout << "\nBook does not exist." << endl;
                }
                break;
            case '5':
                cout << "======================================" << endl;
                for(int i = 0; i < lineNumber; i++){
                    books[i].printInfo();
                    cout << "======================================" << endl;
                }
                break;
            case '6':
                exit(0);
        }
    }
}
