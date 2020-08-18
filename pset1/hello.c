#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //input your_name
    string your_name = get_string("What is your name?\n");
    printf("Hello, %s!\n", your_name);

}