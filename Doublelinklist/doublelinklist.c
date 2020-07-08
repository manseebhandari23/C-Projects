#include<stdio.h>
#include<stdlib.h>

void insertion_beginning();
void insertion_last();
void insertion_random();
void deletion_beginning();
void deletion_last();
void random_delete();
void display();
void search();


struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;

void main()
{
    int choice ;
    printf("                                    DOUBLE LINK LIST                             \n");
    while(choice!= 9)
    {
        printf("\n==================================================================\n");
        printf("\n 1.Insert In Begining\n 2.Insert At Last\n 3.Insert At Specified Location\n 4.Delete From Beginning\n 5.Delete From Last\n 6.Delete The Node From Specified Location\n 7.Search The Element\n 8.Show\n 9.Exit\n");
        printf("\n Enter your choice?\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertion_beginning();
                   break;

            case 2:insertion_last();
                   break;

            case 3:insertion_random();
                   break;

            case 4:deletion_beginning();
                   break;

            case 5:deletion_last();
                   break;

            case 6:random_delete();
                   break;

            case 7:search();
                   break;

            case 8:display();
                    break;

            case 9:exit(0);
                   break;

            default:printf("Please enter valid choice..");
        }
    }
}

void insertion_beginning()
{
   struct node *ptr;
   int item;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n OVERFLOW");
   }
   else
   {
    printf("\n ENTER VALUE : ");
    scanf(" %d",&item);

      if(head==NULL)
      {
         ptr->next = NULL;
         ptr->prev=NULL;
         ptr->data=item;
         head=ptr;
      }
      else
      {
         ptr->data=item;
         ptr->prev=NULL;
         ptr->next = head;
         head->prev=ptr;
         head=ptr;
      }
     printf("\n Node Inserted Successfully \n");
   }
}

void insertion_last()
{
   struct node *ptr,*temp;
   int item;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n OVERFLOW \n");
   }
   else
   {
       printf("\n Enter Value: ");
       scanf(" %d",&item);
       ptr->data=item;
       if(head == NULL)
       {
           ptr->next = NULL;
           ptr->prev = NULL;
           head = ptr;
       }
       else
       {
          temp = head;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
          temp->next = ptr;
          ptr ->prev=temp;
          ptr->next = NULL;
       }
   }
  printf("\nNODE INSERTED SUCCESSFULLY \n");
}

void insertion_random()
{
   struct node *ptr,*temp;
   int item,loc,i;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n OVERFLOW ");
   }
   else
   {
       temp=head;
       printf(" Enter The Location");
       scanf(" %d",&loc);
       for(i=0;i<loc;i++)
       {
           temp = temp->next;
           if(temp == NULL)
           {
               printf("\n THERE ARE LESS NUMBER OF VALUES THEN %d ", loc);
               return;
           }
       }
       printf("\n Enter value");
       scanf(" %d",&item);
       ptr->data = item;
       ptr->next = temp->next;
       ptr -> prev = temp;
       temp->next = ptr;
       temp->next->prev=ptr;
       printf("\n NODE INSERTED SUCCESSfULLY \n");
   }
}

void deletion_beginning()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\n NODE DELETED SUCCESSFULLY \n");
    }
    else
    {
        ptr = head;
        head = head -> next;
        head -> prev = NULL;
        free(ptr);
        printf("\n NODE DELETED SUCCESSFULLY \n");
    }
}

void deletion_last()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\n NODE DELETED SUCCESSFULLY \n");
    }
    else
    {
        ptr = head;
        if(ptr->next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
        printf("\n NODE DELETED SUCCESSFULLY \n");
    }
}

void random_delete()
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter The Data Of The Node To Be Deleted : ");
    scanf(" %d", &val);
    ptr = head;
    while(ptr -> data != val)
    ptr = ptr -> next;
    if(ptr -> next == NULL)
    {
        printf("\n CAN'T DELETE NODE \n");
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr ->next = NULL;
    }
    else
    {
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
        printf("\n NODE DELETED SUCCESSFULLY \n");
    }
}

void display()
{
    struct node *ptr;
    printf("\n VALUES IN DOUBLE LINK LIST ARE AS FOLLOWS = \n");
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ----> ",ptr->data);
        ptr=ptr->next;
    }
}

void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\n Empty List \n");
    }
    else
    {
        printf("\n Enter Item To Search?\n");
        scanf(" %d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\n Item Found At %d Location ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("\n ITEM NOT FOUND IN LIST \n");
        }
    }

}
