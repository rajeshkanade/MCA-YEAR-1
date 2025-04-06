#include "stackLL.h"

int main()
{
    node *head=NULL;
    int choice,x;

    do
    {
        printf("\n\n1:Push");
        printf("\n2:Pop");
        printf("\n3:Peek");
        printf("\n4:Display");
        printf("\n5:Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter data to be pushed: ");
                    scanf("%d",&x);
                    head = push(head,x);
                    break;

            case 2: head = pop(head);
                    break;

            case 3: x = peek(head);
                    if(x!=-1)
                        printf("\nPeek element is : %d\n",x);
                    break;

            case 4: display(head);
                    break;
        }
    }while(choice!=5);

    return 0;
}