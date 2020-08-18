#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//Declaring function grade,count_letters,count_words and count_sentences
void print_grade(string prompt);
int count_letters(string s1);
int count_words(string s2);
int count_sentences(string s3);

int main(void)
{
    string s = get_string("Text: ");
    print_grade(s);
}

//defining function print_grade
void print_grade(string prompt)
{
    // Calling all count functions
    int lc = count_letters(prompt);
    int wc = count_words(prompt);
    int sc = count_sentences(prompt);

    float l = 100 * ((float)lc / (float)wc);
    float s = 100 * ((float)sc / (float)wc);
    //calculating using Coleman-Liau formula
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    //checking of index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf(" Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}
//defining function count_letters
int count_letters(string s1)
{
    //declaring count for letters
    int c1 = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (isalpha(s1[i]))
        {
            c1++;
        }
    }
    return c1;
}
//defining function count_words
int count_words(string s2)
{
    //declaring count for words
    int c2 = 0;
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] == ' ')
        {
            c2++;
        }
    }
    return c2 + 1;
}
//defining function count_sentences
int count_sentences(string s3)
{
    //declaring count for sentences
    int c3 = 0;
    for (int i = 0; s3[i] != '\0'; i++)
    {
        if (s3[i] == '.' || s3[i] == '!' || s3[i] == '?')
        {
            c3++;
        }
    }
    return c3;
}