/**
A sequence of N positive integers (10 < N < 100000), each of them less than or equal
10000, and a positive integer S(S < 100000000) are given. Write a program to find the minimal
length of the subsequence of consecutive elements of the sequence, the sum of which is
greater than or equal to S.

Input
Many test cases will be given. For each test case the program has to read the numbers N and
S, separated by an interval, from the first line. The numbers of the sequence are given in
the second line of the test case, separated by intervals. The input will finish with the end
of file.

Output
For each the case the program has to print the result on separate line of the output file.

Sample Input
10 15
5 1 3 5 10 7 4 9 2 8
5 11
1 2 3 4 5

SampleOutput
2
3
**/

#include <bits//stdc++.h>

using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main()
{
    int n, s, a[100010];
    while(scanf("%d %d", &n, &s) == 2) {
        REP(i, n) scanf("%d", &a[i]);
        int hi = 0, lo = 0, sum = a[0], ans = 1000000;
        while( hi < n ) {
            if( sum >= s ) {
                ans = min(ans, hi - lo + 1);
            }
            if( sum >= s && lo < hi ) {
                sum -= a[lo];
                lo++;
            }
            else {
                hi++;
                if( hi < n )
                    sum += a[hi];
            }
        }
        if( ans == 1000000 ) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
