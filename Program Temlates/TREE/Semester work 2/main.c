#include <stdio.h>
#include <stdlib.h>

struct tree{
    char *word;
    struct tree *left;
    struct tree *right;
};

void create_tree ()

int main(){
    struct tree *ttree;
    char *input = "asdas,bsdfdsf,cdsfsdf,dsdf,edfdgdfg";

    ttree = malloc(sizeof(struct tree));
    ttree->word = "asdfg";
    printf("%s", ttree->word);

    return 0;
}
