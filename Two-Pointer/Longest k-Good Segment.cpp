/*
The array a with n integers is given. Let's call the sequence
of one or more consecutive elements in a segment. Also let's
call the segment k-good if it contains no more than k different values.
Find any longest k-good segment.
*/
#include <bits//stdc++.h>
using namespace std;
int a[5000005], vis[5000005];
int main()
{
    int n, k;
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    int mx = -1, l = 1, cnt = 0, ansl, ansr;
    for(int r=1; r<=n; r++) {
        if(vis[a[r]] == 0) cnt++;
        vis[a[r]]++;
        while(l<=r && cnt>k) {
            if(vis[a[l]] == 1) cnt--;
            vis[a[l]]--;
            l++;
        }
        while(mx < r - l + 1){
            mx = r -l + 1;
            ansl = l;
            ansr = r;
        }
    }
    cout<<ansl<<" "<<ansr<<endl;
    return 0;
}
