#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void printARRAY (int x, int y, int **A){
    for (int j = 0; j < y; j++){
        for (int i = 0; i < x; i++){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),rand()%15+1);
            A[i][j] = rand()%10;
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
}



void fillDWO_DIM_ARRAY (int x, int y, int **A){
    for (int j = 0; j < y; j++){
        for (int i = 0; i < x; i++){
            A[i][j] = rand()%10;
        }
    }
}

int main()
{
    int x = 20;
    int y = 20;
    int **A;
    *A = (int)malloc(x*sizeof(int));
    for(int i = 0; i < x; i++){
        A[i] = (int)malloc(y*sizeof(int));
    }

    srand(time(0));
    for (int j = 0; j < y; j++){
        for (int i = 0; i < x; i++){
            A[i][j] = rand()%10;
        }
    }

    printARRAY(x,y,A);
    return 0;
}
