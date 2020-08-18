#include<stdio.h>
#include<cs50.h>

//function for printing pyramids
void print_pyramid(int n);

int main(void)
{
    //declaring variable h-height
    int h;
    do
    {
        h = get_int("Height:");
    }
    while (h < 1 || h > 8);

    //printing the pyramid by calling the function
    print_pyramid(h);
}
void print_pyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        //for loop to print first half of pyramid
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        // For loop to print out second half of pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}