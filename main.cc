//main file
#include <iostream>//for cin and cout
#include "fraction.cc"
using namespace std;

int main (void)
{
    fraction fAx,fAy,fBx,fBy,fCx,fCy,fDx,fDy;
    cout<<"Enter Fractions in the form of integers [Numerator,Denominator]"<<endl;
    cout<<"Enter a Fraction for Line Segment 1, Point Ax"<<endl;
    cin>>fAx;
    cout<<"Enter a Fraction for Line Segment 1, Point Ay"<<endl;
    cin>>fAy;
    cout<<"Enter a Fraction for Line Segment 1, Point Bx"<<endl;
    cin>>fBx;
    cout<<"Enter a Fraction for Line Segment 1, Point By"<<endl;
    cin>>fBy;
    cout<<"Enter a Fraction for Line Segment 2, Point Cx"<<endl;
    cin>>fCx;
    cout<<"Enter a Fraction for Line Segment 2, Point Cy"<<endl;
    cin>>fCy;
    cout<<"Enter a Fraction for Line Segment 2, Point Dx"<<endl;
    cin>>fDx;
    cout<<"Enter a Fraction for Line Segment 2, Point Dy"<<endl;
    cin>>fDy;
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
            cout<<"These Here Line Segments be Collinear"<<endl;
        }
        else
        {
            cout<<"Them There Line Segments is Parallel"<<endl;
        }
    }
    else
    {
        fraction T=Xt/Y;
        fraction U=Xu/Y;
        if (T>=0&&T<=1&&U>=0&&U<=1)
        {
            cout<<"Line Segments Seem to Intersect at point "<<(p1+(R*T))<<endl;
            cout<<"	               _        \n";
            cout<<"               /(|       \n";
            cout<<"              (  :       \n";
            cout<<"            ___\  \______\n";
            cout<<"          (____)   |     \n";
            cout<<"         (____)    |     \n";
            cout<<"          (____)   |     \n";
            cout<<"           (___)__.|_____\n";
        }
        else
        {
            cout<< "Line Segments Don't Appear to Intersect"<<endl;
        }
    }
    return 0;
}
