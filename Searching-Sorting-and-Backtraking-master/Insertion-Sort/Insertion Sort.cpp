#include <bits//stdc++.h>
using namespace std;

void selectionsort(int ara[], int n)
{
    int i, j, tmp;

    for(i = 1; i < n; i++) {
        j = i;
        while(j>0 && ara[j-1]>ara[j]) {
            tmp = ara[j];
            ara[j] = ara[j-1];
            ara[j-1] = tmp;
            j = j-1;
        }
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

