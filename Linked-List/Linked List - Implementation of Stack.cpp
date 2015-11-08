#include <bits//stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Push(int x)
{
    struct Node* temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop()
{
    struct Node* temp = new Node();
    if(top == NULL) return;
    temp = top;
    top = top->next;
    free(temp);
}

void Print()
{
    struct Node* temp = top;
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int IsEmpty()
{
    if(top == NULL) return true;
    return false;
}

int Top()
{
    return (top->data);
}
int main()
{
    Push(2);
    Push(5);
    Push(3);
    Print();
    Push(8);
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Push(7);
    Print();
    if(IsEmpty())
        printf(" Empty!!");
    else
    printf(" Nope");
}
