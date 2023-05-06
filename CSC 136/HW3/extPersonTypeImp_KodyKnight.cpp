#include <iostream>
#include "extPersonType.h"

void extPersonType::printInfo() const{
    personType::print();
    cout << endl;
    dob.printDate();
    cout << endl;
    address.print();
    cout << phoneNumber << endl;
    cout << personStatus << endl;
}

//set information to given values
void extPersonType::setInfo(string fName, string lName, int month, int day, int year, string street, string c, string s, string z, string phone, string pStatus){
    personType::setName(fName, lName);
    dob.setDate(month, day, year);
    address.setAddress(street, c, s, z);
    phoneNumber = phone;
    personStatus = pStatus;
}

//return true is last name is lName
bool extPersonType::isLastName(string lName) const{
    if(personType::getLastName() == lName){
        return true;
    }
    return false;
}

//store address into the reference parameters
void extPersonType::getAddress(string& sAddress, string& c, string& s, string& z){
    address.getAddress(sAddress, c, s, z);
}

//return status
string extPersonType::getStatus() const{
    return personStatus;
}

//return phone number
string extPersonType::getPhoneNumber() const{
    return phoneNumber;
}

//return true if status is equal to the given value
bool extPersonType::isStatus(string status){
    if(personStatus == status){
        return true;
    }
    return false;
}

//return true if birthday is equal to given values
bool extPersonType::isDOB(int month, int day, int year){
    if(dob.getMonth() == month && dob.getDay() == day && dob.getYear() == year){
        return true;
    }
    return false;
}

//store birthdays into the reference parameters
void extPersonType::getDOB(int& month, int& day, int& year){
    month = dob.getMonth();
    day = dob.getDay();
    year = dob.getYear();
}

//return true if month is equal to the given value
bool extPersonType::isMonth(int month) const{
    if(dob.getMonth() == month){
        return true;
    }
    return false;
}

//constructor
extPersonType::extPersonType(
    string fName, string lName, 
    int month, int day, int year, 
    string street, string c, string s, string z, 
    string phone, string pStatus) :
    personType(fName, lName) ,
    dob(month, day, year) ,
    address(street, c, s ,z) ,
    phoneNumber(phone) , 
    personStatus(pStatus)
    {
        //exampls of a diffrent way to do it, the above way is faster overall
        //dob = dateType(month, day, year);
        //address = addressType(street, c, s, z);
        //phoneNumber = phone;
        //personStatus = pStatus;
    }