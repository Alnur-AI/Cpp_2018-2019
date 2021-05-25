#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef int item;
typedef struct {
    item items[N];
    int top;
    int size;
}stack;

void initStk(stack *stk){
    stk->top = -1;
    stk->size = 0;
}

bool isEmpty (stack*stk){
    return (stk->size == 0);
}

bool isFull(stack *stk){
    return (stk->size==N);
}

int push (stack *stk, item it){
    if (isFull(stk)) return 0;
    stk->items[++stk->top] = it;
    stk->size++;
    return 1;
}

item top (stack stk){
    return (stk.items[stk.top]);
}

int pop(stack *stk){
    if (isEmpty(stk)) return 0;
    stk->top--; stk->size--;
    return 1;
}

int isDig(int c){
    return (c >= '0' && c <= '9');
}

int isOp(int c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int prior(int c){
    return ( c == '*' || c == '/');
}

void int2pos(FILE *fin, FILE *fpost){
    stack stk;
    int c, t;
    initStk(&stk);
    push(&stk, '(');
    while (((c=fgetc(fin)))!= EOF){
        if (isDig(c)) fputc(c, fpost);
        else if (c == '(') push(&stk, c);
        else if (isOp(c)){
            while ( isOp(t=top(stk)) && prior(t)>= prior(c) ){
                fputc(t,fpost);
                pop(&stk);
            }
        push(%stk, c);
        }
        else if (c == ')'){
            while ( t=top(stk) != '(' ){
                fputc(t, fpost);
                pop(&stk);
            }
            pop(&stk);
        }
    }
}
int main(void)
{
    FILE *fin, *fout;
    if ((fin = fopen("infix.txt","r") == NULL)){
        fprintf(stderr, "infix.txt not opened \n");
        exit(1);
    }
    if ((fout = fopen("postfix.txt","w") == NULL)){
        fprintf(stderr, "postfix.txt not opened \n");
        fclose(fin);
        exit(1);
    }
    int2pos(fin,fout);
    fclose(fin);
    fclose(fout);
    return 0;
}
/*

//TASK 4
int how_much_levels (tree T,int E){
    if (T==NULL) return -1;
    if (T->item == E) return 0;

    if (T->item > E){
        E = how_much_levels(T->left, E);
        if (E == -1) return -1;
        return 1 + E;
    }

    if (T->item < E)
    {
        E = how_much_levels(T->right, E);
        if (E == -1) return -1;
        return 1 + E;
    }

}

*/
