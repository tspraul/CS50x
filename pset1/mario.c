#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for pyramid size
    int size = 0;
    do
    {
        size = get_int("How tall do you want your pyramid? (1-8)?\n");
    }
    while (size < 1 || size > 8);
    
    // Print pyramid using hashtags according to size input by user
    for (int r = 1; r < size + 1; r++)
    {
        for (int space = 0; space < size - r; space++)
        {
            printf(" ");
        }
        for (int hashtag = 0; hashtag < r; hashtag++)
        {
            printf("#");
        }
        printf("\n");
    }
}