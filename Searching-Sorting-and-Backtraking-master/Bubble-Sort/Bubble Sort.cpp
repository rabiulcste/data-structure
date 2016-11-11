#include <bits//stdc++.h>

using namespace std;

void bubblesort(int ara[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++) {
            if(ara[j]>ara[j+1]){
                int temp = ara[j];
                ara[j] = ara[j+1];
                ara[j+1] = temp;
            }
        }

    // print the array
    for(int i=0; i<n; i++)
        printf("%d ", ara[i]);
    printf("\n");
}

int main()
{
    int ara[] = {4, 10, 3, 2, 5, 8, 100, 20};
    int n = sizeof(ara)/sizeof(ara[0]);
    bubblesort(ara, n);

    return 0;
}
