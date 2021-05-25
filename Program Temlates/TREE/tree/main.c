#include <stdio.h>
#include <stdlib.h>

#define N 7
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

pnode buildTree(int n){
    if ( n == 0 ) return NULL;
    pnode r = newNode(a[curPos++]);
    r->left = buildTree(n/2);
    r->right = buildTree(n - (n/2+1));
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
        a[i]= i + 1;
    }
    root = buildTree(N);
    printTree(root);
    return 0;
}
