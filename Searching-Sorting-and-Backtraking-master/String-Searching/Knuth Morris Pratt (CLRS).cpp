#include<bits/stdc++.h>
using namespace std;

char txt[10000000], pat[1000];
vector<int>match_pos;
bool flag = false;

vector<int> compute_prefix(const char *p)
{
    int m = strlen(p+1);
    vector<int> prefix(m+1);
    prefix[1] = 0;
    int k = 0;
    for(int i = 2; i <= m; i++)
    {
        while(k>0 and p[k+1] != p[i]) k = prefix[k];
        if(p[k+1] == p[i]) k++;
        prefix[i] = k;
    }
    return prefix;
}
void KMP_matcher(const char *txt, const char *ptrn)
{
    int n = strlen(txt+1);
    int m = strlen(ptrn+1);
    vector<int> Prefix = compute_prefix(ptrn);
    int q = 0;

    for(int i = 1; i <= n; i++)
    {
        while(q > 0 and ptrn[q+1] != txt[i]) q = Prefix[q];
        if(ptrn[q+1] == txt[i]) q++;
        if(q == m)
        {
            flag = true;
            match_pos.push_back(i-m);
            q = Prefix[q];
        }
    }
    return;
}
int main()
{
    // character array index start from 1 not 0
    scanf(" %[^\n]s", txt+1);
    scanf(" %[^\n]s", pat+1);
    KMP_matcher(txt, pat);
    if(flag){
        for(int i = 0; i < match_pos.size(); i++)
        {
            if(!i)
                printf("%d", match_pos[i]);
            else
                printf(" %d", match_pos[i]);
        }
    }
    else cout << "No match found" << endl;
    return 0;
}
