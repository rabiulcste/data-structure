/* Problem - We are Given an array(or vector) of integer, 
in which each element occurs even number of times apart from 
one element, which occurs odd number of times.
Our job is to find the element with odd occurrence in O(n) 
time complexity and O(1) Auxiliary space. */

#include <bits/stdc++.h>
using namespace std;

void findOddOccurring(int a[],int size)
{
    int x=0; //initialising with zero is important
    for(int i=0;i<size;++i)
        x^=a[i];
    cout<<"The number occuring odd times is "<<x;
}

int main() {
    int a[]={1,2,1,3,4,4,2};
    int size=sizeof(a)/sizeof(a[0]);
    findOddOccurring(a,size);
    return 0;
}
