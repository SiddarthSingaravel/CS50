#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Counts the number of arguements in the command line
    if (argc == 2)
    {
        //converts string to number
        const int KEY = atoi(argv[1]);

        bool isKeyValid = true;
        int len = strlen(argv[1]);

        //Loop to check number
        for (int i = 0; i < len; i++)
        {
            //checking isdigit
            if (!isdigit(argv[1][i]))
            {
                isKeyValid = false;
                i = len;
            }
        }
        // goes in if loop successful
        if (isKeyValid)
        {

            string plain = get_string("plaintext: ");
            int plainLength = strlen(plain);

            for (int i = 0; i < plainLength; i++)
            {
                if (isupper(plain[i]))
                {
                    if (plain[i] + KEY >  'Z')
                    {
                        int keyRemainder = (plain[i] + KEY) - 'Z';
                        if (keyRemainder > 'Z' - 'A')
                        {
                            while (keyRemainder >= ('Z' - 'A'))
                            {
                                keyRemainder = keyRemainder - ('Z' - 'A');
                            }
                            if (plain[i] + keyRemainder > 'Z')
                            {
                                keyRemainder = plain[i] + keyRemainder - 'Z';
                                plain[i] = 'A' + keyRemainder - 1;
                            }
                            else
                            {
                                plain[i] = 'a' + keyRemainder - 1;
                            }
                        }
                        else
                        {
                            plain[i] = 'A' + keyRemainder - 1;

                        }
                    }
                    else if (plain[i] + KEY <= 'Z')
                    {
                        plain[i] = plain[i] + KEY;
                    }
                }
                if (islower(plain[i]))
                {
                    if (plain[i] + KEY >  'z')
                    {
                        // Takes the value for rotation of the wheel
                        int keyRemainder = (plain[i] + KEY) - ('z');

                        if (keyRemainder >= 'z' - 'a')
                        {
                            // While the keyRemainder is greater than 25,
                            while (keyRemainder >= ('z' - 'a'))
                            {
                                // Each iteration subtracts 26
                                keyRemainder = keyRemainder - (26);
                            }

                            //checking greater than Z
                            if (plain[i] + keyRemainder > 'z')
                            {
                                keyRemainder = plain[i] + keyRemainder - 'z';
                                plain[i] = 'a' + keyRemainder - 1;
                            }
                            // If the keyRemainder + the initial letter value is not greater than 'z'
                            else
                            {
                                plain[i] = 'a' + keyRemainder - 1;
                            }
                        }
                        //else statement
                        else
                        {
                            plain[i] = 'a' + keyRemainder - 1;
                        }
                    }
                    else if (plain[i] + KEY <= 'z')
                    {
                        plain[i] = plain[i] + KEY;
                    }
                }
            }


            printf("ciphertext: %s\n", plain);
        }
        // for unusable
        else
        {
            printf("Usage: ./caesar key\n");
            printf("1");
            return (1);
        }

    }
    // If too many arguements were entered
    else if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        printf("1");
        return (1);
    }

}