/**Problem:Given two sorted arrays A and B, each having length N and M respectively.
Form a new sorted merged array having values of both the arrays in sorted format.

Constraints: Array A and  B contains about 10^5 integers, each having value around 10^9.

Solution: Since the two arrays are given in sorted order, we can surely do something with two pointers.
Let us go step by step.

    1. We will introduce read-indices l1, l2 to traverse arrays A and B, respectively.
and another write-index cnt to store position of the first free cell in the resulting array.
Initially all l1,l2 and cnt will be 0.
    2. Moving on, if both indices are in range (l1 < N and l2 < M), choose minimum of (Ai, Bj)
and write it to C[cnt], and increase the respective pointer.**/

#include <bits//stdc++.h>

using namespace std;

#define MAX 100005
typedef long long ll;

int C[2*MAX], n, m;

void merge(int A[], int B[])
{
    int l1 = 0, l2 = 0, cnt = 0;
    while(l1 < n || l2 < m) {
        if(l1 < n && l2 < m) {
            if(A[l1] < B[l2]) {
                C[cnt++] = A[l1];
                l1++;
            }
            else if(A[l1] > B[l2]) {
                C[cnt++] = B[l2];
                l2++;
            }
        }
        else if(l1 < n) {
            C[cnt++] = A[l1];
            l1++;
        }
        else if(l2 < m) {
            C[cnt++] = B[l2];
            l2++;
        }
    }
}

int main()
{
    int A[5] = {1, 3, 7, 9, 10};
    int B[5] = {4, 5, 8, 11, 12};
    n = sizeof(A)/sizeof(A[0]);
    m = sizeof(B)/sizeof(B[0]);
    merge(A, B);
    for(int i = 0; i < 10; i++) printf("%d ", C[i]);
    puts("");
}
