/*

In a file called credit.c in a ~/pset1/credit/ directory, write a program that 
prompts the user for a credit card number and then reports (via printf) whether
it is a valid American Express, MasterCard, or Visa card number, per the 
definitions of each’s format herein. So that we can automate some tests of your
code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n
or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you may
assume that the user’s input will be entirely numeric (i.e., devoid of hyphens,
as might be printed on an actual card). But do not assume that the user’s input
will fit in an int!

Here are a few card numbers that PayPal recommends for testing.
American Express	378282246310005
American Express	371449635398431
MasterCard	        2221000000000009
MasterCard	        2223000048400011
MasterCard	        2223016768739313
MasterCard	        5555555555554444
MasterCard	        5105105105105100
Visa	            4111111111111111
Visa	            4012888888881881
Visa	            4222222222222
*/

#include <stdio.h>

#include "../../cs50.h"

int main(void)
{
    // Prompt for the number.
    //long number = get_long("Number: ");
    long number = 4012888888881881;
    if (number < 1)
    {
        // For zero and negative numbers.
        printf("INVALID\n");
    }
    else
    {
        // Get the length.
        unsigned int length = strlen(ultoa(number));

        if (length < 13 || length > 16)
        {
            // For not valid lengths.
            printf("INVALID\n");
        }
        else
        {
            int even_sum = 0;
            int odd_sum = 0;
            // Iterate over the number's array.
            const char* arr = ltoa(number);
            for (unsigned int i = 0; i < length; i++)
            {
                /* Get from last to first digit. 
                Substract '0' to get its correspond integer value. */
                unsigned char digit = arr[length - 1 - i] - '0';

                if (i % 2)
                {
                    /* Multiply every other digit by 2, starting with the 
                    number’s second-to-last digit, and then add those 
                    products’ digits together. */
                    digit *= 2;

                    /* Add the product's digit
                    (i.e., not the product itself) together if needed. */
                    if (strlen(utoa(digit)) == 2)
                    {
                        int first_digit = itoa(digit)[0] - '0';
                        int second_digit = itoa(digit)[1] - '0';
                        digit = first_digit + second_digit;
                    }
                    even_sum += digit;
                }
                else
                {
                    odd_sum += digit;
                }
            }
            /* Add the sum to the sum of the digits 
            that weren’t multiplied by 2. */
            int sum = even_sum + odd_sum;
            if (sum % 10)
            {
                printf("INVALID\n");
            }
            else
            {
                int first_digit = ltoa(number)[0] - '0';
                switch (first_digit)
                {
                    case 2:
                    case 5:
                        printf("MASTERCARD\n");
                        break;
                    case 3:
                        printf("AMEX\n");
                        break;
                    case 4:
                        printf("VISA\n");
                        break;
                    default:
                        printf("INVALID\n");
                }
            }

        }
    }
}