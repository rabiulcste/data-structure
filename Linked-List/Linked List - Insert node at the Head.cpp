#include <bits//stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;
void InsertatBegin(int x)
{
    struct Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print()
{
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the number :\n");
        scanf("%d", &x);
        InsertatBegin(x);
        Print();
    }

    return 0;
}
