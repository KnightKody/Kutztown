/*********************************************/
/* Author: Kody Knight                       */
/* Major: Computer Science                   */
/* Creation Date: 3/19/23                    */
/* Due Date: 3/22/2023                       */
/* Course: CSC136 010                        */
/* Professor Name: DR. Yong Zhang            */
/* Assignment: #3                            */
/* Filename: project3_KodyKnight.cpp         */
/*Purpose: To show what we have learned so   */
/*         far, along with taking in a file  */
/*         and organizing it, then outputing */
/*         it in the required statements     */
/*********************************************/



#include <iostream>
#include <fstream>
#include "extPersonType.h"
#include "personType.h"
#include "addressType.h"
#include "dateType.h"

using namespace std;


/*********************************************/
/* Function name: main()                     */
/* Parateters: none                          */
/* return statement: 0                       */
/* description: Read in a file, organize data*/
/*              and put it in a extPersonType*/
/*              list, then compare that list */
/*              to user inputs, to better    */
/*              find what they requested     */
/*********************************************/
int main(){
    ifstream fp;
    string L, FULLNAME, fName, lName, month, day, year, street, city, state, zip, phone, status;
    bool check = false;
    string input1;
    string input2;

    //Opens the file and checks if it opened right
    fp.open("addressData.txt");
    if(!fp){
        cout << "Error opening file!" << endl;
        exit(0);
    }

    //Gets first line in file which is the amount of people in the file
    getline(fp,L);
    int LineCount = atoi(L.c_str());
    extPersonType INFORMATION[LineCount];

    //Reads in the lines of the file and organizes the data into an array of extPersonType type
    for(int i = 0; i < LineCount; i++){
        getline(fp,FULLNAME);
        for(int i = 0; i < FULLNAME.length(); i++){
            if(FULLNAME[i] == ' '){
                fName = FULLNAME.substr(0,i);
                lName = FULLNAME.substr(i+1,FULLNAME.length());
            }
        }
        getline(fp,year);
        for(int i = 0; i < year.length();i++){
            if(year[i] == ' '){
                month = year.substr(0,i);
                year = year.substr(i+1, year.length());
            }
        }
        for(int i = 0; i < year.length();i++){
            if(year[i] == ' '){
                day = year.substr(0,i);
                year = year.substr(i+1, year.length());
            }
        }
        getline(fp, street);
        getline(fp, city);
        getline(fp, state);
        getline(fp, zip);
        getline(fp, phone);
        getline(fp, status);
        INFORMATION[i].setInfo(fName, lName, atoi(month.c_str()), atoi(day.c_str()), atoi(year.c_str()), street, city, state, zip, phone, status);
    }

    //While loop that is recurring until the user inputs a number
    //displays the menu and uses a switch statement to redirect the user
    string input;
    while(input != "6"){
        cout << endl;
        cout << "====================================" << endl;
        cout << "Welcome to the address book program." << endl;
        cout << "choose among the following options:" << endl;
        cout << "1: Search a person by last name:" << endl;
        cout << "2: Search a person by birthday:" << endl;
        cout << "3: Print the names of persons having birthday in a particular month:" << endl;
        cout << "4: Print the names of persons between two last names:" << endl;
        cout << "5: Print the names of person between two last names:" << endl;
        cout << "6: Terminate the program:" << endl;
        cout << "====================================" << endl;
        cout << endl;
        cout << "Enter a choice[1-6]: ";
        cin >> input;
        cout << endl;

        switch(input[0]){
            case '1':
            //Checks to see if inputed last name exist anywhere in the list of people
                cout << "Enter the last name of  the person: ";
                cin >> input;
                check = false;
                cout << endl;
                for(int i = 0; i < LineCount; i++){
                    if(INFORMATION[i].isLastName(input) == true){
                        INFORMATION[i].printInfo();
                        check = true;
                    }
                }
                if(check == false){
                    cout << "Person does not exist." << endl;
                }
                input = "0";
                break;
            case '2':
            //Checks by matching birthday for anyone in the list, prints names
                cout << "Enter the birthday (mm-dd-yyyy): ";
                cin >> input;
                check = false;
                //Seperates the string with a delimiter for month, day, and year
                month = input.substr(0,input.find("-"));
                input = input.substr(input.find("-")+1, input.length());
                day = input.substr(0,input.find("-"));
                input = input.substr(input.find("-")+1, input.length());
                year = input.substr(0, input.length());
                //loop to check all extPersonType objects in list to see if Date Of Birth matches up with input from user
                for(int i = 0; i < LineCount; i++){
                    if(INFORMATION[i].isDOB(atoi(month.c_str()),atoi(day.c_str()),atoi(year.c_str())) == true){
                        INFORMATION[i].printInfo();
                        cout << endl;
                        check = true;
                    }
                }
                if(check == false){
                    cout << "Person does not exist." << endl;
                }
                input = "0";
                break;
            case '3':
            //Checks by month and displays matching querys of all same month people
                cout << "Enter the month number: ";
                cin >> input;
                check = false;
                //loop to check all extPersonType objects in list  to see if there month matches with the input
                for(int i = 0; i < LineCount; i++){
                    if(INFORMATION[i].isMonth(atoi(input.c_str())) == true){
                        INFORMATION[i].personType::print();
                        cout << endl;
                        check = true;
                    }
                }
                if(check == false){
                    cout << "Person does not exist." << endl;
                }
                input = "0";
                cout << endl;
                break;
            case '4':
            //checks if there are names within a certain parameter EX: AAA CCC and prints people inbetween (not sorted)
                check = false;
                cout << "Enter starting last name: ";
                cin >> input1;
                cout << endl;
                cout << "Enter ending last name: ";
                cin >> input2;
                cout << endl;
                //loop to check all extPersonType objects in list to see if there is a matching query
                for(int i = 0; i < LineCount; i++){
                    lName = INFORMATION[i].personType::getLastName();
                    lName = lName.substr(0,input1.length());
                    for(int i = 0; i < input1.length();i++){
                        lName[i] = toupper(lName[i]);
                        input1[i] = toupper(input1[i]);
                        input2[i] = toupper(input2[i]);
                    }
                    if(input1 <= lName && input2 >= lName){
                        INFORMATION[i].personType::print();
                        cout << endl;
                        check = true;
                    }
                }
                if(check = false){
                    cout << "Person does not exist" << endl;
                    cout << endl;
                }
                input = '0';
                break;
            case '5':
            //Checks relation to person, if matching then prints name of person with matching relation
                cout << "Enter person type: Family, Friend, Business: ";
                cin >> input;
                cout << endl;
                check = false;
                //loop to check all extPersonType objects in list for a matching relationship
                for(int i = 0; i < LineCount; i++){
                    if(INFORMATION[i].isStatus(input) == true){
                        INFORMATION[i].personType::print();
                        cout << endl;
                        check = true;
                    }
                }
                if(check == false){
                    cout << endl;
                    cout << "Person does not exist" << endl;
                }
                break;
            case '6':
                exit(0);
                break;
        }
    }
}
