 #include <stdio.h>
    int stack[100],i,choice=0,n,top=-1;
    void push();
    void pop();
    void show();
    void main()
    {
        printf("                                    STACK OPERATIONS                                \n\n");
        printf("ENTER THE NUMBER OF ELEMENTS IN STACK :-  \n");
        scanf("%d",&n);

        while(choice!= 4)
        {
            printf("\n----------------------------------------------\n");
            printf("  Choose From Below Options \n");
            printf("   1.PUSH   \n   2.POP  \n   3.SHOW    \n   4.EXIT ");
            printf("\n----------------------------------------------\n");
            printf("\n ENTER YOUR CHOICE  \n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                {
                    push();
                    break;
                }
                case 2:
                {
                    pop();
                    break;
                }
                case 3:
                {
                    show();
                    break;
                }
                case 4:
                {
                    printf("\n Exiting....");
                    break;
                }
                default:
                {
                    printf("\n Please Enter Valid Choice ");
                }
            };
        }
    }

    void push()
    {
        int val;
        if (top == n )
        printf("\n STACK OVERFLOW(Stack Limit Is Full) \n");
        else
        {
            printf("\n ENTER THE VALUE : \n");
            scanf("%d",&val);
            top = top +1;
            stack[top] = val;
        }
    }

    void pop()
    {
        if(top == -1)
        printf("\n STACK UNDERFLOW(Stack Is Empty) \n ");
        else
        printf("\n POP ELEMENT IS %d \n",stack[top]);
        top = top -1;
    }

    void show()
    {
        for(i=top;i>=0;i--)
        {
            printf("             |        |           \n");
            printf("             |   %d   |           \n",stack[i]);
            printf("             |________|           \n");
        }
        if(top == -1)
        {
            printf("\n STACK IS EMPTY ");
        }
    }
