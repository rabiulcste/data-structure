#include <bits//stdc++.h>

#define pb push_back
#define sz size
#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

using namespace std;

typedef long long int lld;
typedef pair < int, int > pii;

const int MaxN = 1 << 20;

int N, M, Level[MaxN], Parent[MaxN], Size[MaxN], Chain[MaxN];
vector < int > E[MaxN];

void DFS ( int Curr, int Prev )
{
    Parent[Curr] = Prev;
    Size[Curr] = 1;

    for_each ( it, E[Curr] ) if ( * it != Prev ) Level[* it] = Level[Curr] + 1, DFS ( * it, Curr ), Size[Curr] += Size[* it];
}

void HLD ( int Curr, int Prev, int Color )
{
    Chain[Curr] = Color;

    int idx = -1;
    for_each ( it, E[Curr] ) if ( * it != Prev && ( idx == -1 || Size[* it] > Size[idx] ) ) idx = * it;

    if ( idx != -1 ) HLD ( idx, Curr, Color );
    for_each ( it, E[Curr] ) if ( * it != Prev && * it != idx ) HLD ( * it, Curr, * it );
}

inline int LCA ( int idx, int idy )
{
    while ( Chain[idx] != Chain[idy] ) if ( Level[Chain[idx]] < Level[Chain[idy]] ) idy = Parent[Chain[idy]];
                                       else idx = Parent[Chain[idx]];
    return Level[idx] < Level[idy] ? idx : idy;
}

int main ( void )
{
    cin.sync_with_stdio ( 0 );
    cout.sync_with_stdio ( 0 );

    cin >> N >> M;
    for ( int i = 0; i < N - 1; i++ )
    {
        int idx, idy;
        cin >> idx >> idy;
        idx--;
        idy--;

        E[idx].pb ( idy );
        E[idy].pb ( idx );
    }

    DFS ( 0, -1 );
    HLD ( 0, -1, 0 );

    for ( int i = 0; i < M; i++ )
    {
        int idx, idy;
        cin >> idx >> idy;
        idx--;
        idy--;

        cout << LCA ( idx, idy ) + 1 << endl;
    }

    return 0;
}
