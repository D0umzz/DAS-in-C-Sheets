#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef int TreeEntry;

typedef struct treenode{
    TreeEntry entry;
    struct treenode *left, *right;
}TreeNode;

typedef TreeNode *TreeType;

void createTree (TreeType *pt);
int isEmpty(TreeType *pt);
int isFull(TreeType *pt);
void clearTree (TreeType *pt);
int treeSize(TreeType pt);
int treeDepth (TreeType pt);
void preorder (TreeType pt, void (*pf)(TreeEntry));
void inorder (TreeType pt, void (*pf)(TreeEntry));
void postorder (TreeType pt, void (*pf)(TreeEntry));
int insert(TreeType *pt,TreeEntry e);
int delet(TreeType *pt,TreeEntry *e);
void deletNode(TreeType *pt);
int leavesCount(TreeType pt);
int findClosest(TreeType pt, TreeEntry e);
void levelOrder(TreeType root,void (*pf)(TreeEntry));
#endif // TREE_H_INCLUDED
