//class functions file
#include <iostream>
#include "fraction.h"

//point properties
point::point(fraction fracX,fraction fracY)
{
    x=fracX;
    y=fracY;
}
fraction point::getX() const
{
    return x;
}
fraction point::getY() const
{
    return y;
}
point point::operator-(point p)
{
    return point(x-p.getX(),y-p.getY());
}
point point::operator+(point p)
{
    return point(x+p.getX(),y+p.getY());
}
point point::operator*(fraction p)
{
    return point(x*p,y*p);
}
fraction point::operator*(point p)
{
    return x*p.getY()-y*p.getX();
}
void point::set(fraction fracX,fraction fracY)
{
    x=fracX;
    y=fracY;
}
//fraction properties
fraction::fraction(int num,int den)
{
    numerator=num;
    denominator=den;
    reduce();
}
fraction::fraction()
{
    numerator=0;
    denominator=1;
    reduce();
}
fraction::fraction(int num)
{
    numerator=num;
    denominator=1;
    reduce();
}
fraction::fraction(float value)
{

}
int fraction::getnum()
{
    return numerator;
}
int fraction::getden()
{
    return denominator;
}
float fraction::getval()
{
    return (float)(numerator)/denominator;
}
void fraction::setnum(int newnum)
{

}
void fraction::setden(int newden)
{

}
//reduces to greatest common denominator
void fraction::reduce()
{
    int GCD=gcd(numerator,denominator);
    numerator/=GCD;
    denominator/=GCD;
}
//create gcd
int fraction::gcd(int a,int b)
{
    int r;
    while (b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
//positive num
void fraction::set(int _num, int _den)
{
    if(_num<0)
    {
        _num=-_num;
        _den=-_den;
    }
    int g=gcd(_num,_den);
    numerator=_num/g;
    denominator=_den/g;
}
//+,-,*,/,copy,paste
fraction fraction::operator+(const fraction &b)
{
    fraction newfrac;
    int n,d;
    n=numerator*b.denominator+b.numerator*denominator;
    d=denominator*b.denominator;
    newfrac.set(n,d);
    return (newfrac);
}
fraction fraction::operator-(const fraction &b)
{
    fraction newfrac;
    int n,d;
    n=numerator*b.denominator-b.numerator*denominator;
    d=denominator*b.denominator;
    newfrac.set(n,d);
    return (newfrac);
}
fraction fraction::operator*(const fraction &b)
{
    fraction newfrac;
    int n,d;
    n=numerator*b.numerator ;
    d=denominator*b.denominator;
    newfrac.set(n,d);
    return (newfrac);
}
fraction fraction::operator/(const fraction &b)
{
    fraction newfrac;
    int n,d;
    n=numerator*b.denominator;
    d=denominator*b.numerator;
    newfrac.set(n,d);
    return (newfrac);
}
fraction &operator+(fraction &alpha,fraction beta)
{
    int comden=alpha.getden()*beta.getden();
    int newnum=alpha.getnum()*beta.getden()+beta.getnum()*alpha.getden();
    fraction*sum=new fraction(newnum,comden);
    return *sum;
}
fraction &operator-(fraction &alpha,fraction beta)
{
    int comden=alpha.getden()*beta.getden();
    int newnum=alpha.getnum()*beta.getden()-beta.getnum()*alpha.getden();
    fraction*diff=new fraction(newnum,comden);
    return *diff;
}
fraction &operator*(fraction &alpha,fraction beta)
{
    int comden=alpha.getden()*beta.getden();
    int newnum=alpha.getnum()*beta.getnum();
    fraction *prod=new fraction(newnum,comden);
    return *prod;
}
fraction &operator/(fraction &alpha,fraction &beta)
{
    int comden=alpha.getden()*beta.getnum();
    int newnum=alpha.getnum()*beta.getden();
    fraction *quot=new fraction(newnum,comden);
    return *quot;
}
bool fraction::operator<(fraction b)
{
    int ad=numerator*b.getden();
    int bc=denominator*b.getnum();
    return ad<bc;
}
//fraction comparison
bool fraction::operator==(fraction b)
{
    return !(*this<b)&&!(b<*this);
}
bool fraction::operator!=(fraction b)
{
    return !(*this==b);
}
bool fraction::operator<=(fraction b)
{
    return *this==b||*this<b;
}
bool fraction::operator>(fraction b)
{
    return *this!=b&&!(*this<b);
}
bool fraction::operator>=(fraction b)
{
    return (*this>b||*this==b);
}
//operators for comparing integers
bool fraction::operator==(int n)
{
    fraction f(n);
    return *this==f;
}
bool fraction::operator!=(int n)
{
    fraction f(n);
    return *this!=f;
}
bool fraction::operator>=(int n)
{
    fraction f(n);
    return *this>=f;
}
bool fraction::operator<=(int n)
{
    fraction f(n);
    return *this<=f;
}
bool fraction::operator>(int n)
{
    fraction f(n);
    return *this>f;
}
bool fraction::operator < (int n)
{
    fraction f(n);
    return *this<f;
}
//output and input functions
ostream &operator<<(ostream &os,const fraction &f)
{
    os<<f.numerator<<"/"<<f.denominator;
    return os;
}
istream &operator>>(istream& is,fraction& f)
{
    int n;
    int d;
    is>>n;
    is>>d;
    f.set(n,d);
    return is;
}
ostream &operator<<(ostream &os,const point &p)
{
    os<<"("<<p.getX()<<", "<<p.getY()<<")";
    return os;
}
istream &operator<<(istream& is,point& p)
{
    fraction x;
    fraction y;
    is>>x;
    is>>y;
    p.set(x,y);
    return is;
}
