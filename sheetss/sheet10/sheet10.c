#include <stdio.h>
#include <stdlib.h>
#include "../common/tree.h"
#include "../common/queueL.h"

void print(TreeEntry e){
    printf("->%d",e);
}
void increamentB1(TreeEntry e){
    printf("->%d",e+1);
}

int main()
{
    TreeType tree;
    createTree(&tree);
    /////////////////////////////
    printf("##Q1##\n");
    printf("Solved in photo in the same folder\n");
    /////////////////////////////
    printf("##Q2##\n");
    printf("preOrder:");
    preorder(tree, &print);
    printf("\ninOrder:");
    inorder(tree, &print);
    printf("\npostOrder:");
    postorder(tree,&print);
    /////////////////////////////
    printf("\n##Q3##\n");
    printf("inOrder:");
    inorder(tree, &print);
    printf("\ninOrder(increamented):");
    inorder(tree, &increamentB1);
    /////////////////////////////
    printf("\n##Q4##\n");
    printf("search for 13...\n");
    TreeType tree2;
    createTree(&tree2);
    insert(&tree2, 10);
    insert(&tree2, 5);
    insert(&tree2, 15);
    insert(&tree2, 13);
    insert(&tree2, 7);
    insert(&tree2, 2);
    insert(&tree2, 9);
    insert(&tree2, 6);
    insert(&tree2, 11);
    insert(&tree2, 20);
    int foun=delet(&tree2, 2);
    printf("%d\n",foun);
    printf("search for 50...\n");
    foun=delet(&tree2, 50);
    printf("%d\n",foun);
    /////////////////////////////
    printf("##Q5##\n");
    printf("same as Q4\n");
    /////////////////////////////
    printf("##Q6##\n");
    int leaves=leavesCount(tree);
    printf("the number of leaves: %d\n",leaves);
    /////////////////////////////
    printf("##Q7##\n");
    int closest=findClosest(tree, 17);
    printf("the closest value for 17 is: %d\n",closest);
    /////////////////////////////
    printf("##Q8##\n");
    TreeType root;
    createTree(&root);

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 20);

    printf("Level-order traversal:");
    levelOrder(root,&print);
    clearTree(&tree);
    clearTree(&tree2);
    clearTree(&root);
    /////////////////////////////
    printf("##Q9##\n");
    printf("Solved in photo in the same folder\n");
    /////////////////////////////
    printf("##Q10##\n");
    printf("Solved in photo in the same folder\n");
    return 0;
}
