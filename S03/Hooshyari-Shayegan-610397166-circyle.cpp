#include <iostream>
using namespace std;

#define pi 3.1415926535897932384

long double CalculateOverlap(long double x1,long double x2,long double y1,long double y2,long double r1,long double r2){
    long double d,ans,r12,r22,d2;
//    cout<<"x1:"<<x1<<" y1:"<<y1<<" x2:"<<x2<<" y2:"<<y2<<" r1:"<<r1<<" r2"<<r2;
    r12=r1*r1; r22=r2*r2;
    d=sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)  );
    d2=d*d;
    if( d> r1+r2 ) ans=0;
    else if( d<=abs(r2-r1) && r1>=r2  ) ans= pi*r22;
    else if( d<=abs(r2-r1) && r1<=r2  ) ans= pi*r12;
    else
    {
        long double phi= (acos((r12+d2-r22 )/(2*r1*d)))*2;
        long double theta= (acos((r22+d2-r12 )/(2*r2*d)))*2;
        long double area1= 0.5*theta*r22 -0.5*r22*sin(theta);
        long double area2=0.5*phi*r12-0.5*r12*sin(phi);
        ans= area1 + area2;
    }
    return ans;
}

int main()
{
    int circles_count;
    cin>>circles_count;
    int n = circles_count;
    auto ** circles_data = new long double *[3];
    for(int row=0;row<3;row++)
        circles_data[row] = new long double [circles_count];
    while(circles_count--)
    {
        cin>>circles_data[0][circles_count]>>circles_data[1][circles_count]>>circles_data[2][circles_count];
    }
    long double overlap = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            overlap += CalculateOverlap(
                    circles_data[0][i],
                    circles_data[0][j],
                    circles_data[1][i],
                    circles_data[1][j],
                    circles_data[2][i],
                    circles_data[2][j]
            );
        }
    }
    cout<<overlap;
    return 0;}