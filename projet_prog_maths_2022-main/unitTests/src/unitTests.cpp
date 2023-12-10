#include <random>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>
#include <chrono>
#include <functional>

#include "Rational.hpp"

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST (RationalConstructors, intConstructor)
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribNumerator(-100,100);
  std::uniform_int_distribution<int> distribDenominator(0,100);

  int a = distribNumerator(generator);
  int b = distribDenominator(generator);
  int pgcd = std::gcd(a,b);

  RationalNumber num = RationalNumber(a,b);

  a = a/pgcd;
  b = b/pgcd;

  ASSERT_EQ(a, num.numerator);
  ASSERT_EQ(b, num.denominator);

}

///////////////////////////////////////////////////////

TEST (RationalConstructors, copyConstructor)
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribNumerator(-100,100);
  std::uniform_int_distribution<int> distribDenominator(0,100);

  int a = distribNumerator(generator);
  int b = distribDenominator(generator);

  RationalNumber num1 = RationalNumber(a,b);
  RationalNumber num2 = num1;

  ASSERT_EQ(num1.numerator, num2.numerator);
  ASSERT_EQ(num1.denominator, num2.denominator);

}

///////////////////////////////////////////////////////

TEST (RationalConstructors, doubleConstructor)
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_real_distribution<double> distribDouble(-100,100);

  double a = distribDouble(generator);

  RationalNumber num = RationalNumber(a);
  double b = static_cast<double>(num.numerator)/num.denominator;

  //std::cout<<a<<'\n'<<num<<std::endl;

  ASSERT_NEAR(a, static_cast<double>(num.numerator)/num.denominator, pow(10, -6));

}


//////////////////////////////////////////
// ARITHMETIC //
/////////////////////////////////////////

TEST (RationalArithmetic, plus) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber  num2 = RationalNumber(c,d);
RationalNumber num3 = num1 +  num2;

ASSERT_NEAR(static_cast<double>(num3.numerator)/num3.denominator, static_cast<double>(a)/b + static_cast<double>(c)/d, pow(10,-6));
}

/////////////////////////////////////////

TEST (RationalArithmetic, minus) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber  num2 = RationalNumber(c,d);
RationalNumber num3 = num1 - num2;

ASSERT_NEAR(static_cast<double>(num3.numerator)/num3.denominator, static_cast<double>(a)/b - static_cast<double>(c)/d, pow(10,-6));
}

/////////////////////////////////////////

TEST (RationalArithmetic, multiply) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber  num2 = RationalNumber(c,d);
RationalNumber num3 = num1 * num2;

ASSERT_NEAR(static_cast<double>(num3.numerator)/num3.denominator, static_cast<double>(a)/b * static_cast<double>(c)/d, pow(10,-6));
}

/////////////////////////////////////////

TEST (RationalArithmetic, inverse) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);

RationalNumber num2 = num1.inverse();
RationalNumber num3 = num1*num2;

ASSERT_EQ(num3.numerator, num3.denominator);
}

/////////////////////////////////////////


TEST (RationalArithmetic, abs) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);

if (a<0)
{
  ASSERT_EQ(num1.abs().numerator, -num1.numerator);
}
else
{
  ASSERT_EQ(num1.abs().numerator, num1.numerator);
}

}

/////////////////////////////////////////

TEST (RationalArithmetic, divide) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = RationalNumber(c,d);

RationalNumber num3 = num1/num2;
RationalNumber num4 = num1*num2.inverse();

ASSERT_EQ(num3.numerator, num4.numerator);
ASSERT_EQ(num3.denominator, num4.denominator);
}

/////////////////////////////////////////

TEST (RationalArithmetic, pow) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int n = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = num1.powRatio(n);
   
ASSERT_NEAR(static_cast<double>(num2.numerator)/num2.denominator, static_cast<double>(pow(a,n))/pow(b,n), pow(10,-1));
}

/////////////////////////////////////////


TEST (RationalArithmetic, cos) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = cosRatio(num1);

ASSERT_NEAR(static_cast<double>(num2.numerator)/num2.denominator, std::cos(static_cast<double>(a)/b), pow(10, -5));

}

/////////////////////////////////////////

TEST (RationalArithmetic, sin) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = sinRatio(num1);

ASSERT_NEAR(static_cast<double>(num2.numerator)/num2.denominator, std::sin(static_cast<double>(a)/b), pow(10, -5));

}


/////////////////////////////////////////

TEST (RationalArithmetic, sqrt) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = sqrtRatio(num1);

ASSERT_NEAR(static_cast<double>(num2.numerator)/num2.denominator, std::sqrt(a)/std::sqrt(b), pow(10, -1));

}

/////////////////////////////////////////

TEST (RationalArithmetic, exp) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = expRatio(num1);

ASSERT_NEAR(static_cast<double>(num2.numerator)/num2.denominator, std::exp(static_cast<double>(a)/b), pow(10, -7));

}


/////////////////////////////////////////
//COMPARATORS//
/////////////////////////////////////////

TEST (RationalComparators, strictInf) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = RationalNumber(c,d);
RationalNumber num3 = num1 - num2;
RationalNumber num4 = num2 - num1;

if (num1<num2)
{
    ASSERT_LT(num3.numerator,0);
    ASSERT_GT(num4.numerator,0);
}
}

/////////////////////////////////////////

TEST (RationalComparators, strictSup) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber  num2 = RationalNumber(c,d);
RationalNumber num3 = num1 - num2;
RationalNumber num4 = num2 - num1;

if (num1>num2)
{
    ASSERT_LT(num4.numerator,0);
    ASSERT_GT(num3.numerator,0);
}
}

////////////////////////////////////////////

TEST (RationalComparators, inf) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber  num2 = RationalNumber(c,d);
RationalNumber num3 = num1 - num2;
RationalNumber num4 = num2 - num1;

if (num1<=num2)
{
    ASSERT_LE(num3.numerator,0);
    ASSERT_GE(num4.numerator,0);
}
}

////////////////////////////////////////////

TEST (RationalComparators, sup) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber  num2 = RationalNumber(c,d);
RationalNumber num3 = num1 - num2;
RationalNumber num4 = num2 - num1;

if (num1>=num2)
{
    ASSERT_LE(num4.numerator,0);
    ASSERT_GE(num3.numerator,0);
}
}

/////////////////////////////////////////

TEST (RationalComparators, equals) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = RationalNumber(c,d);

if (num1==num2)
{
  ASSERT_EQ((num1-num2).numerator,0);
}
else
{
  ASSERT_NE((num1-num2).numerator,0);
}
}

/////////////////////////////////////////

TEST (RationalComparators, different) {

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 generator(seed);
std::uniform_int_distribution<int> distribNumerator(-100,100);
std::uniform_int_distribution<int> distribDenominator(0,100);

int a = distribNumerator(generator);
int b = distribDenominator(generator);
int c = distribNumerator(generator);
int d = distribDenominator(generator);

RationalNumber num1 = RationalNumber(a,b);
RationalNumber num2 = RationalNumber(c,d);

if (num1!=num2)
{
  ASSERT_NE((num1-num2).numerator, 0);
}
else
{
  ASSERT_EQ((num1-num2).numerator,0);
}
}




