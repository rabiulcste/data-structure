#include <bits//stdc++.h>
using namespace std;

void bubblesort(int ara[], int n)
{
    int i, j, temp;
    bool swapped;
    for(i=0; i<n-1; i++) {
        swapped = false;
        for(j=0; j<n-i-1; j++) {
            if(ara[j]>ara[j+1]){
                temp = ara[j];
                ara[j] = ara[j+1];
                ara[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped == false) break;
    }
    // print the array
    for(int i=0; i<n; i++)
        printf("%d ", ara[i]);
    printf("\n");
}

int main()
{
    int ara[] = {5, 1, 4, 2, 8};
    int n = sizeof(ara)/sizeof(ara[0]);
    bubblesort(ara, n);
    return 0;
}
