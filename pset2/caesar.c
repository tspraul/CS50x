// Includes
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// Declare functions
char cipher(char p, int k);

// Main program
int main(int argc, string argv[])
{
// GET KEY
// Return error messages if invalid command line arguments:
// Check if none or more than one argument
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
// Check if arguments are digits
    for (int j = 0, n = strlen(argv[1]); j < n; j++)
    {
        if (argv[1][j] < 48 || argv[1][j] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
//printf("Key: %i\n", key);

// PROMPT FOR PLAINTEXT
    string plaintext = get_string("plaintext: ");

// ENCIPHER AND PRINT CIPHERTEXT
// Iterate over each character in plaintext
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", cipher(plaintext[i], key));
    }

// Print new line and exit program by returning main value of 0
    printf("\n");
    return 0;
}

// Functions

char cipher(char p, int k)
{
// Determine ciphertext (one character) from plaintext using key
    // If not letter, print as is
    if (!(isalpha(p)))
    {
        return p;
    }
    // If uppercase, rotate, preserve case, print
    // If lowercase, rotate, preserve case, print
    else
    {
        int c;
        if (isupper(p))
        {
            p = p - 64;
            c = ((p + k) % 26) + 64;
        }
        if (islower(p))
        {
            p = p - 96;
            c = ((p + k) % 26) + 96;
        }
        return c;
    }
}
