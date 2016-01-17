/**  দুইটা সর্টেট array আছে , আমাদের বলতে হবে এই দুইটা array থেকে একটা একটা ভ্যালু নিয়ে আমরা কতভাবে
একটা নাম্বার M বানাতে পারি যাদের কোন মধ্যে কোন ডুপলিকেট ভ্যালু নেই ।

আমরা দুইটা পয়েন্ট নেই । Say low and high । low পয়েন্ট করতেছে আমাদের A array এর starting point
কে এবং high পয়েন্ট করতেছে আমাদের B array এর ending পজিশনটাকে ।

Observation number one ::
আমরা যদি দেখি A[low] + B[high] > M তাহলে আমরা একটা জিনিস সিউর ভাবে বলতে পারব । আমাদের অবশ্যই
B এর ভ্যালু কমাতে হবে । কারণ যেহেতু A[low] হচ্ছে A এর সবথেকে ছোট ভ্যালু সুতরাং  তাকে আর কমিয়ে কখনই
B[high] এর সাথে add করে M বানানো যাবে না ।

Observation number two ::
আমরা যদি দেখি A[low] + B[high] < M তাহলে আমাদের অবশ্যই low এর ভ্যালু বাড়াতে হবে । কারণ high
হচ্ছে B এর সবথেকে বড় ভ্যালু এর থেকে বড় ভ্যালু নাই । high থেকে আমরা কোন ভ্যালু বাড়াতে পারছি না । তাই
অবশ্যই আমাদের এখন  low থেকে বাড়াতে হবে ।

এইখানে একটা খটকা লাগতে পারে Observation one এ  যেহেতু A[] array তে left to right যাওয়া হচ্ছে
current low ভ্যালু মানে low যাকে right now point করছে A[] array তে তার থেকেও তো কম ভ্যালু
আমার array তে থাকতে পারে । আমরা নিচের কোডটা একটু ভাল মত খেয়াল করলেই দেখতে পাব যে যদি থেকে থাকে
এবং তার সাথে যদি high B[] array এর এড যদি M এর সমান হয় তাহলে তা আগেই Ans এর সাথে এড হয়ে আসবে ।
একদমই একই কাজ হচ্ছে B[] array তেও । এইখানে আমরা condition দিয়ে দুইটা পয়েন্টকে নিয়ন্ত্রণ করছি । **/

#include <bits//stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

const int NX = 1e5 + 10 ; // limit of the array
int N; // size of given  array
int M; // we need to make M by using this two array

int solve(int A[], int B[])
{
    int ans = 0, low = 0, high = N - 1;

    while( low < N )
    {
        while( A[low] + B[high] > M && high > 0 ) high--;
        if( A[low] + B[high] == M ) ans++;
        low++;
    }
    return ans;
}
int main()
{
    int A[NX], B[NX];
    cin>>N>>M;
    REP(i, N) cin>>A[i];
    REP(i, N) cin>>B[i];
    cout<<solve(A, B)<<endl;
}
