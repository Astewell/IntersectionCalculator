//main file
#include <iostream>
#include "fraction.cc"
using namespace std;

int main (void)
{
    fraction fAx,fAy,fBx,fBy,fCx,fCy,fDx,fDy;
    cout<<"This Program will Calculate the Intersection of 2 Line Segments you Input"<<endl;
    cout<<"Each Line Segment is made of 2 Points"<<endl;
    cout<<"Each Point is in the form of P(x,y)"<<endl;
    cout<<"Enter Fractions in the form of integers (Numerator,Denominator)"<<endl;
    cout<<"For Line Segment 1, Input Point Ax,y (X,'Enter',Y)"<<endl;
    cin>>fAx>>fAy;
    cout<<"For Line Segment 1, Input Point Bx,y (X,'Enter',Y)"<<endl;
    cin>>fBx>>fBy;
    cout<<"For Line Segment 2, Input Point Cx,y (X,'Enter',Y)"<<endl;
    cin>>fCx>>fCy;
    cout<<"For Line Segment 2, Input Point Dx,y (X,'Enter',Y)"<<endl;
    cin>>fDx>>fDy;
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
