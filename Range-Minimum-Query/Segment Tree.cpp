#include <iostream>

using namespace std;

#define mx 100001
int arr[mx];
int tree[mx*3];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i > e || j< b) return 0;
    if(b >= i && e <= j) return tree[node];
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);

    return p1 + p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if(i > e || i < b) return;
    if(b >= i && e <= i)
    {
        tree[node] = newvalue;
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, newvalue);
    update(right, mid+1, e, i, newvalue);
    tree[node] = tree[left] + tree[right];
}

int main()
{
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    init(1, 1, n);
    update(1, 1, n, 2, 0);
    cout<<query(1, 1, n, 1, 3)<<endl;
    update(1, 1, n, 2, 2);
    cout<<query(1, 1, n, 2, 2);
    return 0;
}
