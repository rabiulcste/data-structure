#include <bits//stdc++.h>

using namespace std;

#define INF (int)1e9

int A[500005], cnt[1000100];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++) scanf("%d", &A[i]);
    int l = 0, r = 0, ans = -1;
    set<int>s;
    int ansl = -1;
    while ( l < n ) {
        while ( r < n && (s.size() < k || (s.size() == k && s.find(A[r]) != s.end()))) {
            s.insert(A[r]);
            cnt[A[r]]++;
            r++;
        }
        if (r-l > ans) {
			ans = r-l;
			ansl = l;
		}
        if ( cnt[A[l]] == 1 ) s.erase(A[l]);
        cnt[A[l]]--;
        l++;
    }
    if ( ans == INF ) ans = -1;

    //cout << ans << endl;
    printf("%d %d\n", ansl+1, ansl+ans);
    return 0;
}
