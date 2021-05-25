#include <stdio.h>
#include <math.h>

double PolynomCalc(int n, double *a, double x)
{
    double sum = 0;
    for(int tempPower = 0; tempPower <= n; tempPower++)
    {
        sum += (a[tempPower] * pow(x,tempPower) );
    }
    return sum;
}

int main()
{
    printf("This program counting the polynomals such as a0 + a1X + a2X^2 + a3X^3...\n\n");

    printf("What size of polynomal are you want to calculate?\n");
    int constPower;
    scanf("%d",&constPower);

    printf("Okay! Now, put your constants a1,a2,a3... here:\n");
    double arr[constPower + 1];
    for (int i = 0; i <= constPower; i++)
    {
        scanf("%lf",&arr[i]);
    }
    printf("Your polynomal is: ");
    for (int i = 0; i <= constPower; i++)
    {
        if (arr[i]>=0)
        {
           printf("+%lf (X ^ %d) ",arr[i], i);
        }
        if (arr[i]<0)
        {
           printf(" %lf (X ^ %d) ",arr[i], i);
        }
    }

    printf("\nAnd the last one: Put the value of x here: ");
    double variable;
    scanf("%lf", &variable);

    printf("Your answer is: %lf", PolynomCalc(constPower, arr, variable) );
    getch();
    return 0;
}
