//main file
#include <iostream>
#include "fraction.cc"
using namespace std;

int main (void)
{
    fraction fAx,fAy,fBx,fBy,fCx,fCy,fDx,fDy;
    cout<<"This Program will Calculate the Intersection of 2 Line Segments you Input"<<endl;
    cout<<"Each Line Segment is made of 2 Points"<<endl;
    cout<<"Each Point is in the form of P(x y)"<<endl;
    cout<<"Enter Fractions in the form of integers [Numerator,Denominator]"<<endl;
    cout<<"Enter Line Segment 1, Point A(x y)"<<endl;
    cin>>fAx fAy;
    cout<<"Enter Line Segment 1, Point B(x y)"<<endl;
    cin>>fBx fBy;
    cout<<"Enter Line Segment 2, Point C(x y)"<<endl;
    cin>>fCx fCy;
    cout<<"Enter Line Segment 2, Point D(x y)"<<endl;
    cin>>fDx fDy;
    point p1(fraction fAx,fraction fAy);
    point p2(fraction fBx,fraction fBy);
    point q1(fraction fCx,fraction fCy);
    point q2(fraction fDx,fraction fDy);
    point R=p2-p1;//Distance between the 2 points of line segment p
    point S=q2-q1;
    point Z=q1-p1;//Distance between the inital points of line segments p and q
    fraction Xt=Z*S;
    fraction Xu=Z*R;
    fraction Y=R*S;
    if (Y==0)
    {
        if (Xt==0)
        {
            cout<<"Line Segments are Collinear"<<endl;
        }
        else
        {
            cout<<"Line Segments are Parallel"<<endl;
        }
    }
    else
    {
        fraction T=Xt/Y;
        fraction U=Xu/Y;
        if (T>=0&&T<=1&&U>=0&&U<=1)
        {
            cout<<"Line Segments Intersect at Point "<<(p1+(R*T))<<endl;
        }
        else
        {
            cout<< "Line Segments Don't Intersect"<<endl;
        }
    }
    return 0;
}
