#include <stdio.h>
#include <stdlib.h>

#define NMAX 20
typedef struct Stack {
  int elem [NMAX + 1];
  int top;
}*stack;



void init(stack stk) {
    stk->top = 0;
}

void push (stack stk, int data){
    stk->top++;
    if (stk->top > NMAX) {
        printf("PUSH %d: STACK OVERFLOW! STACK IS FULL! OPERATION CANCELLED!\n", data);
        stk->top--;
        return;
    }
    else{
        stk->elem [stk->top] = data;
    }
}

void pop (stack stk){
    if (stk->top <= 0 ){
        printf("POP: STACK UNDERFLOW! STACK IS EMPTY! OPERATION CANCELLED!\n");
        return;
    }
    else{
        stk->top--;
    }
}

void stack_is_empty(stack stk){
    printf("\nChecking: IS STACK EMPTY?\n");
    if (stk->top < 0) printf("ERROR!!! STACK UNDERFLOW!\n");
    if (stk->top > NMAX) printf("ERROR!!! STACK OVERFLOW!\n");
    if (stk->top == 0) printf("Stack is empty!\n");
    if (stk->top > 0 && stk->top <= NMAX) printf("stack isn't empty!\n");
}

int dont_delete_and_get_top_of_stack (stack stk){
    if (stk->top == 0){
        printf("GET TOP OF STACK: STACK IS EMPTY! YOU WILL GET 0 AS AN ANSWER\n");
        return 0;
    }
    else return stk->elem[stk->top];
}

int take_top_of_stack (stack stk){
    if (stk->top == 0){
        printf("TAKE TOP OF STACK: STACK IS EMPTY! YOU WILL GET 0 AS AN ANSWER\n");
        return 0;
    }
    else
    {
        return stk->elem [stk->top--];
    }
}

void print_stack (stack stk){
    printf("-----Your Stack-----\n");
    int temp = stk->top;
    while (temp != 0){
        printf("Element #%d: %d\n",temp + 1, stk->elem[temp--]);
    }
    printf("----END OF STACK----\n");
}


int main()
{
    //stack stk = (struct Stack*)malloc(sizeof(struct Stack));
    //stack stk = (stack)malloc(sizeof(stack*));
    stack stk = malloc(sizeof(stack*));
    init(stk);

    push(stk, 62);
    push(stk, 3);
    push(stk, 1);
    push(stk, 2);

    print_stack(stk);
    return 0;
}
