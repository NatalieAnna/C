// CS50 pset week 1 (Mario)
// Builds a pyramid from user input using the # symbol and white space
// Expected output if height = 4:
//    #
//   ##
//  ###
// ####

#include <stdio.h>
#include <cs50.h>

// my own method definition, checking that inputted value is between 1 & 8
#define BETWEEN(value, min, max)  (value < max && value > min)

// prompts user for positive integer between 1 & 8 and uses this value to print pyramid
// if incorrect input, method called recursively
int main(void)
{
    int height = get_int("Input a positive number between 1 & 8: ");
    if (BETWEEN(height, 0, 9))
    {
        // row
        for (int i = 0; i < height; i++)
        {
            // dots
            for (int k = i + 1;  k < height; k++)
            {
                // printf("%format-specifier",variable);
                // format-specifier is datatype ie char
                // variable is what is printed/displayed
                int space = ' ';
                printf("%c", space);
            }
            // hashes
            for (int j = height - i; j <= height; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    // recursive call to continue asking user for input if input provided is incorrect
    else
    {
        main();
    }
}
