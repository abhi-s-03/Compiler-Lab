#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 10
#define MAX_CHARS 10

int n, count = 0;
char productions[MAX_PRODUCTIONS][MAX_CHARS], set[MAX_CHARS];

void addtoset(char c)
{
    for (int i = 0; i < count; i++)
        if (set[i] == c)
            return;
    set[count++] = c;
}

int first(char c, int cond)
{
    if (islower(c))
    {
        addtoset(c);
        return 0;
    }
    int epsilon = 0, epsilonFound = 0;
    for (int i = 0; i < n; i++)
    {
        if (productions[i][0] == c)
        {
            if (productions[i][2] == 'e')
            {
                if (cond)
                {
                    epsilon = 1;
                    continue;
                }
                addtoset(productions[i][2]);
            }
            else if (!isupper(productions[i][2]))
                addtoset(productions[i][2]);
            else
            {
                for (int j = 2; j < strlen(productions[i]); j++)
                {
                    epsilonFound = first(productions[i][j], 1);
                    if (!epsilonFound)
                        break;
                }
                if (epsilonFound && cond == 0)
                    addtoset('e');
            }
        }
    }
    return epsilon || epsilonFound;
}

void follow(char c)
{
    if (productions[0][0] == c)
        addtoset('$');

    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(productions[i]); j++)
        {
            if (productions[i][j] == c)
            {
                if (productions[i][j + 1] != '\0')
                {
                    if (!isupper(productions[i][j + 1]))
                        addtoset(productions[i][j + 1]);
                    else
                    {
                        int epsilonFound = 0, k;
                        for (k = j + 1; k < strlen(productions[i]); k++)
                        {
                            epsilonFound = first(productions[i][k], 1);
                            if (!epsilonFound)
                                break;
                        }
                        if (k == strlen(productions[i]) && epsilonFound)
                            follow(productions[i][0]);
                    }
                }
                else if (productions[i][0] != c)
                    follow(productions[i][0]);
            }
        }
    }
}

int main()
{
    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (use e for epsilon):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", productions[i]);

    char c;
    do
    {
        printf("\nEnter the symbol to find First and Follow: ");
        scanf(" %c", &c);

        count = 0;
        memset(set, 0, sizeof(set));
        first(c, 0);
        printf("First(%c) = { ", c);
        for (int i = 0; i < strlen(set); i++)
            printf("%c ", set[i]);
        printf("}\n");

        count = 0;
        memset(set, 0, sizeof(set));
        follow(c);
        printf("Follow(%c) = { ", c);
        for (int i = 0; i < strlen(set); i++)
            printf("%c ", set[i]);
        printf("}\n");

        printf("Continue? (y/n): ");
        scanf(" %c", &c);
    } while (c == 'y' || c == 'Y');

    return 0;
}