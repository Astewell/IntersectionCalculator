//header file containing class definition
#include <iostream>
#ifndef _FRACTION_H
#define _FRACTION_H
using namespace std;//for standard library items

class fraction
{//start of member list
private://can't be accessed from outside the class/used for storage
    int numerator,denominator;
    int gcd(int a,int b);
public://can be accessed from outside to manipulate the class
    int a,b;
    fraction();
    ~fraction(void){}
    fraction(int num);
    fraction(float value);
    fraction(int numerator,int denominator);
    int getnum(),getden();
    float getval();
    void setnum (int newnum);
    void setden (int newden);
    void reduce();
    void set(int _num=0,int _den=1);
//friend functions can access private members of a class
    friend ostream& operator<<(ostream &,const fraction &);//const can examine the status of an object but cant change it
    friend istream& operator>>(istream &,const fraction &);
//fraction arithmatic operations
    fraction operator+(const fraction &);
    fraction operator-(const fraction &);
    fraction operator*(const fraction &);
    fraction operator/(const fraction &);
//compare integers
    bool operator==(int n);
    bool operator!=(int n);
    bool operator>=(int n);
    bool operator<=(int n);
    bool operator>(int n);
    bool operator<(int n);
//compare fractions
    bool operator==(fraction b);
    bool operator!=(fraction b);
    bool operator<=(fraction b);
    bool operator>=(fraction b);
    bool operator<(fraction b);
    bool operator>(fraction b);
};

class point
{
private:
    fraction x,y;
public:
    point(fraction x,fraction y);
    point operator+(point p);
    point operator-(point p);
    fraction operator*(point p);
    point operator*(fraction p);
    fraction getY() const;
    fraction getX() const;
    void set(fraction x,fraction y);
    friend ostream& operator<<(ostream &,const point &);
    friend istream& operator>>(istream &,const point &);
};

#endif
