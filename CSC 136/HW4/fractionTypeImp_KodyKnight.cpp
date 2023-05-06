#include "fractionType.h"

//FractionType constructor that makes a fraction with denomiator != 0
fractionType::fractionType(int num, int den){
    numerator = num;
    denominator = den;
    if(denominator == 0)
    {
        cout << "denominator cannont be zero" << endl;
        numerator = 0;
        denominator = 1;
    }
    else{
        int Great = gcd();
        numerator = num/Great;
        denominator = den/Great;
    }
}


//Overloadeds << to print num and den
ostream& fractionType::operator<<(ostream& out){
    out << numerator << " / " << denominator;
    return out;
}

//Overloadeds >> to take in a string and spit it into numbers
istream& fractionType::operator>>(istream& in){
    cout << "Enter fraction in form A / B" << endl;
    string FRACTION;
    in >> FRACTION;

    int length = FRACTION.length();
    int pos = FRACTION.find('/');
    numerator = atoi((FRACTION.substr(0,pos-1)).c_str());
    denominator = atoi((FRACTION.substr(pos+2,length)).c_str());
    return in;
}

//Overloads == to comapre fractionType
bool fractionType::operator==(const fractionType& Num) const{
    if((numerator == Num.numerator) && (denominator == Num.denominator)){
        return true;
    }
    return false;
}

//Overloads != to comapre fractionType
bool fractionType::operator!=(const fractionType& Num) const{
    if(numerator != Num.numerator || denominator != Num.denominator){
        return true;
    }
    return false;
}

//Overloads > to comapre fractionType
bool fractionType::operator>(const fractionType& Num) const{
    double TN = (double) numerator;
    double TD = (double) denominator;
    double TTN = (double) Num.numerator;
    double TTD = (double) Num.denominator;
    if((TN/TD) > (TTN/TTD)){
        return true;
    }
    return false;
}

//Overloads >= to comapre fractionType
bool fractionType::operator>=(const fractionType& Num) const{
    double TN = (double) numerator;
    double TD = (double) denominator;
    double TTN = (double) Num.numerator;
    double TTD = (double) Num.denominator;
    if(TN/TD >= TTN/TTD){
        return true;
    }
    return false;

}

//Overloads < to comapre fractionType
bool fractionType::operator<(const fractionType& Num) const{
    double TN = (double) numerator;
    double TD = (double) denominator;
    double TTN = (double) Num.numerator;
    double TTD = (double) Num.denominator;
    if((TN/TD) < (TTN/TTD)){
        return true;
    }
    return false;
}

//Overloads <=to comapre fractionType
bool fractionType::operator<=(const fractionType& Num) const{
    double TN = (double) numerator;
    double TD = (double) denominator;
    double TTN = (double) Num.numerator;
    double TTD = (double) Num.denominator;
    if(TN/TD <= TTN/TTD){
        return true;
    }
    return false;
}

//Overloads + to Add fractionType fractions together
fractionType fractionType::operator+(const fractionType& Num) const{
    int NNum = numerator*Num.denominator + Num.numerator*denominator;
    int NDen = denominator*Num.denominator;
    fractionType Temp3(NNum, NDen);
    int Great = Temp3.gcd();
    fractionType Temp4(Temp3.numerator/Great,Temp3.denominator/Great);
    return Temp4;
}

//Overloads - to subtract fractiontype fractions together
fractionType fractionType::operator-(const fractionType& Num) const{
    int NNum = numerator*Num.denominator - Num.numerator*denominator;
    int NDen = denominator*Num.denominator;
    fractionType Temp3(NNum, NDen);
    int Great = Temp3.gcd();
    fractionType Temp4(Temp3.numerator/Great,Temp3.denominator/Great);
    return Temp4;
}

//Overloads - to Multiply fractiontype fractions together
fractionType fractionType::operator*(const fractionType& Num) const{
    fractionType Temp1(numerator*Num.numerator,denominator*Num.denominator);
    int Great = Temp1.gcd();
    fractionType Temp2(Temp1.numerator/Great,Temp1.denominator/Great);
    return Temp2;
}

//Overloads - to divide fractiontype fractions together
fractionType fractionType::operator/(const fractionType& Num) const{
    if(Num.numerator == 0){
        return *this;
    }
    else{
        fractionType Temp1(numerator * Num.denominator,denominator * Num.numerator);
        int Great = Temp1.gcd();
        fractionType Temp2(Temp1.numerator,Temp1.denominator);
        return Temp2;
    }
}

//Overloads ++ add to fraction type (pre)
fractionType fractionType::operator++(){
    numerator = numerator + denominator;
    return *this;
}

//Overloads -- add to fraction type (pre)
fractionType fractionType::operator--(){
    numerator = numerator - denominator;
    return *this;
}

//Overloads ++ add to fraction type (post)
fractionType fractionType::operator++(int){
    fractionType Temp1(numerator,denominator);
    numerator = numerator + denominator;
    return Temp1;

}

//Overloads -- add to fraction type (post)
fractionType fractionType::operator--(int){
    fractionType Temp1(numerator,denominator);
    numerator = numerator - denominator;
    return Temp1;
}
