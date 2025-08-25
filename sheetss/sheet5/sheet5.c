#include <stdio.h>
#include <stdlib.h>
#include "../common/global.h"
#include "stacks.h"
#include "queus.h"

void View(int i,char *c){
    printf("id: %d name:%s\n",i,c);


}

int main()
{
    int choice;
    Stack S;
    Queue Q,tmp;
    create_Stack(&S);
    createQueue(&Q);
    createQueue(&tmp);
    element_type e;
    while(1){
            printf("1. Add a New Customer.\n");
            printf("2. Serve a Customer.\n");
            printf("3. Display Customers Information.\n");
            printf("4. Display Customers information in the 'most-recent' Order.\n");
            printf("5. Exit menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar();
            if (choice==1)
            {
                printf("Enter Customers Information:\n");
                printf("ID: ");
                scanf("%d",&e.id);
                printf("Name: ");
                scanf("%s",e.name);
                Append(e,&Q);
            }
            else if (choice==2)
            {
                if(!isQueueEmpty(&Q)){
                Serve(&e,&Q);
                printf("YYYYYYYYYYYYYYYYY\n");
                printf("A Customer had served\nId: %d    Name: %s\n",e.name,e.name);
                printf("YYYYYYYYYYYYYYYYY\n");
                }
                else
                {
                    printf("Queue underflow\n");
                }
            }
            else if (choice==3)
            {
                printf("The waiting list :\n");
                printf("YYYYYYYYYYYYYYYYY\n");
                TraversQueue(&Q,&View);
                printf("YYYYYYYYYYYYYYYYY\n");
            }
            else if (choice==4)
            {
                while(!isQueueEmpty(&Q)){
                    Serve(&e,&Q);
                    Append(e,&tmp);
                    Push(e,&S);
                }
                while(!isQueueEmpty(&tmp)){
                    Serve(&e,&tmp);
                    Append(e,&Q);

                }
                printf("YYYYYYYYYYYYYYYYY\n");
                Travers_Stack(&S,&View);
                printf("YYYYYYYYYYYYYYYYY\n");
                clearStack(&S);
            }
            else if(choice==5)
            {
                break;
            }
            else
            {
                printf("XXXXXXXXXXXXXXXXXXXXXXX\n");
                printf("INVALIED INPUT\n");
                printf("XXXXXXXXXXXXXXXXXXXXXXX\n");
            }
    }
    return 0;
}
