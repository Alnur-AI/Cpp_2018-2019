#include <stdio.h>
#include <stdlib.h>

char input[] = "pEn, PiNeAPPle, aPPle, pEn, Yahoooo, ILUduDUduDu.";
typedef char* string;

typedef struct Node{
    string word;
    struct Node *next;
}*list;

int howMuchWords(string str){
    int counterWords = 0;
    int i = 0;
    while (str[i] != '.'){
        if (str[i] == ',') counterWords++;
        i++;
    }
    counterWords++;
    return counterWords;
}
int theLargestWordLetterNumber(string s){
    int wordsInString = howMuchWords(s);
    int stringsWordLetterNumber [wordsInString];
    int counterLetters = 0;
    int wordPosition = 0;
    int i = 0;

    while (s[i] != '.'){
        if (s[i] == ' '){
            i++;
            continue;
        }
        if (s[i] != ',') counterLetters++;
        else {
            stringsWordLetterNumber[wordPosition] = counterLetters;
            counterLetters = 0;
            wordPosition++;
        }
        i++;
    }
    if (s[i] == '.'){

    }
    for (int j = 0; j < wordsInString; j++){
        printf("\n%d\n", stringsWordLetterNumber[j]);
    }


    for (i = 0; i < wordsInString - 1; i++){
        if (stringsWordLetterNumber[i] <= stringsWordLetterNumber[i + 1]){
            continue;
        }
        else{
            stringsWordLetterNumber[i + 1] = stringsWordLetterNumber[i];
        }
    }
    int MAXwordsNumber = stringsWordLetterNumber[wordsInString - 1];
    return MAXwordsNumber;
}
list createNode(string w){
    list lst = (list)malloc(sizeof(struct Node));
    if (lst == NULL) printf("ERRORRR!!!");
    lst->word = w;
    lst->next = NULL;
    return lst;
}
list pushFront(list lst, string w){
    list temp = createNode(w);
    temp->next = lst;
    lst = temp;
    return lst;
}
list pushBack (list head, string w){
    list lst = head;
    list temp = createNode(w);
    //list temp = (list)malloc(sizeof(struct Node));
    //temp->word = w;
    //temp->next = NULL;
    while (lst->next != NULL) lst = lst->next;
    lst->next = temp;
    return head;
}
void printList(list lst){
    if (lst->next == NULL){
        printf("%s ", lst->word);
        return;
    }
    else{
        while (lst->next != NULL){
            printf("%s ", lst->word);
            lst = lst->next;
        }
    }
}
list initList(){
    list lst = (list)malloc(sizeof(struct Node));
    lst->next = NULL;
    return lst;
}

int main()
{
    list li = initList();
    li = pushFront(li,"second");
    li = pushFront(li,"first");
    li = pushBack(li, "third");
    printList(li);
    printf("\nWords: %d\nMax letters: %d", howMuchWords(input),theLargestWordLetterNumber(input));
    return 0;
}


