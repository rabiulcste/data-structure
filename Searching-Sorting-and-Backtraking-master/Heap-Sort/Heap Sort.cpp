#include <bits//stdc++.h>

using namespace std;

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2] = temp;
    return;
}

void heapSort(int *a, int n)
{
    for(int i = n ; i >= 2; i--)
    {
        swap(a[i], a[1]);
        max_heapify(a, 1, i-1);

    }
}

void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1; i<=n; i++) cin>>a[i];
    build_maxheap(a, n);
    heapSort(a, n);
	printf("Sorted Array:\n");
	for(int i = 1; i<=n; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}
