#include<stdio.h>
#include<stdlib.h>
#define maxsize 15
void insert();
void delete();
void display();
int front = -1, rear = -1;
int queue[maxsize];

void main()
{
    int choice;
    printf("                                    QUEUE OPERATIONS                               \n");
    while(choice != 4)
    {
        printf("\n================================================================================\n");
        printf("\n   1.Insert An Element\n   2.Delete An Element\n   3.Display The Queue\n   4.Exit\n");
        printf("\n================================================================================\n");
        printf("\n  Enter your Choice ? \n");
        scanf("%d",&choice);
          switch(choice)
           {
               case 1:insert();
                       break;

                case 2:delete();
                       break;

                case 3:display();
                       break;

                case 4:exit(0);
                       break;

                default:
                        printf("\n Enter valid choice?? \n");
            };
    }
}

void insert()
{
    int item;
    printf(" ENTER THE ELEMENT :  \n");
    scanf("%d",&item);
    if(rear == maxsize-1)
    {
        printf("\n QUEUE OVERFLOW \n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
            rear = 0;
        }
        else
        {
            rear = rear+1;
        }
        queue[rear] = item;
        printf("\n VALUE INSERTED SUCEESFULLY ");
    }

    void delete()
    {
        int item;
        if (front == -1 || front > rear)
        {
            printf("\n QUEUE UNDERFLOW \n");
            return;
        }
        else
        {
            item = queue[front];
            if(front == rear)
            {
                front = -1;
                rear = -1 ;
            }
            else
            {
                front = front + 1;
            }
            printf("\n VALUE DELETED SUCCEESFULLY ");
        }


    }

    void display()
    {
        int i;
        if(rear == -1)
        {
            printf("\n QUEUE IS EMPTY \n");
        }
        else
        {
            printf("\n PRINTING VALUES......... \n");
            printf("\n");
            for(i=front;i<=rear;i++)
            {
                printf("   %d    |\t",queue[i]);
            }
            printf(" \n");
        }
    }
