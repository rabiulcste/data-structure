#include <iostream>
#include <cstdio>

using namespace std;

int Partition(int *ara, int start, int end)
{
    int pivot = ara[end];
    int pIndex = start;

    for(int i=start; i<end; i++)
    {
        if(ara[i] <= pivot){
            swap(ara[i], ara[pIndex]);
            pIndex++;        }
    }
    swap(ara[pIndex], ara[end]);
    return pIndex;
}

void quickSort(int *ara, int start, int end)
{
    if(start < end) {
        int pIndex = Partition(ara, start, end);
        quickSort(ara, start, pIndex-1);
        quickSort(ara, pIndex+1, end);
    }
}

int main()
{
    int ara[] = {1, 4, 2, 18, 5, 3, 10, 6, 100, 34, 23, 123};
    int n = sizeof(ara)/sizeof(ara[0]);

    quickSort(ara, 0, n-1);

    for(int i=0; i<n; i++) printf("%d ", ara[i]);
    printf("\n");
}

