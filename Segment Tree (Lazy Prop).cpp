#include <bits//stdc++.h>

using namespace std;
#define mx 100005
#define i64 long long
int arr[mx];
struct info
{
    int prop, sum;
}tree[mx*3]; // sum ছাড়াও নিচে অতিরিক্ত কত যোগ হচ্ছে সেটা রাখবো prop এ

void init(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].sum = arr[b];
        return;
    }

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(int node, int b, int e, int i, int j, int x)
{
    if(i > e || j < b) return;
    if(b >= i && e <= j) // নোডের রেঞ্জ আপডেটের রেঞ্জের ভিতরে
    {
        tree[node].sum += ((e-b+1) * x); // নিচে নোড আছে e-b+1 টি, তাই e+b-1 বার x যোগ হবে এই রেঞ্জে
        tree[node].prop += x; // নিচের নোডগুলোর সাথে x যোগ হবে
        return;
    }

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e-b+1)*tree[node].prop;

    // উপরে উঠার সময় পথের নোডগুলো আপডেট হবে
    // বাম আর ডান পাশের সাম ছাড়াও যোগ হবে নিচে অতিরিক্ত যোগ হওয়া মান
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if(i > e || j < b) return 0;
    if(b >= i && e <= j) return tree[node].sum + carry*(e-b+1);

    int Left = node << 1;
    int Right = (node << 1) + 1;

    int mid = (b + e) >> 1;
    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);
    return p1 + p2;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>arr[i];
    init(1, 1, n);

    update(1, 1, n, 2, 5, 6);
    cout<<query(1, 1, n, 1, 3)<<endl;
    update(1, 1, n, 1, 4, 2);
    cout<<query(1, 1, n, 2, 2)<<endl;

    return 0;
}
