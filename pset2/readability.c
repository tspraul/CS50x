// Includes
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Declare functions
float avg_two_numbers(float n, float d);
float readability(float L, float S);

int main(void)
{
    // Get input from user
    string text = get_string("Text: ");
    
    // Determine number of letters, words, and sentences in input text (loop through array checking for each)
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (toupper(text[i]) > 64 && toupper(text[i]) < 91)
        {
            letters++;
        }
        if (text[i] == 32)
        {
            words++;
        }
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    //printf("%i %i %i\n", letters, words, sentences);
    //printf("%f %f\n", avg_two_numbers(letters, words), avg_two_numbers(sentences, words));
    
    
    // Calculate readability index via function call
    int X = round(readability(avg_two_numbers(letters, words) * 100, avg_two_numbers(sentences, words) * 100));
    //printf("%f\n", readability(avg_two_numbers(letters, words), avg_two_numbers(sentences, words)));
    
    // Determine output based on readability
    if (X >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (X < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", X);
    }
}

// Functions
float avg_two_numbers(float n, float d)
{
    float a = n / d;
    return a;
}

float readability(float L, float S) 
// L is the average number of letters per 100 words in the text, S is the average number of sentences per 100 words in the text
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}