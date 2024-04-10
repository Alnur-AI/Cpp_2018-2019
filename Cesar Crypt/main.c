#include <stdio.h>
#include <stdlib.h>

int main(void){
    ///STEP 0: INITIALIZATION
    char buffer[1024];
    FILE* fnc;

    ///STEP 1: OPEN AND GET UNCRYPTED FILES
    if (fopen("uncrypted.txt","r") == NULL)
        return 0;
    fnc = fopen("uncrypted.txt","r");
    fgets(buffer, 1024,fnc);
    fclose(fnc);

    ///STEP 2: USE CEASAR CRYPTING
    for (int i = 0; buffer[i] != '\0'; i++)
        buffer[i] += 1;

    ///STEP 3: INPUT BUFFER TO NEW FILE
    if (fopen("crypted.txt","w") == NULL)
        return 0;
    fnc = fopen("crypted.txt","w");
    fprintf(fnc,"%s" ,buffer);
    fclose(fnc);

    ///STEP 4: END
    return 0;
}
