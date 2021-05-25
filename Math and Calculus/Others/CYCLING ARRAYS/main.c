#include <stdio.h>
#include <stdlib.h>

    void cycle_right_array(int a[],  int a_size){
        int a_temp[a_size];
        a_temp[0] = a[a_size - 1];
        for (int i = 0; i < a_size - 1; i++){
            a_temp [i + 1] = a [i];
        }
        for (int i = 0; i < a_size; i++){
            a [i] = a_temp[i];
        }
    }

    void cycle_left_array(int a[],  int a_size){
        int a_temp[a_size];
        a_temp[a_size - 1] = a[0];
        for (int i = 0; i < a_size - 1; i++){
            a_temp [i] = a [i + 1];
        }
        for (int i = 0; i < a_size; i++){
            a [i] = a_temp[i];
        }
    }

    void cycle_right_array_n_times (int a[],  int a_size, int n_times){
        int a_temp[a_size];
        if (n_times < 0) n_times = n_times * (-1);
        if (n_times > 5) n_times = n_times % 5;
        if (n_times == 0) return;

        for (int i = 0; i < n_times; i++){
            cycle_right_array (a, a_size);
        }
    }

    void cycle_left_array_n_times (int a[],  int a_size, int n_times){
        int a_temp[a_size];
        if (n_times < 0) n_times = n_times * (-1);
        if (n_times > 5) n_times = n_times % 5;
        if (n_times == 0) return;

        for (int i = 0; i < n_times; i++){
            cycle_left_array(a, a_size);
        }
    }

    void print_array(int a[], int n){
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");
    }

int main()
{
    int array [5] = { 1, 2, 3, 4, 5 };

    printf("\nLEFT SHIFT: ");
    print_array(array, 5);
    for (int i = 1; i < 11; i++){
        printf("%d: ",i );
        cycle_left_array_n_times(array, 5, 1);
        print_array(array, 5);
    }

    printf("\nRIGHT SHIFT: ");
    print_array(array, 5);
    for (int i = 11; i < 21; i++){
        printf("%d: ",i );
        cycle_right_array_n_times(array, 5, 1);
        print_array(array, 5);
    }

    return 0;
}
