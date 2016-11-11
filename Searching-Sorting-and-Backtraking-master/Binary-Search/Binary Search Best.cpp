#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 10005

int input[MAX], item, pos, middle;

void binarySearch(int low, int high){
    if(low<=high){
        middle = (low+high)/2;
        if(input[middle]==item) pos = middle;
        if(item<=input[middle]) binarySearch(low, middle-1);
        else binarySearch(middle+1, high);
    }
    else return;
}
int main(){
    int n;
    scanf("%d", &n);

    // input array
    for(int i=0; i<n; i++) scanf("%d", &input[i]);
    sort(input, input+n);

    // search
    scanf("%d", &item);
    pos = -1;
    binarySearch(0, n-1);

    if(pos<0) printf("%d not found\n", item);
    else printf("%d found at position %d\n", item, pos+1);

    return 0;
}
