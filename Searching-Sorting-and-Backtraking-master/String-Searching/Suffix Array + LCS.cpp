#include <bits//stdc++.h>
using namespace std;

#define MAX_N 700000
char T[MAX_N]; // the input string
int n; // the length of input string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N]; // for counting / radix sort

char P[MAX_N]; // the pattern string
int m;
int Phi[MAX_N]; // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N]; // LCP[i] stores the LCP between previous suffix T+SA[i-1]
// ans current suffix T+SA[i]

void countingSort(int k) // O(n)
{
    int i, sum, maxi = max(300, n);// up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c); // clear frequency table
    for(int i = 0; i < n; i++) { // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    }

    for(int i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }

    for(int i = 0; i < n; i++) { // shuffle the  suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    }
    for(int i = 0; i < n; i++) { // update the suffix array SA
        SA[i] = tempSA[i];
    }
}

void constructSA() // upto 1e5 characters
{
    int i, k, r;
    for(i = 0; i < n; i++) RA[i] = T[i]; // initial ranking
    for(i = 0; i < n; i++) SA[i] = i; // initial SA

    for(k = 1; k < n; k <<= 1) { // repeat sorting process log(n) times
        countingSort(k); // actually radix sort : sort based on second item
        countingSort(0); // stable sort based on the first item
        tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0;
        for(int i = 1; i < n; i++) {
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        }

        for(i = 0; i < n; i++) { // update the rank array RA
            RA[i] = tempRA[i];
        }
        if(RA[SA[n-1]] == n-1) break; // optimization trick
    }
}

void computeLCP()
{
    int i, L;
    Phi[SA[0]] = -1; // default value
    for(i = 1; i < n; i++) // compute phi in O(n)
        Phi[SA[i]] = SA[i-1]; // remember which suffix is behind this suffix
    for(i = L = 0; i < n; i++) { // compute permuted LCP in O(n)
        if(Phi[i] == -1) {
            PLCP[i] = 0; // special case
            continue;
        }
        while(T[i+L] == T[Phi[i]+L]) L++; // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0); // L decreased max n times
    }
    for(i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]]; // put the permuted lcp to the correct position
}

int owner(int idx)
{
    return (idx < n - m -1) ? 1 : 2;
}

int LCS()
{
    int i, idx = 0, maxLCP = -1;
    for(int i = 1; i < n; i++) {
        if(owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP) {
            maxLCP = LCP[i];
        }
    }
    return maxLCP;
}

int main()
{
    cin >> T;
    n = strlen(T);
    T[n++] = '$';
    cin >> P;
    m = strlen(P);
    strcat(T, P);
    strcat(T, "#");
    n = strlen(T);

    constructSA();
    computeLCP();
    // for(int i = 0; i < n; i++) cout << SA[i] << " " << LCP[i] << endl;
    cout << LCS() << endl;
    return 0;
}
