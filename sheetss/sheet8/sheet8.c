#include <stdio.h>
#include <stdlib.h>
#include "prlist.h"

void view(info e){
    printf("ID: %s, Priority: %d\n", e.id, e.Pr);
}

int main()
{
    dlist prlist;
    create(&prlist);
    info e;
    int choice;
    while(1)
    {
        printf("1. Add a New Process.\n");
        printf("2. Serve a Process.\n");
        printf("3. Display Information about Waiting Process.\n");
        printf("4. Number of Waiting Processes.\n");
        printf("5. Exit menu.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        if (choice==1)
        {
            printf("Enter Process Information:\n");
            printf("ID: ");
            scanf("%s",e.id);
            printf("Priority: ");
            scanf("%d",&e.Pr);
            insertNode(e,&prlist);
        }
        else if (choice==2)
        {
            if(!isEmpty(&prlist)){
            deleteNode(&e,&prlist);
            printf("YYYYYYYYYYYYYYYYY\n");
            printf("A Customer had served\nId: %s Priority: %d\n",e.id,e.Pr);
            printf("YYYYYYYYYYYYYYYYY\n");
            }
            else
            {
                printf("List underflow\n");
            }

        }
        else if (choice==3)
        {
            printf("The Waiting Process:\n");
            printf("YYYYYYYYYYYYYYYYY\n");
            Traverse(&prlist,&view);
            printf("YYYYYYYYYYYYYYYYY\n");
        }
        else if (choice==4)
        {
            int size=listSize(&prlist);
            printf("The number of Waiting Process: %d\n",size);
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
