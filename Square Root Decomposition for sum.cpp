#include <bits//stdc++.h>
using namespace std;
const int sz = 100005;
const int INF = (1<<28);

int b[sz];
int a[sz];

int s; // s for blockSize

int incElement(int index, int delta)
{
	a[index] += delta;
	b[index/s] += delta;
}
int decElement(int index, unsigned int delta) //delta - на сколько уменьшить элемент
{
	a[index] -= delta;
	b[index/s] = min(b[index/s], a[index]);
}

void querySum(int l, int r)
    {
	int sum = 0;
    int nl = l / s,   nr = r / s;
    if (nl == nr)
	for (int i=l; i<=r; ++i)
		sum += a[i];

    else {
	for (int i=l, end=(nl+1)*s-1; i<=end; ++i)
		sum += a[i];
	for (int i=nl+1; i<=nr-1; ++i)
		sum += b[i];
	for (int i=nr*s; i<=r; ++i)
		sum += a[i];
    }
    cout<<sum<<endl;
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    s = sqrt(n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i/s] += a[i];
    }
    while(q--)
    {
        int choice;
        // cout<<"What's your choiche?"<<endl;
        cin>>choice;
        if(choice==1){
            int i, j;
            cin>>i>>j;
            querySum(--i, --j);
        }
        else if(choice==2)
        {
            int i, value;
            cin>>i>>value;
            incElement(--i, value);
        }
        else
        {
            int i, value;
            cin>>i>>value;
            decElement(--i, value);
        }
    }
}
