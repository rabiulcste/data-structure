#include <bits//stdc++.h>
using namespace std;

void selectionsort(int ara[], int n)
{
    int i, j, minIndx, tmp;
    for(i=0; i<n-1; i++) {
        minIndx = i;
        for(j=i+1; j<n; j++) {
            if(ara[j]<ara[minIndx]){
                minIndx = j;
            }
        }

        if(minIndx != i) {
                tmp = ara[i];
                ara[i] = ara[minIndx];
                ara[minIndx] = tmp;
        }
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
    selectionsort(ara, n);
    return 0;
}

