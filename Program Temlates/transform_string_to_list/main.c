#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//"ABFSD, FEDF, ABCDEF, ACBEF, ED, FF, GED, ZEA, SDAS, ASDAS."
typedef char *string;
typedef struct Node{
    char *word;
    struct Node *next;
}*list;

list create_list (char *wrd){
    list new_list = (list)malloc(sizeof(struct Node));
    new_list->word = wrd;
    new_list->next = NULL;
    return new_list;
}

list push_back (list lst, char *wrd){
    list pointer_lst = lst;
    while (pointer_lst->next) pointer_lst = pointer_lst->next;
    list temp = create_list(wrd);
    pointer_lst->next = temp;
    temp->next = NULL;
    return lst;//Will I lose some memory after that?
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

void print_list (list lst){
    list pointer_lst = lst;
    while (pointer_lst){
        printf("%s -> ", pointer_lst->word);
        pointer_lst = pointer_lst->next;
    }
    printf("end-of-list\n");
}

void print_list_num (list lst){
    int counter = 1;
    list pointer_lst = lst;
    while (pointer_lst){
        printf("%d) %s ", counter, pointer_lst->word);
        pointer_lst = pointer_lst->next;
    }
}

list transform_string_to_list (string str){
    int first_word = 1;
    int letter_counter = 0;
    int counter = 0;
    char tempWORD[6];
    list new_list = NULL;
    while (1){
        //"ABFSD , FEDGGF, ABCDEF, ACBEF, ED, FF, GED, ZEA, SDAS, ASDAS."
        if (str[counter] == '.') break;
        if (str[counter] == ' ') {
            printf("SPACE\n");
            counter++;
            continue;
        }
        if (str[counter] == ','){
            printf("NewWord\n");
            for (int i = 0; i < 6; i++) tempWORD[i] = '*';
            counter++;
            continue;
        }
        if (str[counter] != ',' || str[counter] == ' '){
            while (str[counter + 1] != ','){
                printf("PutWORD\n");
                tempWORD[letter_counter] = str[counter];
                letter_counter++;
                counter++;
            }
            if (first_word == 1) {
                printf("first WORD\n");
                new_list = create_list(tempWORD);
                print_list(new_list);
                first_word = 0;
            }
            else{
                printf("other WORD\n");
                new_list = push_back(new_list, tempWORD);
                print_list(new_list);
            }
            letter_counter = 0;
            counter++;
        }
    }
    return new_list;
}

int main()
{
    list lst;
    string sent = "ABFSD , FEDF, ABCDEF, ACBEF, ED, FF, GED, ZEA, SDAS, ASDAS.";

    lst = transform_string_to_list (sent);
    print_list(lst);
    return 0;
}


/*
while (sent[counter] != '.'){
        printf("%d: ", counter + 1);
        if (sent[counter] == ' '){
            printf("space\n");
            counter++;
            continue;
        }
        if (sent[counter] == ','){
            printf("new word\n");
            if (lst == NULL) lst = create_list(tempWORD);
            else lst = push_back(lst, tempWORD);
            print_list_num(lst);
            printf("\n");
            for (int i = 0; i < 6; i++) tempWORD[i] = "*";
            letc = 0;
        }
        if (sent[counter] != ',' || sent[counter] != ' '){
            printf("WORD%d# letter\n",letc + 1);
            tempWORD[letc] = sent [counter];
            letc++;
            if (letc == 5) letc = 0;
        }
        counter++;
    }

*/
