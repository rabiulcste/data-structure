/** Problem: Given an array containing N integers, you need to find the length of the 
smallest contiguous subarray that contains atleast K distinct elements in it. 
Output "−1" if no such subarray exists.

Constraints: Number of elements in the array are around one million with each of
them having value as large as 10^9.

Solution: we take two pointers l, r with both at the tip of the array. We keep on 
shifting the right pointer unless we have k elements into the set as set will only
contains distinct elements and will ignore the insertion of duplicate elements. As 
soon as we meet our condition, we now shift the left pointer unless the size of the 
set becomes < k. We also update the length of our minimum contiguous subarray as 
soon as we are ready to shift the left pointer. **/

#include <bits//stdc++.h>

using namespace std;

#define INF (int)1e9

int A[500005], cnt[1000100];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &A[i]);
    set<int>s;
    int l = 0, r = 0, ans = INF;

    while ( l < n ) {
            bool f1 = false;
        while ( r < n && s.size() < k ) {
            s.insert(A[r]);
            cnt[A[r]]++;
            r++;
            f1 = true;
        }
        if(f1) ans = min(ans, r-l);
        if ( cnt[A[l]] == 1 ) s.erase(A[l]);
        cnt[A[l]]--;
        l++;
    }
    if ( ans == INF ) ans = -1;

    cout << ans << endl;
    return 0;
}
