#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

typedef struct Node {
    int key;
    struct Node *next;
}*stack;

stack create_node (int data){
    stack empty_node = (stack)malloc(sizeof(struct Node));
    empty_node->key = data;
    empty_node->next = NULL;
    return empty_node;
}

stack init (stack lst){
    lst = NULL;
    return lst;
}

stack push (stack lst, int data){
    if (stack_height(lst) > NMAX - 1){
        printf("PUSH %d: STACK OVERFLOW!\n", data);
        return lst;
    }
    stack temp = create_node(data);
    temp->next = lst;
    return temp;//Will I lose some memory after that?
}

int stack_height(stack lst){
    if (lst == NULL){
        return 0;
    }
    else{
        stack p_lst = lst;
        int counter = 0;
        while (p_lst){
            p_lst = p_lst->next;
            counter++;
        }
        return counter;
    }
}

stack pop (stack lst){
    if (stack_height(lst) == 0){
        printf("POP: STACK UNDERFLOW!\n");
        return lst;
    }
    stack temp = lst;
    lst = lst->next;
    free (temp);
    return lst;
}

int dont_delete_and_get_top_of_stack (stack stk){
    int top_of_stack = stk->key;
    return top_of_stack;
}

void print_stack (stack lst){
    stack pointer_lst = lst;
    printf("-----Your Stack-----\n");
    int temp = stack_height(lst);
    while (pointer_lst){
        printf("Element #%d: %d\n", temp--, pointer_lst->key);
        pointer_lst = pointer_lst->next;
    }
    printf("----END OF STACK----\n");
}

int main()
{
    stack lst = init (lst);
    lst = push(lst, 4);
    lst = push(lst, 3);
    lst = push(lst, 2);
    lst = push(lst, 1);
    //lst = pop(lst);
    print_stack(lst);
    return 0;
}


/*
int take_top_of_stack (stack stk){//WTF?????
    int top_of_stack = stk->key;
    stack temp = stk;
    //free (temp);
    stk = stk->next;
    return top_of_stack;
}


stack push (stack lst, int data){
    if (lst == NULL){
        lst = create_node(data);
        return lst;
    }

    stack pointer_lst = lst;
    while (pointer_lst->next){
        pointer_lst = pointer_lst->next;
    }
    stack temp = create_node(data);
    pointer_lst->next = temp;
    temp->next = NULL;
    return lst;//Will I lose some memory after that?
}
*/
