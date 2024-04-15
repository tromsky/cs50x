#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letter_count = 0;
    int word_count = 1;
    int sentence_count = 0;

    // could do each of these in their own function
    // but that would require looping through the text multiple times
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letter_count++;
        }
        else if (text[i] == ' ')
        {
            word_count++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count++;
        }
    }

    // Compute the Coleman-Liau index
    // index = 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text
    //     the number of letters divided by the number of words, all multiplied by 100
    // S is the average number of sentences per 100 words in the text
    //     the number of sentences divided by the number of words, all multiplied by 100

    float average_letters = (float)letter_count / (float)word_count * 100.00;
    float average_sentences = (float)sentence_count / (float)word_count * 100.00;
    float index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;

    // Print the grade level
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
