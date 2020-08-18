#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //finding average
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            //then assigning average
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculating the values of sepia red,blue and green
            int sepR = round((0.393 * (image[i][j].rgbtRed)) + (0.769 * (image[i][j].rgbtGreen)) + (0.189 * (image[i][j].rgbtBlue)));
            int sepG = round((0.349 * (image[i][j].rgbtRed)) + (0.686 * (image[i][j].rgbtGreen)) + (0.168 * (image[i][j].rgbtBlue)));
            int sepB = round((0.272 * (image[i][j].rgbtRed)) + (0.534 * (image[i][j].rgbtGreen)) + (0.131 * (image[i][j].rgbtBlue)));

            // Checking conditions
            if (sepR > 255)
            {
                sepR = 255;
                image[i][j].rgbtRed = sepR;
            }
            if (sepG > 255)
            {
                sepG = 255;
                image[i][j].rgbtGreen = sepG;
            }
            if (sepB > 255)
            {
                sepB = 255;
                image[i][j].rgbtBlue = sepB;
            }
            //setting sepia colours
            image[i][j].rgbtRed = sepR;
            image[i][j].rgbtGreen = sepG;
            image[i][j].rgbtBlue = sepB;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        //determining halfwidth
        int new_width = round((float)1 / 2 * width);
        for (int j = 0; j < width; j++)
        {

            while (j < new_width)
            {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][width - 1 - j];
                image[i][width - 1 - j] = temp;
                break;
            }

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
    return;
}
