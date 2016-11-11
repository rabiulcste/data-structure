#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// Structure to store information of a suffix
struct suffix
{
    int index;
    char *suff;
} ;

int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int *buildSuffixArray(char *txt, int n)
{
    struct suffix suffixes[n];

    for(int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
    sort(suffixes, suffixes+n, cmp);

    int *suffixArray = new int[n];

    for(int i = 0; i < n; i++)
        suffixArray[i] = suffixes[i].index;

    return suffixArray;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n ; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void search(char *pat, char *txt, int *suffArr, int n)
{
    int m = strlen(pat);

    // do binary search for the pattern
    int l = 0, r = n-1;
    while(l <= r)
    {
        // See if pattern is prefix of middle suffix in suffix array
        int mid = l + (r-1)/2;
        int res = strncmp(pat, txt+suffArr[mid], m);

        // If match found at the middle, print it
        if(res == 0)
        {
            cout << "Pattern found at index " << suffArr[mid];
            return;
        }
        // Move to left half if pattern is alphabetically
        // less than the mid suffix
        if(res < 0) r = mid - 1;

        // otherwise move to right half
        else l = mid + 1;
    }
    cout << "Pattern not found" << endl;
}

int main()
{
    char txt[] = "banana";
    char pat[] = "nan";

    int n = strlen(txt);
    int *suffArr = buildSuffixArray(txt, n);
    // cout << "Following is suffix array for " << txt << endl;
    // printArr(suffixArr, n);

    search(pat, txt, suffArr, n);

    return 0;
}
