#include <bits//stdc++.h>
using namespace std;
const int sz = 100005;
const int INF = (1<<28);

template<typename t> t min3(t a, t b, t c) {return min(a, min(b, c));}

int block[sz];
int arr[sz];

void update(int index, int blockSize, int newvalue)
{
    int indx = index/blockSize;
    block[indx] = min(INF, newvalue);
}

int query(int l, int r, int blockSize)
{
    // LI for leftIndex, RI for rightIndex
    int LI = l/blockSize;
    int RI = r/blockSize;

    if(LI == RI)
    {
        int ret = INF;
        for(int i = l; i <= r; i++) ret = min(ret, arr[i]);
        return ret;
    }

    int m1 = INF, m2 = INF, m3 = INF;
    for(int i = l,  j = (LI+1)*blockSize-1; i <= j; i++) m1 = min(m1, arr[i]);
    for(int i = LI+1; i<RI-1; i++) m2 = min(m2, block[i]);
    for(int i = RI*blockSize; i <= r; i++) m3 =min(m3, arr[i]);

    return min3(m1, m2, m3);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int blockSize = sqrt(n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        block[i/blockSize] = min(INF, arr[i]) ;
    }
    while(q--)
    {
        int choice;
        // cout<<"What's your choiche?"<<endl;
        cin>>choice;
        if(choice==1){
            int i, j;
            cin>>i>>j;
            printf("%d\n", query(--i, --j, blockSize));
        }
        else
        {
            int i, value;
            cin>>i>>value;
            update(i, blockSize, value);
        }
    }
}
