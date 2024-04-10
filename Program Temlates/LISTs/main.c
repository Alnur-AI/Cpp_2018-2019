#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *next;
}*list;


list create_list (int data){
    list empty_list = (list)malloc(sizeof(struct Node));
    empty_list->key = data;
    empty_list->next = NULL;
    return empty_list;
}

list push_front (list lst, int data){
    list temp = create_list(data);
    temp->next = lst;
    return temp;//Will I lose some memory after that?
}

list push_back (list lst, int data){
    list pointer_lst = lst;
    while (pointer_lst->next){
        pointer_lst = pointer_lst->next;
    }
    list temp = create_list(data);
    pointer_lst->next = temp;
    temp->next = NULL;
    return lst;//Will I lose some memory after that?
}

list delete_n_element_in_list (list lst, int n){ // Counting starts with 1;
    int elements_in_lst = how_much_elements_in_list(lst);
    if (n > elements_in_lst || n < 1 ){
        printf("Sorry, you number isn't laid in [1,n] segment\nYour list would remain unchanged\n");
        return lst;
    }

    if(n == 1){
        list pointer_lst = lst;
        lst = lst->next;
        free(pointer_lst);
        return lst;
    }
    list prev_pointer_lst = lst;
    int counter = 1;

    while (prev_pointer_lst->next){//n-1
        counter++;
        if (counter == n) break;
        prev_pointer_lst = prev_pointer_lst->next;
    }
    list curr_pointer_lst = prev_pointer_lst->next;//n
    list next_pointer_lst = curr_pointer_lst->next;//n+1

    prev_pointer_lst->next = next_pointer_lst;

    curr_pointer_lst->next = NULL;
    free(curr_pointer_lst);

    return lst;
}

list delete_the_whole_list (list lst){
    list pointer_lst;
    while (lst){
        pointer_lst = lst;
        lst = lst->next;
        free(pointer_lst);
    }
    return lst;
}

int max_element_in_list (list lst){
    int counter = 0;
    int howMuchElements = how_much_elements_in_list (lst);
    int array[howMuchElements];
    list pointer_list = lst;
    while (pointer_list){
        array[counter++] = pointer_list->key;
        pointer_list = pointer_list->next;
    }

    int local_max;
    int global_max = array[0];

    for (int i = 0; i < howMuchElements - 1; i++){
        local_max = max_of_two_elements(array[i], array[i + 1]);
        global_max = max_of_two_elements(local_max, global_max);
    }
    return global_max;
}

int min_element_in_list (list lst){
    int counter = 0;
    int howMuchElements = how_much_elements_in_list (lst);
    int array[howMuchElements];
    list pointer_list = lst;
    while (pointer_list){
        array[counter++] = pointer_list->key;
        pointer_list = pointer_list->next;
    }

    int local_min;
    int global_min = array[0];

    for (int i = 0; i < howMuchElements - 1; i++){
        local_min = min_of_two_elements(array[i], array[i + 1]);
        global_min = min_of_two_elements(local_min, global_min);
    }
    return global_min;
}

int how_much_elements_in_list (list lst){
    int counter = 0;
    list pointer_lst = lst;
    while (pointer_lst){
        pointer_lst = pointer_lst->next;
        counter++;
    }
    return counter;
}

    int max_of_two_elements (int a, int b){

    if (a > b){
        return a;
    }
    if (a < b){
        return b;
    }
    if (a == b){
        return a;
    }

    }

    int min_of_two_elements (int a, int b){

    if (a > b){
        return b;
    }
    if (a < b){
        return a;
    }
    if (a == b){
        return a;
    }

    }

int element_with_this_value (list lst, int data){
    int counter = 1;
    list pointer_lst = lst;
    int howMuchElements = how_much_elements_in_list (lst);
    while (pointer_lst){
        if (pointer_lst->key == data) return counter;
        counter++;
        pointer_lst = pointer_lst->next;
    }
    printf("\nSorry, they are no node with this value\nYour int would get 0 value\n");
    return;
}

void is_list_empty(list lst){
    if (lst == NULL) printf("\nYour list is empty\n");
    else printf("\nYour list isn't empty\n");
}

void print_list (list lst){
    list pointer_lst = lst;
    while (pointer_lst){
        printf("%d ", pointer_lst->key);
        pointer_lst = pointer_lst->next;
    }
}

int main()
{
    list lst = create_list(3);
    lst = push_front(lst, 2);
    lst = push_front(lst, 1);
    lst = push_back(lst, 4);
    lst = push_back(lst, 5);
    lst = push_back(lst, 6);
    print_list(lst);
    return 0;
}
