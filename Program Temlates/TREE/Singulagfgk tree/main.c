#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
    int item;
    struct Node *left, *right;
}*tree;

tree newNode (int i){
    tree n = malloc(sizeof(struct Node));
    if (n == NULL)
    {
        fprintf(stderr,"ERROR\n");
        exit(1);
    }
    n->item = i;
    n->left = n->right = NULL;
}


void printTree(tree r)
{
    if (r == NULL) return;
    printf(" %d ", r->item);
    printf("(");
    printTree(r->left);
    printf("),(");
    printTree(r->right);
    printf(")");
}

tree perfectBuildTree(int count, int n)
{
    if (count > n) return NULL;
    tree r = newNode(count);
    r->left = perfectBuildTree(count + 1,n);
    r->right = perfectBuildTree(count + 1,n);
    return r;
}

int main()
{
    int n;
    scanf("%d",&n);
    tree t1;
    t1 = perfectBuildTree(1,n);
    printTree(t1);
}
