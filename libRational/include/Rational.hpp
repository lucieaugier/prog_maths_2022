/**
 * @mainpage 
 */






/**
 * @file Rational.hpp
 * @author Adrix & Lu6
 * @version 0.1
 * @date 2022-12-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string> 
#include <cmath>
#include <numeric>

#ifndef __RATIONAL__HPP
#define __RATIONAL__HPP


/**
 * @brief Global variable which indicates how many iterations does the conversion algorithm from reals to rational numbers does
 */
constexpr int NB_ITER = 10;

/**
 * @brief Class defining a rational number for algebra operations.
 */
class RationalNumber
{

    public :

    long int numerator;             /*!< numerator of the rational number */
    unsigned long int denominator;  /*!< denominator of the rational number */

    public :

    /**
     * @brief Construct a new Rational Number object from two int a and b
     * 
     * @param a : the numerator of the Rational Number. Signed 
     * @param b : the denominator of the Rational Number. Unsigned
     */
    RationalNumber(long int a, unsigned long int b);

    /**
     * @brief Copy-constructor
     * 
     * @param val : the source Rational Number to be copied
     */
    RationalNumber(const RationalNumber &val);

    /**
     * @brief Construct a new Rational Number object from a real number
     * 
     * @param x : the real number converted
     */
    RationalNumber(const double x);

    /**
     * @brief Destroy the Rational Number object
     * 
     */
    ~RationalNumber()=default;


    //méthodes

    /**
     * @brief Add 2 Rational Numbers
     * 
     * @param val : Rational number to add to the calling rational number
     * @return the sum of the current rational number and the argument rational number
     */
    RationalNumber operator+(const RationalNumber &val) const ; 

    /**
     * @brief Substract a rational number to the calling rational number
     * 
     * @param val : rational number to substract
     * @return the substraction of the current rational number and the argument rational number
     */
    RationalNumber operator-(const RationalNumber &val) const; 


    /**
     * @brief Unary minus
     * 
     * @return the minus the calling rational number
     */
    RationalNumber operator-() const;



    /**
     * @brief Multiply a rational number to the calling rational number
     * 
     * @param val : rational number to multiply with
     * @return the multiplication of the current rational number and the argument rational number
     */
    RationalNumber operator*(const RationalNumber &val) const; 


    //valeur absolue
    //partie entière
    
    /**
     * @brief Inverse a rational number : a/b becomes b/a
     * 
     * @return the inverse of the current rational number
     */
    RationalNumber inverse() const;

    /**
     * @brief Give the absolute value of a rational number
     * 
     * @return the absolute value of the current rational number
     */
    RationalNumber abs() const;

    /**
     * @brief Give the integer part of a rational number
     * 
     * @return the result of the integer division of the numerator by the denominator of the current rational number 
     */
    int integerPart() const;

    /**
     * @brief Divide a rational number by another one
     * 
     * @param val : The rationel number by which to divide the current rationel number
     * @return the result of the division 
     */
    RationalNumber operator/(const RationalNumber &val) const;


    /**
     * @brief Compare if the current rational number is strictly less than another one 
     * 
     * @param val : Rational number with which to compare the current rational number 
     * @return true if the current rational number is stricty less than val
     * @return false if the current rational number is greater than or equal to val
     */
    bool operator<(const RationalNumber &val) const;




    /**
     * @brief Compare if the current rational number is strictly greater than another one 
     * 
     * @param val : Rational number with which to compare the current rational number 
     * @return true if the current rational number is stricty greater than val
     * @return false if the current rational number is less than or equal to val
     */
    bool operator>(const RationalNumber &val) const;




    /**
     * @brief Compare if the current rational number is greater than or equal to another one 
     * 
     * @param val : Rational number with which to compare the current rational number 
     * @return true if the current rational number is greater than or equal to val
     * @return false if the current rational number is strictly less than val
     */
    bool operator>=(const RationalNumber &val) const;




    /**
     * @brief Compare if the current rational number is less than or equal to another one 
     * 
     * @param val : Rational number with which to compare the current rational number 
     * @return true if the current rational number is less than or equal to val
     * @return false if the current rational number is strictly greater than val
     */
    bool operator<=(const RationalNumber &val) const;

    


    /**
     * @brief Compare if the current rational number is equal to another one 
     * 
     * @param val : Rational number with which to compare the current rational number 
     * @return true if the current rational number is equal to val
     * @return false if the current rational number is different from val
     */
    bool operator==(const RationalNumber &val) const;




    /**
     * @brief Compare if the current rational number is different from another one 
     * 
     * @param val : Rational number with which to compare the current rational number 
     * @return true if the current rational number is different from val
     * @return false if the current rational number is equal to val
     */
    bool operator!=(const RationalNumber &val) const;





    /**
     * @brief Simplify a fraction to make it irreductible
     * 
     * @return the current rational number where its numerator and denominator have been divided by their GCD 
     */
    RationalNumber irreducible();
    



    /**
     * @brief Give the GCD of the numerator and denominator of a rational number
     * 
     * @return  the GCD of the numerator and denominator of the current rational number 
     * 
     */
    int pgcd() const;


    /**
         * @brief Give the power of a rational number
         * 
         * @param n exponent
         * @return the rational exponent n
         */
    RationalNumber powRatio(int n) const;


};  



/**
 * @brief overload the operator << for RationalNumber
 * 
 * @param stream : input stream
 * @param val : the rational number to outpout
 * @return the output stream containing the rational number written with its fractional form : a/b
 */
std::ostream& operator<< (std::ostream& stream, const RationalNumber& val);





/**
 * @brief Convert a real number into a rational number
 * 
 * @param x : real number to convert into a rational number
 * @param iter : number of passages in the algorithm loop to get precision
 * @return x converted into a rational number 
 */
RationalNumber convertDoubleToRatio(double x, int iter);





/**
     * @brief template function which scales a rational number with a constant value 
     * 
     * @tparam T type of the constant value
     * @param x constant value to multiply to the rational number
     * @param ratio rational number to scale
     * @return the scaled rational number
 */
template<typename T>
    RationalNumber operator*(const T& x, RationalNumber ratio){
        RationalNumber result = RationalNumber(x) * ratio;
        return result.irreducible();
    }


/**
     * @brief Give the cosinus of a rational number
     *
     * @param ratio rational number whose cosinus is wanted
     * @return the cosinus of the rational number 
     */
RationalNumber cosRatio(RationalNumber ratio);


/**
     * @brief Give the sinus of a rational number
     *
     * @param ratio rational number whose sinus is wanted
     * @return the sinus of the rational number 
     */
RationalNumber sinRatio(RationalNumber ratio);


/**
 * @brief Give the square root of a rational number
 * 
 * @param ratio rational number square root sinus is wanted
 * @return the square root of the rational number 
 */
RationalNumber sqrtRatio(RationalNumber ratio);


/**
 * @brief Give the exponential of a rational number
 * 
 * @param ratio rational number whose exponential is wanted
 * @return the exponential of the rational number 
 */
RationalNumber expRatio(RationalNumber ratio);

#endif