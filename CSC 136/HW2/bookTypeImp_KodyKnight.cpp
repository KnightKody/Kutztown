#include <iostream>
#include "bookType.h"

//default constructor, set everything to default values
bookType::bookType(){
     bookTitle = "";
     bookISBN = "";
     bookPublisher = "";
     bookPublishYear = 0;
     authors[4];
     price = 0.0;
     quantity = 0;
     noOfAuthors = 0;
}

//set the values, auth[] is an author array, noAuthors is the number
//of authors
void bookType::setBookInfo(string title, string ISBN, string Publisher, int PublishYear, string auth[], double cost, int copies, int noAuthors){
    bookTitle = title;
    bookISBN = ISBN;
    bookPublisher = Publisher;
    bookPublishYear = PublishYear;
    for(int i  = 0; i < 4;i++){
        authors[i] = auth[i];
    }
    price = cost;
    quantity = copies;
    noOfAuthors = noAuthors;
}

//set title to s
void bookType::setBookTitle(string s){
    bookTitle = s;
}

//set ISBN to s
void bookType::setBookISBN(string s){
    bookISBN = s;
}

//set price to cost
void bookType::setBookPrice(double cost){
    price = cost;
}

//set quantity to noOfCopies
void bookType::setCopiesInStock(int noOfCopies){
    quantity = noOfCopies;
}

//print the object information
void bookType::printInfo() const{
    cout << "Title: " << bookTitle << endl;
    cout << "ISBN: " << bookISBN << endl;
    cout << "Publisher: " << bookPublisher << endl;
    cout << "Year of Publication: " << bookPublishYear << endl;
    cout << "Number of Authors: " << noOfAuthors << endl;
    cout << "Authors: ";
    for(int i = 0; i < noOfAuthors; i++){
        cout << authors[i] << " ";
    }
    cout << endl;
    cout << "Price: " << price << endl;
    cout << "Quantities in stock: " << quantity << endl;
}

//return true if s is equal to ISBN
bool bookType::isISBN(string s) const{
    if(bookISBN == s){
        return true;
    }
    else{
        return false;
    }
}

//return true if s is equal to title
bool bookType::isTitle(string s) const{
    if(bookTitle == s){
        return true;
    }
    else{
        return false;
    }
}

//return true if s is one of the authors
bool bookType::isAuthor(string s) const{
    for(int i = 0;i < 4;i++){
        if(authors[i] == s){
            return true;
        }
    }
    return false;
}

//assign book title to s
void bookType::getBookTitle(string& s) const{
    
    s = bookTitle;
}

//assign ISBN to s
void bookType::getBookISBN(string& s) const{
    s = bookISBN;
}

//return book price
double bookType::getBookPrice() const{
    return price;
}

//return true if quantity is > 0
bool bookType::isInStock() const{
    if(quantity > 0){
        return true;
    }
    else{
        return false;
    }
}

//made a sale, decrease quantity by 1
void bookType::makeSale(){
    quantity--;
}

//print book price 
void bookType::printBookPrice() const{
    cout << "Price: " << price << endl;
}

//print book title
void bookType::printbookTitle() const{
    cout << "Title: " << bookTitle << endl;
}

//print title and ISBN
void bookType::printbookTitleAndISBN() const{
    cout << "Title: " << bookTitle << ";  ISBN: " << bookISBN << endl;
}

//print quantity
void bookType::showQuantityInStock() const{
    cout << "Quantities in stock: " << quantity << endl;
}

//add addBooks to quantity
void bookType::updateQuantity(int addBooks){
    quantity += addBooks;
    if(quantity < 0){
        quantity = 0;
    }
}
