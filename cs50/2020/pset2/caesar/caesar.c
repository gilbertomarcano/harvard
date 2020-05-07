/*
Supposedly, Caesar (yes, that Caesar) used to “encrypt” (i.e., conceal in a
reversible way) confidential messages by shifting each letter therein by some
number of places. For instance, he might write A as B, B as C, C as D, …, and,
wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar
might write IFMMP. Upon receiving such messages from Caesar, recipients would
have to “decrypt” them by shifting letters in the opposite direction by the
same number of places.

The secrecy of this “cryptosystem” relied on only Caesar and the recipients
knowing a secret, the number of places by which Caesar had shifted his letters
(e.g., 1). Not particularly secure by modern standards, but, hey, if you’re
perhaps the first in the world to do it, pretty secure!

Unencrypted text is generally called plaintext. Encrypted text is generally
called ciphertext. And the secret used is called a key.
*/

#include <stdio.h>
#include <ctype.h>

#include "../../cs50.h"

int main(int argc, char** argv)
{
    // Counting Command-Line Arguments.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Get the key.
        char* end;
        int k = strtol(argv[1], &end, 10);

        // Validating the key.
        if (*end)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // Get the plaintext.
            char* plaintext = get_string("plaintext:  ");

            unsigned int length = strlen(plaintext);
            char ciphertext[length];

            // Encipher.
            for (unsigned int i = 0; i < length; i++)
            {
                if (islower(plaintext[i]))
                {
                    // Lowercase letters, though rotated, must remain lowercase letters.
                    ciphertext[i] = (plaintext[i] - 'a' + k) % 26 + 'a';
                }
                else if (isupper(plaintext[i]))
                {
                    // Capitalized letters, though rotated, must remain capitalized letters.
                    ciphertext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
                }
                else
                {
                    // Everything else must remain the same.
                    ciphertext[i] = plaintext[i];
                }
            }
            ciphertext[length] = '\0';

            // Print the ciphertext.
            printf("ciphertext: %s\n", ciphertext);
        }
    }
}