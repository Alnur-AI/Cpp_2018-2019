#include <stdio.h>
#include <stdlib.h>

#define N 8
int a[N];
int curPos = 0;

typedef struct Node{
    int item;
    struct Node *left, *right;
}*pnode;

pnode newNode (int i){
    pnode n = malloc(sizeof(struct Node));
    if (n == NULL)
    {
        fprintf(stderr,"ERROR\n");
        exit(1);
    }
    n->item = i;
    n->left = n->right = NULL;
}

pnode buildTree(int i){
    if ( i >= N ) return NULL;
    pnode r = newNode(a[i]);
    r->left = buildTree(2 * i);
    r->right = buildTree(2 * i + 1);
    return r;
}

void printTree(pnode r)
{
    if (r == NULL) return;
    printf(" %d ", r->item);
    printf("(");
    printTree(r->left);
    printf("),(");
    printTree(r->right);
    printf(")");
}
int main()
{
    pnode root;
    for (int i = 0; i < N; i++)
    {
        a[i]= i;
    }
    root = buildTree(1);
    printTree(root);
    return 0;
}
