#include<stdio.h>

#define True 1
#define False 0

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] =
{
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember",
};

int inputyear(void)
{
    int year;
    printf("Enter a year (Example: 2004) : ");
    scanf("%d", &year);
    return year;
}

int determineLeapyear(int year)
{
    if(year % 4 == False && year % 100 != False || year % 400 == False)
    {
        days_in_month[2] = 29;
        return True;
    }
    else
    {
        days_in_month[2] = 28;
        return False;
    }
}

int determinedaycode(int year)
{
    double d1, d2, d3;
    int daycode;

    d1 = (year - 1) / 4.0;
    d2 = (year - 1) / 100.0;
    d3 = (year - 1) / 400.0;
    daycode = (int)(year + d1 - d2 + d3) % 7;

    return daycode;
}

void Calender(int year, int daycode)
{
    int month, day;

    for(month = 1; month <= 12; month++)
    {
        printf("%s", months[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri Sat\n");

        for(day = 1; day <= 1 + daycode * 5; day++)
        {
            printf(" ");
        }

        for(day = 1; day <= days_in_month[month]; day++)
        {
            printf("%2d", day);

            if((day + daycode) % 7 > 0)
                printf("  ");
            else
                printf("\n ");
        }

        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main(void)
{
    int year, daycode, Leapyear;
    year = inputyear();
    daycode = determinedaycode(year);
    determineLeapyear(year);
    Calender(year, daycode);
    printf("\n");

    return 0;
}
