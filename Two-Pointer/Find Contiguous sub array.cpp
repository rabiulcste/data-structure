/** Problem: Given an array having N integers, find the contiguous sub-array
having sum as great as possible, but not greater than M.

Constraints: Array can have atmost 10^5 elements and each number will be
non-negative and can be as big as 10^9.

Solution: 1. We introduce two pointers l, r denoting startIndex and endIndex
of our contiguous sub-array, with both of them at the tip of the array.
2. We now start extending our right pointer r  provided sum[l,r] <= M Once,
we reach at such a stage, we don't have any option but to move the left pointer
as well and start decreasing the sum until we arrive at the situation where we
can extend our right pointer again.
3. As and when we reach the point, where we need to shift the left pointer,
we keep updating our maximum sum we have achieved so far.

Problem Link - http://www.spoj.com/problems/HOTELS/ **/

#include <bits//stdc++.h>

using namespace std;

int main()
{
    int n, M, A[300001];
    cin>>n>>M;

    for(int i = 0; i < n; i++) cin>>A[i];

    int l = 0, r = 0, ans = 0, sum = 0;

    while(l < n)
    {
        while(r < n && sum + A[r] <= M) {
            sum += A[r];
            r++;
        }
        ans = max(ans, sum);
        sum -= A[l];
        l++;
    }

    cout<<ans<<endl;
    return 0;
}
