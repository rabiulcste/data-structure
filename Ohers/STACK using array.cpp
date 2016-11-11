#include <bits//stdc++.h>

using namespace std;

#define MAX 5
int stak[5];
int top;
void push();
void pop();
void display();

int main()
{
    top = -1;
    int choice;
    printf("\t Enter 1 to Push\n");
    printf("\t Enter 2 to Pop\n");
    printf("\t Enter 3 to Display\n");
    printf("\t Enter 4 to exit\n");
    do
    {
        printf("\t Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\t Wrong Choice\n");
        }
    } while(choice!=4);

    return 0;
}

void push()
{
    int data;
    if(top == MAX-1)
        printf("\t Stack overflow\n");
    else
    {
        printf("\t Enter data to be pushed: ");
        scanf("%d", &data);
        top++;
        stak[top] = data;
    }
}

void pop()
{
    int data;
    if(top == -1)
        printf("\t Item can not be deleted. Stack is empty\n");
    else
    {
        data = stak[top];
        top--;
        printf("\t Item deleted: %d", data);
    }
}

void display()
{
    if(top == -1)
        printf("\t Stack is empty\n");
    else
    {
        printf("\t Here is stacked value: ");
        for(int i=top; i>=0; i--)
            printf("%d ", stak[i]);
        printf("\n");
    }
}
