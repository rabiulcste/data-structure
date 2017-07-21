// O(n)*log(n)*log(n)
#include <bits//stdc++.h>
using namespace std;

#define MAXN (int)1e5
#define MAXK 17

int SA[MAXN]; // Suffix Array
string str; // input string, 1 based indexing

struct tuple {
   int first, second, index;
} L[MAXN]; // Array of tuples

int P[MAXK][MAXN]; // P[i][j] denotes rank of suffix at position when all
        // suffixes are sorted by their first '2^i' characters
int po[MAXK]; // array of power of 2, power[i] denotes 2^i
int lcp[MAXN]; // longest common prefix
int N; // length of string
int step;

bool cmp(struct tuple a, struct tuple b)
{
    return a.first == b.first ? (a.second<b.second ? 1 : 0) : (a.first<b.first ? 1 : 0);
}

void buildSA()
{
    po[0] = 1;
    for(int i = 1; i < MAXK; i++) {
        po[i] = po[i-1]*2;
    }

    N = str.size();
    for(int i = 0; i < N; i++)
        P[0][i] = str[i] - 'a';

    int i;
    for(i = 1, step = 1; po[i-1] < N; i++, step++) {
        for(int j = 0; j < N; j++) {
            L[j].index = j;
            L[j].first = P[i-1][j];
            L[j].second = j+po[i-1]<=N ? P[i-1][j+po[i-1]] : -1;
        }
        sort(L, L+N, cmp);

        for(int j = 0; j < N; j++) {
            P[i][L[j].index] = (j>0 && L[j].first == L[j-1].first && L[j].second == L[j-1].second) ? P[i][L[j-1].index] : j;
            // Assign same rank to the suffixes which have same number in the first and second
            // fields of their respective tuples.
        }
    }
    step = step - 1;
    for(int i = 0; i < N; i++) {
        //cout << P[step][i] << endl;
        SA[P[step][i]] = i;
    }
}

int LCP(int i,  int j)
{
    int ans = 0;
    if(i == j) return N-i;
    for(int k = step; k >= 0; k--) {
        if(P[k][i] == P[k][j])
            ans += po[k], i += po[k], j += po[k];
    }
    return ans;
}

int main()
{
    cin >> str;

    buildSA();

    cout << "Suffix Array:\n";
    for(int i = 0; i < N; i++) {
        cout << SA[i] << " " << str.substr(SA[i]) << "\n";
    }

    cout << "\nLongest Common Prefix:\n";
    for(int i = 0; i < N; i++) {
        if(i == 0) lcp[i] = 0;
        else lcp[i] = LCP(SA[i], SA[i-1]);
        cout << lcp[i] << "\n";
    }
    return 0;
}
