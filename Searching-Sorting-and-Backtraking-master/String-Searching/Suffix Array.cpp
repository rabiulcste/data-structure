// O(n)*log(n)
#include <bits//stdc++.h>
using namespace std;

#define MAXN 100010
#define MAXK 20

int SA[MAXN]; // Suffix Array
string str; // input string, 1 based indexing

struct tuple {
   int first, second, index;
}; // Array of tuples

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


void count_sort(tuple t[])
{
    int count[MAXN];
    tuple temp[N + 9];
    memset(count, 0, sizeof count);

    for(int i = 0; i < N; i++)
        count[t[i].second + 1]++;

    for(int i = 1; i < MAXN; i++)
        count[i] += count[i-1];

    for(int i = 0; i < N; i++)
    {
        temp[count[t[i].second +1] - 1] = t[i];
        count[t[i].second + 1]--;
    }

    memset(count, 0, sizeof count);

    for(int i = 0; i < N; i++)
        count[t[i].first+ 1]++;

    for(int i = 1; i < MAXN; i++)
        count[i] += count[i-1];

    for(int i = N-1; i >= 0; i--)
    {
        t[count[temp[i].first+ 1] - 1] = temp[i];
        count[temp[i].first+ 1]--;
    }
}

void buildSA()
{
    po[0] = 1;
    for(int i = 1; i < MAXK; i++) {
        po[i] = po[i-1]*2;
    }

    tuple L[N+9];
    for(int i = 0; i < N; i++)
        P[0][i] = str[i] - 'a';

    for(int i = 1; po[i-1]/2 < N; i++) {
        for(int j = 0; j < N; j++) {
            L[j].index = j;
            L[j].first = P[i-1][j];
            L[j].second = j+po[i-1] < N ? P[i-1][j+po[i-1]] : -1;
        }

        // sort(L, L+N, cmp);
        count_sort(L);
        for(int j = 0; j < N; j++) {
            P[i][L[j].index] = (j>0 && L[j].first == L[j-1].first && L[j].second == L[j-1].second) ? P[i][L[j-1].index] : j;
            // Assign same rank to the suffixes which have same number in the first and second
            // fields of their respective tuples.
        }
    }

    step = ceil(log(N)/log(2));
    for(int i = 0; i < N; i++) {
        SA[P[step][i]] = i;
    }
}

//void lcpok()
//{
//    int k = 0;
//    vector<int> rank(N,0);
//    for(int i=0; i<N; i++) rank[SA[i]] = i;
//    lcp[0] = 0;
//
//    for(int i=0; i<N; i++, k?k--:0)
//    {
//        if(rank[i] == N-1) {k = 0; continue;}
//        int j = SA[rank[i]+1];
//        while(i+k<N && j+k<N && str[i+k] == str[j+k]) k++ ;
//        lcp[rank[i] + 1] = k;
//    }
//}

int LCP(int i,  int j)
{
    int ans = 0;
    if(i == j) return N-i;
    for(int k = step; k >= 0 && i < N && j < N; k--) {
        if(P[k][i] == P[k][j]) {
            ans += po[k], i += po[k], j += po[k];
        }
    }
    return ans;
}


int main()
{
    // freopen("out1.txt", "w", stdout);
    cin >> str;
    N = str.size();

    buildSA();
    // lcpok();
    cout << "\nSuffix Array + LCP:\n\n";
    lcp[0] = 0;
    for(int i = 1; i < N; i++) {
        lcp[i] = LCP(SA[i], SA[i-1]);
    }

    for(int i = 0; i < N; i++) {
        cout << SA[i] << " " << str.substr(SA[i]) << "\tlcp = " << lcp[i] << "\n";
    }

    return 0;
}
