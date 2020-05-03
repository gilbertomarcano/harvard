/*
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

int get_length(long number);

int get_digit(long number, int index);

int main(void)
{
    // Prompt for the number.
    long number; 
    printf("Number: ");
    scanf("%li", &number);

    if (number < 1)
    {
        // For zero and negative numbers.
        printf("INVALID\n");
    }
    else
    {
        // Get the length.
        unsigned int length = get_length(number);

        if (length < 13 || length > 16)
        {
            // For not valid lengths.
            printf("INVALID\n");
        }
        else
        {
            int even_sum = 0;
            int odd_sum = 0;
            for (unsigned int i = 0; i < length; i++)
            {
                int digit = get_digit(number, length - i);
                if (i % 2)
                {
                    digit *= 2;
                    if (get_length(digit) == 2)
                    {
                        digit = get_digit(digit, 1) + get_digit(digit, 2);
                    }
                    even_sum += digit;
                }
                else
                {
                    odd_sum += digit;
                }
            }
            int sum = even_sum + odd_sum;
            if (sum % 10)
            {
                printf("INVALID\n");
            }
            else
            {
                int first_digit = get_digit(number, 1);
                switch (get_digit(number, 1))
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
// 2019
int get_digit(long number, int index)
{
    unsigned int length = get_length(number);

    if (index > 0 && index <= length)
    {
        for (unsigned short i = 0; i < length - index; i++)
        {
            number /= 10;
        }
        return number % 10;
    }
    return -1;
}

int get_length(long number)
{
    number = number < 0 ? number * -1 : number;
    unsigned int length = 0;
    while (number != 0)
    {
        length++;
        number /= 10;
    }
    return length;
}