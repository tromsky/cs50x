#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // prompt the user for two words
    string first_word = get_string("Player 1: ");
    string second_word = get_string("Player 2: ");

    // computer scores
    int first_word_score = compute_score(first_word);
    int second_word_score = compute_score(second_word);

    // determine winnder
    if (first_word_score > second_word_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (second_word_score > first_word_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int total_score = 0;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
        {
            char letter = toupper(word[i]);
            int position = letter - 65;
            int score = SCORES[position];
            total_score += score;
        }
    }
    return total_score;
}
