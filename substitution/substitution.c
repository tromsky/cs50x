#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int VALID_KEY_VALUE = 2015;

int main(int argc, string argv[])
{
    // get command-line arg
    // validate that a key was passed in
    if (argc != 2)
    {
        printf("Usage: ./substitution <key>\n");
        printf("Example: ./substitution NQXPOMAFTRHLZGECYJIUWSKDVB\n");
        return 1;
    }

    string key = argv[1];
    // validate a 26-character key
    if (strlen(key) != 26)
    {
        printf("Key must be 26 characters long\n");
        return 1;
    }

    // check if the key contains invalid characters or duplicate characters
    for (int i = 0, keylen = strlen(key); i < keylen; i++)
    {
        char character = key[i];

        for (int j = i + 1; j < keylen; j++)
        {
            if (toupper(character) == toupper(key[j]))
            {
                printf("Key contains duplicates\n");
                return 1;
            }
        }

        if (toupper(character) < 'A' || toupper(character) > 'Z')
        {
            printf("Key contains invalid characters\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");

    char ciphertext[strlen(plaintext) + 1];

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char character = plaintext[i];
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
        {
            int delta = toupper(character) - 'A';
            if (isupper(character))
            {
                ciphertext[i] = toupper(key[delta]);
            }
            else
            {
                ciphertext[i] = tolower(key[delta]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
