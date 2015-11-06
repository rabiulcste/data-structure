#include <bits//stdc++.h>

using namespace std;
#define MAX 10
int A[MAX];
int front, rear;

bool IsEmpty()
{
    if(front == -1 && rear == -1)
        return true;
    return false;
}

bool IsFull()
{
    if((rear+1)%MAX == front)
        return true;
    return false;
}

void Enqueue()
{
    if(IsFull())
    {
        printf("\t Queue is full\n\n");
        return;
    }
    if(IsEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear+1)%MAX;
    }

    int x;
    printf("\t Enter data to be enqueued : ");
    scanf("%d", &x);
    printf("\n");
    A[rear] = x;
}

void Dequeue()
{
    if(IsEmpty()){
        printf("\t Queue is empty\n\n");
        return;
    }
    else if(front == rear)
    {
    printf("\t Dequeuing Data : %d\n\n", A[front]);
       rear = front = -1;
    }
    else
    {
        printf("\t Dequeuing Data : %d\n\n", A[front]);
        front = (front + 1)%MAX;
    }
}

void Front()
{
    if(front == -1)
    {
        printf("\t Can not return front empty queue\n\n");
    }
    printf("\t Front/Top data: %d\n\n", A[front]);
}

void Display()
{
    if(IsEmpty())
    {
        printf("\t Queue is empty\n\n");
    }
    else
    {
        int cnt = (rear+MAX-front)%MAX + 1;
        printf("\t Queue :");
        for(int i = 0; i < cnt; i++)
        {
            int indx = (front+i) % MAX;
            printf(" %d", A[indx]);
        }
        printf("\n\n");
    }
}

int main()
{
    front = rear = -1;
    int choice;
    printf("\t Enter 1 to Enqueue Data\n");
    printf("\t Enter 2 to Dequeue Data\n");
    printf("\t Enter 3 to Display Queue\n");
    printf("\t Enter 4 to Front Data\n");
    printf("\t Enter 5 to Exit\n");
    do
    {
        printf("\t Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            Front();
            break;
        default:
            printf("\t Wrong Choice\n");
        }
    } while(choice!=5);

    return 0;
}
