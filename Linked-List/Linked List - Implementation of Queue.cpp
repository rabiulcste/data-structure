#include <bits//stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x)
{
    struct Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct Node* temp = front;
    if(front == NULL) return;
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }

    free(temp);
}

int Top()
{
    return (front->data);
}

void Print()
{
    printf("\t Queue is : ");
    struct Node* temp = front;
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Enqueue(2);
    Enqueue(6);
    Enqueue(9);
    Print();
    Dequeue();
    Print();
    Enqueue(5);
    Enqueue(1);
    Dequeue();
    Print();
    printf("\t Top data is : %d", Top());
}
