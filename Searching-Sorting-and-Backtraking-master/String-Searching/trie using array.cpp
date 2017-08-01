#include <bits//stdc++.h>
using namespace std;

#define ll long long
struct node
{
    bool endmark;
    int cnt;
    int next[60+1];
    node()
    {
        cnt = 0;
        endmark = false;
        for(int i=0; i<60; i++) next[i] = 0;
    }
}trie[100010];
int ind;

void insert(char *str, int len)
{
    int curr = 0;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - 'A';
        if(trie[curr].next[id] == 0)
            trie[curr].next[id] = ++ind;
        curr = trie[curr].next[id];
        ++trie[curr].cnt;
    }

    trie[curr].endmark = true;
}

bool search(char *str, int len)
{
    int curr = 0;
    for(int i=0; i<len; i++)
    {
        int id = str[i]-'A';
        if(trie[curr].next[id] == 0) return 0;
        curr = trie[curr].next[id];
    }
    return trie[curr].endmark;
}

void del()
{
    memset(trie, 0, sizeof trie);
}

int main()
{
    int T;
    scanf(" %d", &T);
    for(int ks = 1; ks <= T; ks++) {
        int n;
        scanf(" %d", &n);
        getchar();
        ind = 0;
        for(int i = 0; i < n; i++) {
            char str[110];
            //scanf(" %s", str);
            gets(str);
            insert(str, strlen(str));
        }

        int q;
        scanf(" %d", &q);
        getchar();

        for(int i = 0; i < q; i++) {
            char str[110];
            gets(str);

            if(search(str, strlen(str))) printf("Found\n");
            else printf("Not Found\n");
        }
        del();
    }
    return 0;
}
