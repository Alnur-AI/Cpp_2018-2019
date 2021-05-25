#include <stdio.h>
#include <stdlib.h>

#define N 10
int a[N];
int b[N];
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

pnode rebuildSearch (int n){
    if ( n == 0 ) return NULL;
    pnode r = newNode(b[curPos++]);
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
    pnode rebuilded;
    for (int i = 1; i < N; i++)
    {
        a[i] = i;
        b[i-1] = i;
    }
    root = buildTree(1);
    rebuilded = rebuildSearch(N - 1);
    printTree(root);
    printf("\n");
    printTree(rebuilded);
    return 0;
}
