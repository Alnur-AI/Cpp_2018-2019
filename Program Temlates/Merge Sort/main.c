#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[4] = {1, 3, 5, 67};
    int arr2[4] = {6, 8, 12, 65};
    int arr3[8];

    for (int i = 0 ; i < 8; i++){
        if(i <  4){
            arr3[i] = arr1[i];
            printf("%d ", arr3[i]);
            continue;
        }
        arr3[i] = arr2[i - 4];
        printf("%d ", arr3[i]);
    }
    for (int i = 0; i < 7; i++)
        if(arr3[i] >= arr3[i + 1]){
            int temp = arr3[i + 1];
            arr3[i + 1] = arr3[i];
            arr3[i] = temp;
            continue;
        }
    printf("\n");

    for (int i = 0 ; i < 8; i++)
        printf("%d ", arr3[i]);


    return 0;
}
