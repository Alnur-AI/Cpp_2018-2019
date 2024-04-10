#include <stdio.h>
#include <stdlib.h>

int main()
{
    //          "dfd394JIJFDSj3fdsodf"
    char str[] = "3f433.";
    int rax = 0;//rax
    int numbers = 0;//rbx
    char temp;

    printf("%s\n", str);
    while (1){// find number
        if (str[rax] == '.') break;
        if (str[rax] <= '9' && str[rax] >= '0'){//number founded
            temp = str[rax];
            str[rax] = str[numbers];
            str[numbers] = temp;
            numbers++;
        }
        rax++;
    }
    printf("%s\n", str);
    return 0;
}


/*
str[i] != '.'
    9ght343e
    9343ghte

    eh32hf2634
    322634ehhf


*/
