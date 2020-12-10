// This program prompts the user for input (amount of change owed) and
// calculates the smallest number of coins that will sum to this value

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float one = 1; // penny
    float five = 5; // nickel
    float ten = 10; // dime
    float tf = 25; // quarter
    int count = 0;

    float changeInitial = get_float("Change owed? ");
    printf("%.2f\n", changeInitial);
    // round cents to nearest penny
    int change = round(changeInitial * 100);
    printf("ROUNDED: %i\n", change);

    // user input must be positive
    if (change > 0)
    {
        // check how many quarters go into 'change' and deduct from change
        int numOfTwentyFive = (change / tf);
        if (numOfTwentyFive > 0)
        {
            count = count + numOfTwentyFive;
            change = change - (numOfTwentyFive * tf);
            printf("25c=%i\n", numOfTwentyFive);
            printf("count=%i\n", count);
            printf("Total,%i\n", change);
        }

        // check how many dimes go into 'change' and deduct from change
        int numOfTen = (change / ten);
        if (numOfTen > 0)
        {
            count = count + numOfTen;
            change = change - (numOfTen * ten);
            printf("10c=%i\n", numOfTen);
            printf("count=%i\n", count);
            printf("Total,%i\n", change);
        }

        // check how many nickels go into 'change' and deduct from change
        int numOfFive = (change / five);
        if (numOfFive > 0)
        {
            count = count + numOfFive;
            change = change - (numOfFive * five);
            printf("5c=%i\n", numOfFive);
            printf("count=%i\n", count);
            printf("Total,%i\n", change);
        }

        // check how many pennies go into 'change' and deduct from change
        int numOfOne = (change / one);
        if (numOfOne > 0)
        {
            count = count + numOfOne;
            change = change - (numOfOne * one);
            printf("1c=%i\n", numOfOne);
            printf("count=%i\n", count);
            printf("Total,%i\n", change);
        }
    }
    else
    {
        // recursive call to method until user inputs correct value
        main();
    }
    printf("%d\n", count);
}
