#include <stdio.h>

#include "../../cs50.h"

int main(void)
{
    // Prompt for the number.
    long number = get_long("Number: ");

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
