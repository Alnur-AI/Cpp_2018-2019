#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dd;
    int mm;
    int yy;
}date;

void printDate(date D);
date scanDate(date D);
date sumDays(date D, int day);
int howMuchDaysSinceTheOrigin (date D);

int main()
{
    int plusDays;
    date dt;
    printf("Please, write your date here (DD/MM/YYYY): ");
    dt = scanDate(dt);
    printf("Thanks! Now please put here how days are you want to add: ");
    scanf("%d", &plusDays);
    dt = sumDays(dt, plusDays);
    printf("Here is your new date: ");
    printDate(dt);
    printf("How much days had gone since 01/01/0001: %d", howMuchDaysSinceTheOrigin(dt));
    return 0;
}

void printDate(date D)
{
    printf("%.2d/%.2d/%d", D.dd, D.mm, D.yy);
}

date scanDate(date D)
{
    scanf("%d/%d/%d", &D.dd, &D.mm, &D.yy);
    return D;
}

date sumDays(date D, int day)
{
    if (day == 0)
    {
        return D;
    }
    int leftDays = day;
    int floatFebruary;
    while (1)
    {
        if (D.yy%400 == 0 || (D.yy%4 == 0 && D.yy%100 != 0))
        {
            floatFebruary = 29;
        }
        else
        {
            floatFebruary = 28;
        }

        //JANUARY
        if (D.mm == 1)
        {
            while (D.dd <= 31 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 2;
        }
        //February
        if (D.mm == 2)
        {
            while (D.dd <= floatFebruary )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 3;
        }
        //MARCH
        if (D.mm == 3)
        {
            while (D.dd <= 31 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 4;
        }
        //APRIL
        if (D.mm == 4)
        {
            while (D.dd <= 30 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 5;
        }
        //MAY
        if (D.mm == 5)
        {
            while (D.dd <= 31 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 6;
        }
        //JUNE
        if (D.mm == 6)
        {
            while (D.dd <= 30 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 7;
        }
        //JULY
        if (D.mm == 7)
        {
            while (D.dd <= 31 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 8;
        }
        //AUGUST
        if (D.mm == 8)
        {
            while (D.dd <= 31 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 9;
        }
        //SEPTEMBER
        if (D.mm == 9)
        {
            while (D.dd <= 30 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 10;
        }
        //OCTOBER
        if (D.mm == 10)
        {
            while (D.dd <= 31 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 11;
        }
        //NOVEMBER
        if (D.mm == 11)
        {
            while (D.dd <= 30 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 12;
        }
        //DECEMBER
        if (D.mm == 12)
        {
            while (D.dd <= 31 )
            {
                D.dd++;
                leftDays--;
                if (leftDays == 0)
                {
                    return D;
                }
            }
            D.dd = 1;
            D.mm = 1;
            D.yy++;
        }
    }
}

int howMuchDaysSinceTheOrigin (date D)
{
   int totalDays = 0;
   int floatFebruary;
    while (1)
    {
        if (D.yy%400 == 0 || (D.yy%4 == 0 && D.yy%100 != 0))
        {
            floatFebruary = 29;
        }
        else
        {
            floatFebruary = 28;
        }

        //DECEMBER
        if (D.mm == 12)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 30;
            D.mm = 11;
        }
        //NOVEMBER
        if (D.mm == 11)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 31;
            D.mm = 10;
        }
        //OCTOBER
        if (D.mm == 10)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 30;
            D.mm = 9;
        }
        //SEPTEMBER
        if (D.mm == 9)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 31;
            D.mm = 8;
        }
        //AUGUST
        if (D.mm == 8)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 31;
            D.mm = 7;
        }
        //JULY
        if (D.mm == 7)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 30;
            D.mm = 6;
        }
        //JUNE
        if (D.mm == 6)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 31;
            D.mm = 5;
        }
        //MAY
        if (D.mm == 5)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 30;
            D.mm = 4;
        }
        //APRIL
        if (D.mm == 4)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 31;
            D.mm = 3;
        }
        //MARCH
        if (D.mm == 3)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = floatFebruary;
            D.mm = 2;
        }
        //FEBRUARY
        if (D.mm == 2)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            D.dd = 31;
            D.mm = 1;
        }
        //JANUARY
        if (D.mm == 1)
        {
            while (D.dd > 0)
            {
                D.dd--;
                totalDays++;
            }
            if (D.dd == 1 && D.mm == 1 && D.yy == 1)
            {
                return totalDays;
            }
            D.dd = 31;
            D.mm = 12;
            D.yy--;
        }
    }
}
