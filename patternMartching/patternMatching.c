#include <stdio.h>
#include <string.h>

void clrscr(void) { printf("\033[1J\033[H"); } // use clearing the screen

int main()
{

    clrscr(); // use for clearing the screen
    char text[30];
    char pattern[10];
    int i, j;

    printf("Enter the text: ");
    fflush(stdout);                     // Use for flushing the output out
    scanf("%[^\n]s", text);
    fflush(stdin);                      // Use flusing the next line character from the input buffer

    printf("Enter the pattern: ");
    fflush(stdout);                     // Use for flushing the output out  
    scanf("%[^\n]s", pattern);
    fflush(stdin);                      // Use flusing the next line character from the input buffer

    unsigned int tlen = strlen(text);    // Taking the lenght of the input text character only not the size the array
    unsigned int plen = strlen(pattern);  

    for (i = 0; i <= (tlen - plen); i++)         // to make the algorithm 0(nm), we subtract the pattern lenght from the the text lenght
    {                                            // This does not affect it since we are only looking for the starting point of the match
        for (j = 0; (j < plen) && (pattern[j] == text[i + j]); j++)
        {
        }

        if (j == plen)
        {
            printf("There is a match starting at position %d", i);
            return 1;
        }
    }

    printf("There is no match!! ");
    // printf("%d", strlen(text));
}