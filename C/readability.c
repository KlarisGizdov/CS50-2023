#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    //Prompt user for input
    string text = get_string("Text :");

    //Calculate words, letters, sentences
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        //Alphabetical
        if (isalpha(text[i]))
        {
            letters++;
        }

        //Spaces
        else if (text[i] == ' ')
        {
            words++;
        }

        //End of sentence mark counts as 1 sentence
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    //Calculate greade level
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", index);
    }
    printf("\n");
}
