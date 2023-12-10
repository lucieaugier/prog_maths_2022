#include "Rational.hpp"

#include <cstdlib>    
#include <cmath>      
#include <cassert>

/////CONSTRUCTORS/////

RationalNumber::RationalNumber(const long int a, const unsigned long int b)
: numerator(a), denominator(b)
{
    //assert ((denominator != 0) && "division by 0");
   (*this).irreducible();
}


RationalNumber::RationalNumber(const RationalNumber &val)
: numerator(val.numerator), denominator(val.denominator)
{
}


RationalNumber::RationalNumber(const double x)
:numerator(convertDoubleToRatio(x, NB_ITER).numerator), denominator(convertDoubleToRatio(x, NB_ITER).denominator)
{
}

/////METHODS/////

//sum
RationalNumber RationalNumber::operator+(const RationalNumber &val) const 
{
    RationalNumber result(0,1);
    result.numerator = numerator* static_cast<long int>(val.denominator) + static_cast<long int>(denominator)*val.numerator;
    result.denominator = denominator*val.denominator;
    return result.irreducible();
}


// operator - between two rationals
RationalNumber RationalNumber::operator-(const RationalNumber &val) const 
{
    RationalNumber result(0,1);
    result.numerator = numerator*static_cast<long int>(val.denominator) - static_cast<long int>(denominator)*val.numerator;
    result.denominator = denominator*val.denominator;
    return result.irreducible();
}

// operator - to get the opposite sign
RationalNumber RationalNumber::operator-() const
{
    RationalNumber result(0,1);
    result.numerator = -numerator;
    result.denominator = denominator;
    return result;
}  

// multiplication
RationalNumber RationalNumber::operator*(const RationalNumber &val) const
{
    RationalNumber result(0,1);
    result.numerator = numerator * val.numerator;
    result.denominator = denominator*val.denominator;
    return result.irreducible();
}

//inversion
RationalNumber RationalNumber::inverse() const {

    //if ( numerator == 0) throw std :: string ( " inverse this number will lead to a division by zero " );

    long int n = numerator;
    long unsigned int d = denominator; 
    long int tempN = n;

    if (n<0)
    {
        n= -d;
        d= -tempN;
    }

    else 
    {
        n= d;
        d= tempN;
    }

    return RationalNumber(n,d);
}


//absolute value
RationalNumber RationalNumber::abs() const
{
    RationalNumber result = RationalNumber(0,1);
    result.numerator = std::abs(numerator);
    result.denominator = denominator;
    return result;

}


//integer part
int RationalNumber::integerPart() const
{
    return numerator/denominator;
}


//division
RationalNumber RationalNumber::operator/(const RationalNumber &val) const
{
    RationalNumber result(0,1);

    if ( val.numerator == 0){
        throw std :: string ( " divide by zero " );
    }
        
    result.numerator = numerator * static_cast<long int>(val.denominator);

    long int tempD = result.denominator;
    tempD = static_cast<long int>(denominator)*val.numerator;

    if (tempD < 0)
    {
        result.numerator = -result.numerator;
        result.denominator = std::abs(tempD);
    }
    else 
    {
        result.denominator = tempD;
    }

    return result.irreducible();
}



/////COMPARATORS/////


bool RationalNumber::operator<(const RationalNumber &val) const 
{
    int a, b;
    a = numerator*val.denominator;
    b = denominator*val.numerator;

    if (a<b)
    {
        return true;
    }

    return false;
}


bool RationalNumber::operator>(const RationalNumber &val) const 
{
    int a, b;
    a = numerator*val.denominator;
    b = denominator*val.numerator;

    if (a>b)
    {
        return true;
    }

    return false;
}


bool RationalNumber::operator>=(const RationalNumber &val) const 
{
    int a, b;
    a = numerator*val.denominator;
    b = denominator*val.numerator;

    if (a>=b)
    {
        return true;
    }

    return false;
}


bool RationalNumber::operator<=(const RationalNumber &val) const 
{
    int a, b;
    a = numerator*val.denominator;
    b = denominator*val.numerator;

    if (a<=b)
    {
        return true;
    }

    return false; 

}

bool RationalNumber::operator==(const RationalNumber &val) const
{
    int a, b;
    a = numerator*val.denominator;
    b = denominator*val.numerator;

    if (a==b)
    {
        return true;
    }

    return false;
}


bool RationalNumber::operator!=(const RationalNumber &val) const
{
    int a, b;
    a = numerator*val.denominator;
    b = denominator*val.numerator;

    if (a!=b)
    {
        return true;
    }

    return false;
}

//irreducible
RationalNumber RationalNumber::irreducible(){
    int p = (*this).pgcd();
    if (p==0)
    {
        return *this;
    }
    
    if (p==1)
    {
        return *this;
    }
    else
    {
        numerator/=p;
        denominator/=p;
        return *this;
    }
}

//GCD
int RationalNumber::pgcd() const
{
    return std::gcd(numerator,denominator);
}

//pow
RationalNumber RationalNumber::powRatio(int n) const
{
    RationalNumber result(0,1);
    result.numerator = std::pow(numerator,n);
    result.denominator = std::pow(denominator,n);
    return result.irreducible();
}


/////FUNCTIONS/////

// << overload
std::ostream& operator<< (std::ostream& stream, const RationalNumber& val) {
stream << val.numerator << "/" << val.denominator;
return stream;
}

//conversion alorithm
RationalNumber convertDoubleToRatio(double x, int iter) 
{
    //if x negative
    if (x<0)
    {
        return -convertDoubleToRatio(std::abs(x),iter);
    }
    
    //stop conditions

    if (x==0 || iter==0)
    {
        return RationalNumber(0,1);
    }

    if (x<1)
    {
        return (convertDoubleToRatio(1/x,iter).inverse());
    }

    if (x>1)
    {
        double q = floor(x);
        return (RationalNumber(q,1) + convertDoubleToRatio(x-q,iter-1));  
    }

    return RationalNumber(1,1);
}

// cosinus
RationalNumber cosRatio(RationalNumber ratio){
    double cos = std::cos(static_cast<double>(ratio.numerator)/ratio.denominator);
    return RationalNumber(cos);
}

// sinus
RationalNumber sinRatio(RationalNumber ratio){
    double sin = std::sin(static_cast<double>(ratio.numerator)/ratio.denominator);
    return RationalNumber(sin);
}

// square root
RationalNumber sqrtRatio(RationalNumber ratio){

    //assert( (ratio.numerator >= 0) && "error: sqrtRatio : value should be positive");
    double sqrt = std::sqrt(static_cast<double>(ratio.numerator)/ratio.denominator);
    return RationalNumber(sqrt);
}


//exponential
RationalNumber expRatio(RationalNumber ratio){
    double exp = std::exp(static_cast<double>(ratio.numerator)/ratio.denominator);
    return RationalNumber(exp);
}

