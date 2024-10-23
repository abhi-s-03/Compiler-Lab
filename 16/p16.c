#include <stdio.h>
#include <string.h>

int i = 0, j = 0, length = 0;
char inputstr[16], stack[15];

void check()
{
    for (int k = 0; k < length; k++)
    {
        if (stack[k] == 'i' && stack[k + 1] == 'd')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stack, inputstr, "REDUCE TO E");
            j++;
        }
    }

    for (int k = 0; k < length; k++)
    {
        if (stack[k] == 'E' && stack[k + 1] == '+' && stack[k + 2] == 'E')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, inputstr, "REDUCE TO E");
            i = i - 2;
        }
    }

    for (int k = 0; k < length; k++)
    {
        if (stack[k] == 'E' && stack[k + 1] == '*' && stack[k + 2] == 'E')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, inputstr, "REDUCE TO E");
            i = i - 2;
        }
    }

    for (int k = 0; k < length; k++)
    {
        if (stack[k] == '(' && stack[k + 1] == 'E' && stack[k + 2] == ')')
        {
            stack[k] = 'E';
            stack[k + 1] = '\0';
            stack[k + 2] = '\0';
            printf("\n$%s\t%s$\t%s", stack, inputstr, "REDUCE TO E");
            i = i - 2;
        }
    }
}

int main()
{
    printf("GRAMMAR\nE->E+E \nE->E*E \nE->(E) \nE->id\n");
    printf("Enter input string:");
    scanf("%s", inputstr);
    length = strlen(inputstr);
    printf("\nstack \t Input \t\t Action");
    printf("\n$\t%s$\t", inputstr);

    for (i = 0; j < length; i++, j++)
    {
        if (inputstr[j] == 'i' && inputstr[j + 1] == 'd')
        {
            stack[i] = inputstr[j];
            stack[i + 1] = inputstr[j + 1];
            stack[i + 2] = '\0';
            inputstr[j] = ' ';
            inputstr[j + 1] = ' ';
            printf("\n$%s\t%s$\t%sid", stack, inputstr, "SHIFT ->");
            check();
        }
        else
        {
            stack[i] = inputstr[j];
            stack[i + 1] = '\0';
            inputstr[j] = ' ';
            printf("\n$%s\t%s$\t%s symbols", stack, inputstr, "SHIFT ->");
            check();
        }
    }
    printf("\n");
}