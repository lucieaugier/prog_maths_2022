#include <iostream>
#include <random>
#include <chrono>

#include "Rational.hpp"


int main(){

    std::cout<<"\n";
    //tests

    /////CONSTRCTORS/////
    std::cout<<"TESTS CONSTRUCTORS"<<std::endl;
    std::cout<<"RationalNumber num1 = RationalNumber(21,18);"<<std::endl; 
    std::cout<<"RationalNumber num2 = RationalNumber(-25,100);"<<std::endl;
    std::cout<<"RationalNumber num3 = num1;"<<std::endl;
    std::cout<<"RationalNumber num4 = RationalNumber(3,876); "<<std::endl;
    std::cout<<"RationalNumber num7 = RationalNumber(-3,876); "<<std::endl;
    RationalNumber num1 = RationalNumber(21,18);
    RationalNumber num2 = RationalNumber(-25,100);
    RationalNumber num3 = num1;
    RationalNumber num4 = RationalNumber(3,876); 
    RationalNumber num7 = RationalNumber(-3,876);

    /////PRINT/////
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<'\n'<<"num3 = "<<num3<<'\n'<<"num4 = "<<num4<<'\n'<<"num7 = "<<num7<<'\n'<<std::endl;
    
    /////INVERSE/////
    std::cout<<"TESTS INVERSE"<<std::endl;
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<'\n'<<"num1.inverse() = "<<num1.inverse()<<'\n'<<"num2.inverse() = "<<num2.inverse()<<'\n'<<std::endl;

    /////COMPARATORS/////
    std::cout<<"TESTS COMPARATORS"<<std::endl;
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<std::endl;
    bool comp1 = num1<num2;
    bool comp2 = num1>num2;
    bool comp3 = num1==num2;
    bool comp4 = num1<=num2;
    bool comp5 = num1>=num2;
    bool comp6 = num1!=num2;

    std::cout<<"num1<num2 returns : "<<comp1<<std::endl;
    std::cout<<"num1>num2 returns : "<<comp2<<std::endl;
    std::cout<<"num1==num2 returns : "<<comp3<<std::endl;
    std::cout<<"num1<=num2 returns : "<<comp4<<std::endl;
    std::cout<<"num1>=num2 returns : "<<comp5<<std::endl;
    std::cout<<"num1!=num2 returns : "<<comp6<<'\n'<<std::endl;

    /////ABSOLUTE VALUE/////
    std::cout<<"TESTS ABSOLUTE VALUE"<<std::endl;
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<std::endl;
    std::cout<<"num1.abs() = "<<num1.abs()<<std::endl;    
    std::cout<<"num2.abs() = "<<num2.abs()<<'\n'<<std::endl;  

    /////INTEGER PART/////    
    std::cout<<"TESTS INTEGER PART"<<std::endl;
    std::cout<<"num1 = "<<num1<<" = "<<static_cast<double>(num1.numerator)/num1.denominator<<std::endl;
    std::cout<<"num2 = "<<num2<<" = "<<static_cast<double>(num2.numerator)/num2.denominator<<std::endl;
    std::cout<<"num1.integerPart() = "<<num1.integerPart()<<std::endl;    
    std::cout<<"num2.integerPart() = "<<num2.integerPart()<<'\n'<<std::endl;   

    /////ADDITION/////
    std::cout<<"TEST ADDITION"<<std::endl;
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<std::endl;
    RationalNumber num5 = num1 + num2;
    std::cout<<"num1 + num2 = "<<num5<<'\n'<<std::endl;

    /////MULTIPLICATION/////
    std::cout<<"TEST MULTIPLICATION"<<std::endl;
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<std::endl;
    std::cout<<"num1 * num2 = "<<num1 * num2<<'\n'<<std::endl;

    /////OVERLOAD */////
    std::cout<<"TEST OVERLOAD *"<<std::endl;
    std::cout<<"num1 = "<<num1<<std::endl;
    std::cout<<"3*num1 = "<<3*num1<<std::endl;
    std::cout<<"3.5*num1 = "<<3.5*num1<<"\n"<<std::endl; 

    /////DIVISION/////
    std::cout<<"TEST DIVISION"<<std::endl;
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<std::endl;
    std::cout<<"num1 / num2 = "<<num1 / num2<<'\n'<<std::endl;
    
    /////SOUSTRACTION/////
    std::cout<<"TEST DIFFERENCE"<<std::endl;
    std::cout<<"num1 = "<<num1<<'\n'<<"num2 = "<<num2<<std::endl;
    RationalNumber num6 = num1 - num2;
    std::cout<<"num1 - num2 = "<<num6<<'\n'<<std::endl; 

    /////UNARUS MINUS/////
    std::cout<<"TEST UNARUS MINUS"<<std::endl;
    std::cout<<"num1 = "<<num1<<std::endl;
    std::cout<<"-num1 = "<<-num1<<"\n"<<std::endl; 


    /////COSINUS/////
    std::cout<<"TEST COSINUS"<<std::endl;
    std::cout<<"cosRatio(RationalNumber(M_PI)) = "<<cosRatio(RationalNumber(M_PI))<<"\n"<<std::endl;

    /////SINUS/////
    std::cout<<"TEST SINUS"<<std::endl;
    std::cout<<"sinRatio(RationalNumber(0)) = "<<sinRatio(RationalNumber(0))<<"\n"<<std::endl;

    /////SQUARE ROOT/////
    std::cout<<"TEST SQUARE ROOT"<<std::endl;
    std::cout<<"sqrtRatio(RationalNumber(1,4)) = "<<sqrtRatio(RationalNumber(1,4))<<"\n"<<std::endl;

    /////POWER/////
    std::cout<<"TEST POWER"<<std::endl;
    std::cout<<"RationalNumber(1,2).powRatio(2) = "<<RationalNumber(1,2).powRatio(2)<<"\n"<<std::endl;

    /////EXPONENTIAL/////
    std::cout<<"TEST EXPONENTIAL"<<std::endl;
    std::cout<<"expRatio(RationalNumber(0)) = "<<expRatio(RationalNumber(0))<<"\n"<<std::endl;

     /////ERRORS HANDELING/////
    // RationalNumber num7 = RationalNumber (5,0);
    // RationalNumber num8 = RationalNumber (0);
    // RationalNumber num9 = RationalNumber (-1,5);
    // std::cout<<sqrtRatio(num9)<<std::endl;
    //RationalNumber num10 = num1/num8 ;
    //std::cout<<num1/num8<<std::endl;



    /////TESTS ON LARGE INT NUMBERS/////
    std::cout<<"TESTS ON LARGE INT NUMBERS"<<std::endl;
    std::cout<<"RationalNumber(100) returns : "<<RationalNumber(100)<<std::endl;
    std::cout<<"RationalNumber(1258) returns : "<<RationalNumber(1258)<<std::endl;
    std::cout<<"RationalNumber(10000) returns : "<<RationalNumber(10000)<<std::endl;
    std::cout<<"RationalNumber(100005000) returns : "<<RationalNumber(100005000)<<std::endl;
    std::cout<<"SEEMS OK"<<"\n"<<std::endl;
    //std::cout<<"RationalNumber(123.78) returns : "<<RationalNumber(123.78)<<"\n"<<std::endl;

    /////TEST ON LARGE double NUMBERS/////
    std::cout<<"TEST ON LARGE double NUMBERS"<<std::endl;
    std::cout<<"RationalNumber(101.1) returns : "<<RationalNumber(101.1)<<" and should return : "<<RationalNumber(1011,10)<<std::endl;
    std::cout<<"RationalNumber(1258.3) returns : "<<RationalNumber(1258.3)<<" and should return : "<<RationalNumber(12583,10)<<std::endl;
    std::cout<<"RationalNumber(10000.058) returns : "<<RationalNumber(10000.058)<<" and should return : "<<RationalNumber(10000058,1000)<<std::endl;
    std::cout<<"NOT OK"<<"\n"<<std::endl;

    /////TEST ON LARGE double NUMBERS/////
    std::cout<<"TEST ON LARGE double NUMBERS"<<std::endl;
    std::cout<<"RationalNumber(0.1) returns : "<<RationalNumber(0.1)<<" and should return : "<<RationalNumber(1,10)<<std::endl;
    std::cout<<"RationalNumber(0.01) returns : "<<RationalNumber(0.01)<<" and should return : "<<RationalNumber(1,100)<<std::endl;
    std::cout<<"RationalNumber(0.001) returns : "<<RationalNumber(0.001)<<" and should return : "<<RationalNumber(1,1000)<<std::endl;
    std::cout<<"RationalNumber(0.2) returns : "<<RationalNumber(0.2)<<" and should return : "<<RationalNumber(2,10)<<std::endl;
    std::cout<<"RationalNumber(0.02) returns : "<<RationalNumber(0.02)<<" and should return : "<<RationalNumber(2,100)<<std::endl;
    std::cout<<"RationalNumber(0.3) returns : "<<RationalNumber(0.3)<<" and should return : "<<RationalNumber(3,10)<<std::endl;
    std::cout<<"RationalNumber(0.0045) returns : "<<RationalNumber(0.0045)<<" and should return : "<<RationalNumber(45,10000)<<std::endl;
    std::cout<<"NOT OK"<<"\n"<<std::endl;


    return 0;
}
