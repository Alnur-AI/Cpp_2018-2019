#include <stdio.h>

//int a = 10;
//int b = 20;
//int result;

int main()
{
    int data1 =10;
    int data2 = 20;
    int result;
    asm("imull %%edx, %%ecx\n\t"
        "movl %%ecx, %%eax"
        :"=a"(result)
        :"d" (data1), "c" (data2));
    printf("%d",result);

    return 0;
}
/*
asm ("assem code":output locations:input operands:change registers);
            2           3               1               4

asm ("push a\n\t"
         "movl a, %eax\n\t"
         "movl b, %ebx\n\t"
         "imull %ebx, %eax\n\t"
         "movl %eax, result\n\t"
         "pop a");
    printf("%d",result);
*/
