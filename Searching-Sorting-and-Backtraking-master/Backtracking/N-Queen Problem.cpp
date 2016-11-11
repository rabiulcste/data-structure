#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

bool row[8], diagonal1[15], diagonal2[15];
int total, C, pos[8];

void nqueen(int c)
{
    if(c == 8) // complete
    {
        printf("%2d      ", ++total);
        for(int i = 0; i < 8; i++){
            if(i != 0) printf(" ");
            printf("%d", pos[i]+1);
        }
        printf("\n");
    }

    if(c==C) nqueen(c+1);
    else{
    for(int i = 0; i < 8; i++){
        if(row[i] || diagonal1[c-i+7] || diagonal2[c+i]) continue;
        // As c-i can be negative that's why we are adding n
        row[i] = diagonal1[c-i+7] = diagonal2[c+i] = true;
        pos[c] = i; // position of column
        nqueen(c+1);
        row[i] = diagonal1[c-i+7] = diagonal2[c+i] = false;
        }
    }
}

int main()
{
    int r, test;
    scanf("%d", &test);
    for(int i=0; i<test; i++){
    scanf("%d %d", &r, &C);
    r--;
    C--;
        for(int j=0;j<8;j++) row[j]=false;
        for(int j=0;j<15;j++) diagonal1[j]=diagonal2[j]=false;

    row[r] = diagonal1[C-r+7] = diagonal2[C+r]= true;

    pos[C] = r;
    total = 0;
    if(i!=0) printf("\n");
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
    nqueen(0);
    }
    return 0;
}
