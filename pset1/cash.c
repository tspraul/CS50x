#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Prompts user for change owed, not accepting negative values or stings
    float dollars;
    do
    {
        dollars = get_float("How much change are you owed?\n");
    }
    while (dollars < 0);
    
    //Convert dollars to cents
    int cents;
    cents = round(dollars * 100);
    
    //Calculate the minimum number of coins
    int q = 25, d = 10, n = 5, p = 1, coins = 0;
    while (cents >= q)
    {
        cents = cents - q;
        coins++;
    }
    while (cents >= d)
    {
        cents = cents - d;
        coins++;
    }    
    while (cents >= n)
    {
        cents = cents - n;
        coins++;
    }    
    while (cents >= p)
    {
        cents = cents - p;
        coins++;
    }
    
    //Print the minimum number of coins with which the change can be made
    printf("%i\n", coins);
}