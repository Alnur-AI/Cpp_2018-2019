#include <stdio.h>
#include <stdlib.h>


int sumOfDigits(int n){
    int num = n;
    int sum = 0;
    num = n;
    sum += num%10;
    while (num != 0)
    {
        num = num/10;
        sum += num%10;
    }
    return sum;
}
int main()
{
    printf("Hello world!\n");
    printf("%d",sumOfDigits(1456));
    return 0;
}
