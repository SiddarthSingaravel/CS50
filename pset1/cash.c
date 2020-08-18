#include<stdio.h>
#include<math.h>
#include<cs50.h>

//declaring function for counting coins
int count_coins(string prompt);

int main(void)
{
    float val = count_coins("Change owed: ");
    int num = round(val);
    printf("%i\n", num);
}

//writing the function
int count_coins(string prompt)
{
    float change;
    do
    {
        change = get_float("%s", prompt);
    }
    while (change < 0);
    int cents = round(change * 100);
    //intializing count
    int count = 0;

    //now performing counting of coins

    //checking cents are greater than 25 cents
    while (cents >= 25)
    {
        count ++;
        cents = cents - 25;
    }

    //checking cents are greater than 10 cents
    while (cents >= 10)
    {
        count ++;
        cents = cents - 10;
    }

    //checking cents are greater than 5 cents
    while (cents >= 5)
    {
        count ++;
        cents = cents - 5;
    }

    //checking cents are greater than 1 cents
    while (cents >= 1)
    {
        count ++;
        cents = cents - 1;
    }

    return count;
}