#include <bits//stdc++.h>
using namespace std;

void selectionsort(int ara[], int n)
{
    int i, j, tmp, key;

    for(i = 1; i < n; i++) {
        key = ara[i];
        j = i;
        while(j>0 && ara[j-1]>key) {
            ara[j] = ara[j-1];
            j = j-1;
        }
        ara[j] = key;
    }
    // print the array
    for(int i=0; i<n; i++)
        printf("%d ", ara[i]);
    printf("\n");
}

int main()
{
    int ara[] = {3, 7, 4, 9, 5, 2, 6, 1};
    int n = sizeof(ara)/sizeof(ara[0]);
    selectionsort(ara, n);
    return 0;
}

