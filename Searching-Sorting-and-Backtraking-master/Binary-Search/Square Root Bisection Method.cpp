#include <bits//stdc++.h>

using namespace std;

double sqrt(double x)
{
    // check if x is non-negative value
    if(x<0) return -1;
    // also check x==0 or x==1 because in this case sqrt(a) = a
    if(x==0 || x==1) return x;

    // core coding starts now
    double precision = 0.00001;
    double low = 0;
    double high = x;

    while(high-low>precision){
        double mid = (low+high)/2;
        double midSqr = mid*mid;
        if(midSqr==x) return mid; // we got the exact sqrt value
        else if(midSqr<x) low = mid; // our focus on bigger half
        else high = mid; // our focus on smaller half
    }
    /* if we did not find exact sqrt value,
    we return the approximated value with the defined precision*/
    return (low+high)/2;
}

int main()
{
    printf("%lf", sqrt(15));
    return 0;
}
