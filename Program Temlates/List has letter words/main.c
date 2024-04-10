#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *word;
    int count;
    int number;
    struct Node *next;
};

void printList(struct Node *list) {
    while(list != NULL) {
    printf("%s(%d), ", list -> word, list -> number);
    list = list -> next;
    }
}

int checkOrder(char *word, char *curWord) {
// return 1 — need to add curWord before word
// return 0 — need to add curWord after word
// return -1 — the words is equal => don't need to add curWord into list

    int i;

    for(i = 0; i < strlen(word); i++) {
        if (word[i] > curWord[i])
        return 1;
        else if (word[i] < curWord[i])
        return 0;
    }
    return -1;
}

struct Node *getNode(char *word, int num) {
    struct Node* p;

    p = malloc(sizeof(struct Node));
    p -> word = malloc(sizeof(char) * (strlen(word) + 1));
    strncpy(p -> word, word, sizeof(char) * strlen(word));
    p -> word[strlen(word)] = '\0';
    p -> count = strlen(word);
    p -> number = num;
    p -> next = NULL;

return p;
}

struct Node *addToList(struct Node *list, char *curWord, int num) {
    struct Node *curPtr, *prevPtr, *p, *head;

    if (list == NULL) {
        list = getNode(curWord, num);
        return list;
    }

    head = list;
    curPtr = list;
    prevPtr = list;
    while(curPtr != NULL) {
        if (checkOrder(curPtr -> word, curWord) == -1) {
            return list;
        } else if (checkOrder(curPtr -> word, curWord) == 1) {
            p = getNode(curWord, num);
            p -> next = curPtr;
            if (prevPtr == head)
            head -> next = p;
            else
            prevPtr -> next = p;
            return head;
        }
        prevPtr = curPtr;
        curPtr = curPtr -> next;
    }

    p = getNode(curWord, num);
    prevPtr -> next = p;

    return head;
}

struct Node **readText(struct Node **arrayLists) {
    char ch;
    char *tmpPtr, *word = NULL;
    int n = 0, num = 0;

    ch = getchar();
    while(ch != '.') {
        if (ch == ',') {
            num++;
            arrayLists[n - 1] = addToList(arrayLists[n - 1], word, num);
            n = 0;
            word = NULL;
        } else {
            n++;
            if (n == 1) {
                word = malloc(sizeof(char) * (n + 1));
                word[0] = ch;
                word[1] = '\0';
            } else {
                tmpPtr = word;
                word = realloc(word, sizeof(char) * (n + 1));
                strncpy(word, tmpPtr, sizeof(char) * (n - 1));
                word[n - 1] = ch;
                word[n] = '\0';
            }
        }

        ch = getchar();
    }

    if (n != 0) {
        arrayLists[n - 1] = addToList(arrayLists[n - 1], word, num + 1);
    }

    return arrayLists;
}

int main(void) {
    struct Node **arrayLists;
    int i;

    arrayLists = malloc(sizeof(struct Node *) * 6);
    for(i = 0; i < 6; i++) {
        arrayLists[i] = NULL;
    }

    arrayLists = readText(arrayLists);

    for(i = 0; i < 6; i++) {
        printf("List has %d-letter words: ", i + 1);
        printList(arrayLists[i]);
        printf("\n");
    }

    return 0;
}
