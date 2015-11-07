#include <bits//stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void InsertatEnd(int data)
{
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(head == NULL)
    {
        head = temp1;
        return;
    }
    Node* temp2 = new Node();
    temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

void Print()
{
    Node* temp = head;
    printf("List elements are :");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int n)
{
    struct Node* temp1 = head;
    if(n == 1)
    {
        head = temp1->next; // head now points to second node
        free(temp1);
        return;
    }

    int i;
    for(int i = 0; i < n-2; i++)
        temp1 = temp1->next;

    // temp1 points to (n-1)th Node
    struct Node* temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    free(temp2); // delete temp2
}


int main()
{
    head = NULL;
    InsertatEnd(2);
    InsertatEnd(4);
    InsertatEnd(6);
    InsertatEnd(5);
    Print();
    int n;
    printf("Enter Position :\n");
    scanf("%d", &n);
    Delete(n);
    Print();
    return 0;
}
