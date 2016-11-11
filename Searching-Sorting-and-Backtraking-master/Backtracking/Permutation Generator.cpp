#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char arr[] = {'a', 'b', 'c', 'd'};

vector<char>result;
int taken[20] = {0};

void call()
{
    if(result.size() == 4)
    {
        for(int i = 0; i < 4; i++)
        printf("%c", result[i]);
        puts(" ");
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        if(taken[i] == 0)
        {
            taken[i] = 1; result.push_back(arr[i]);
            call();
            taken[i] = 0; result.pop_back();
        }
    }
}

int main()
{
    call();
}
