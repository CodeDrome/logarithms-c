
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<stdlib.h>

char* currsym; // global variable for local currency symbol

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void calculateamounts(double startamount, double interest, int years);
void timetoamount(double startamount, double interest, double requiredamount);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main()
{
    // get set up for local number formatting and currency symbol
    setlocale(LC_ALL, "");
    const struct lconv* const currentlocale = localeconv();
    currsym = currentlocale->currency_symbol;

    puts("-----------------");
    puts("| codedrome.com |");
    puts("| Logarithms    |");
    puts("-----------------\n");

    calculateamounts(1000, 1.1, 12);

    timetoamount(1000, 1.1, 3138.43);

    return EXIT_SUCCESS;
}

//--------------------------------------------------------
// FUNCTION calculateamounts
//--------------------------------------------------------
void calculateamounts(double startamount, double interest, int years)
{
    // calculate and display amount after specified number of years
    double currentamount = startamount;
    double endamount = startamount * pow(interest, years);

    // calculate amounts for each year
    printf("startamount %s%'.2lf\n", currsym, startamount);
    printf("years       %d\n", years);
    printf("interest    %.2lf%%\n", (interest - 1) * 100);
    printf("endamount   %s%'.2lf\n\n", currsym, endamount);

    for(int y = 1; y <= years; y++)
    {
        currentamount*= interest;

        printf("Year %2d: %s%'.2lf\n", y, currsym, currentamount);
    }
}

//--------------------------------------------------------
// FUNCTION timetoamount
//--------------------------------------------------------
void timetoamount(double startamount, double interest, double requiredamount)
{
    double yearstorequiredamount = log(requiredamount / startamount) / log(interest);

    printf("\nstartamount           %s%'.2lf\n", currsym, startamount);
    printf("interest              %.2lf%%\n", (interest - 1) * 100);
    printf("requiredamount        %s%'.2lf\n", currsym, requiredamount);
    printf("yearstorequiredamount %lf\n\n", yearstorequiredamount);
}
