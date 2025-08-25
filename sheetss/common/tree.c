#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queueL.h"

void createTree(TreeType *pt) {
    *pt = NULL;
}
int isEmpty(TreeType *pt) {
    return (*pt == NULL);
}

int isFull(TreeType *pt) {
    return 0;
}
void clearTree(TreeType *pt) {
    if (*pt) {
        clearTree(&((*pt)->left));
        clearTree(&((*pt)->right));
        free(*pt);
        *pt = NULL;
    }
}
int treeSize(TreeType pt) {
    if (!pt)
        return 0;
    return 1 + treeSize(pt->left) + treeSize(pt->right);
}
int treeDepth(TreeType pt) {
    if (!pt)
        return 0;
    int l = treeDepth(pt->left);
    int r = treeDepth(pt->right);
    return (l > r ? l : r) + 1;
}
void preorder(TreeType pt, void (*pf)(TreeEntry)) {
    if (pt) {
        (*pf)(pt->entry);
        preorder(pt->left, pf);
        preorder(pt->right, pf);
    }
}
void inorder(TreeType pt, void (*pf)(TreeEntry)) {
    if (pt) {
        inorder(pt->left, pf);
        (*pf)(pt->entry);
        inorder(pt->right, pf);
    }
}
void postorder(TreeType pt, void (*pf)(TreeEntry)) {
    if (pt) {
        postorder(pt->left, pf);
        postorder(pt->right, pf);
        (*pf)(pt->entry);
    }
}
int insert(TreeType *pt, TreeEntry e)
{
    TreeNode *tn=(TreeNode*)malloc(sizeof(TreeNode));
    if(!tn){
        printf("Error in malloc");
        return 0;
    }
    tn->entry=e;
    tn->left=NULL;
    tn->right=NULL;
    if(!(*pt)) *pt=tn;
    else{
        TreeNode *pre,*cur;
        cur=*pt;
        while(cur){
            pre=cur;
            if(e<cur->entry)
                cur=cur->left;
            else
                cur=cur->right;
        }
        if (e < pre->entry)
            pre->left = tn;
        else
            pre->right = tn;
    }
    return 1;
}
int delet(TreeType *pt,TreeEntry *e)
{
    int found=0;
    TreeNode *q=*pt;
    TreeNode *r=NULL;
    while(q&&!(found=(e==q->entry))){
        r=q;
        if(e<q->entry)
            q=q->left;
        else
            q=q->right;
    }
    if(found){
        if (!r)
            deletNode(pt);
        else if((e<r->entry))
            deletNode(&r->left);
        else
            deletNode(&r->right);
    }
    return found;
}
void deletNode(TreeType *pt)
{
    TreeNode *q=*pt;
    if(!(q)->left)
        *pt=(q)->right;
    else if(!(q)->right)
        *pt=(q)->left;
    else
    {
        q=q->left;
        TreeNode *r=NULL;
        while(q->right){
            r=q;
            q=q->right;
        }
        (*pt)->entry=q->entry;
        if(r)
            r->right=q->left;
        else
            (*pt)->left=q->left;
    }
    free(q);
}
int leavesCount(TreeType pt)
{
    if (!pt)
        return 0;
    if (pt->left == NULL && pt->right == NULL)
        return 1;
    return leavesCount(pt->left) + leavesCount(pt->right);
}
int findClosest(TreeType pt, TreeEntry e) {
    if (pt == NULL) {
        printf("Empty tree\n");
        return -1;
    }

    TreeEntry closest = pt->entry;

    while (pt != NULL) {
        if (labs((long)pt->entry - (long)e) < labs((long)closest - (long)e)) {
            closest = pt->entry;
        }

        if (e < pt->entry) {
            pt = pt->left;
        } else if (e > pt->entry) {
            pt = pt->right;
        } else {
            return pt->entry;
        }
    }

    return closest;
}
void levelOrder(TreeType root,void (*pf)(TreeEntry)) {
    if (root == NULL)
        return;

    QueueL q;
    createQueueL(&q);
    AppendL(root, &q);

    while (!isQueueLEmpty(&q)) {
        TreeType current;
        ServeL(&current, &q);


        (*pf)(current->entry);

        if (current->left != NULL)
            AppendL(current->left, &q);

        if (current->right != NULL)
            AppendL(current->right, &q);
    }
}

