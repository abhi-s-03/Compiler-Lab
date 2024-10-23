#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

char InputSymbols[15], InputPointer = 0, Output[50], Temp[50];

void E_Prime();
void E();
void T_Prime();
void T();
void F();

void E()
{
    strcpy(Output, "TE'");
    printf("E=%-25sE -> TE'\n", Output);
    T();
    E_Prime();
}

void E_Prime()
{
    int i, tempIndex = 0, length;
    for (i = 0; i <= strlen(Output); i++)
        if (Output[i] != 'e')
            Temp[tempIndex++] = Output[i];
    strcpy(Output, Temp);
    length = strlen(Output);
    for (tempIndex = 0; tempIndex < length && Output[tempIndex] != 'E'; tempIndex++)
        ;

    if (InputSymbols[InputPointer] == '+')
    {
        i = tempIndex + 2;
        do
        {
            Output[i + 2] = Output[i];
            i++;
        } while (i <= length);

        Output[tempIndex++] = '+';
        Output[tempIndex++] = 'T';
        Output[tempIndex++] = 'E';
        Output[tempIndex++] = 39;
        printf("E=%-25s", Output);
        printf("E' -> +TE'\n");
        InputPointer++;
        T();
        E_Prime();
    }
    else
    {
        Output[tempIndex] = 'e';
        for (i = tempIndex + 1; i <= strlen(Output); i++)
            Output[i] = Output[i + 1];
        printf("E=%-25s", Output);
        printf("E' -> e");
    }
}

void T()
{
    int i, tempIndex = 0, length;
    for (i = 0; i <= strlen(Output); i++)
        if (Output[i] != 'e')
            Temp[tempIndex++] = Output[i];
    strcpy(Output, Temp);

    length = strlen(Output);
    for (tempIndex = 0; tempIndex < length && Output[tempIndex] != 'T'; tempIndex++)
        ;

    i = tempIndex + 1;
    do
    {
        Output[i + 2] = Output[i];
        i++;
    } while (i < length);

    Output[tempIndex++] = 'F';
    Output[tempIndex++] = 'T';
    Output[tempIndex++] = 39;
    printf("E=%-25s T -> FT'\n", Output);
    F();
    T_Prime();
}

void T_Prime()
{
    int i, tempIndex = 0, length;
    for (i = 0; i <= strlen(Output); i++)
        if (Output[i] != 'e')
            Temp[tempIndex++] = Output[i];
    strcpy(Output, Temp);
    length = strlen(Output);

    for (tempIndex = 0; tempIndex < length && Output[tempIndex] != 'T'; tempIndex++)
        ;

    if (InputSymbols[InputPointer] == '*')
    {
        i = tempIndex + 2;
        do
        {
            Output[i + 2] = Output[i];
            i++;
        } while (i < length);

        Output[tempIndex++] = '*';
        Output[tempIndex++] = 'F';
        Output[tempIndex++] = 'T';
        Output[tempIndex++] = 39;
        printf("E=%-25s", Output);
        printf("T' -> *FT'\n");
        InputPointer++;
        F();
        T_Prime();
    }
    else
    {
        Output[tempIndex] = 'e';
        for (i = tempIndex + 1; i <= strlen(Output); i++)
            Output[i] = Output[i + 1];
        printf("E=%-25s", Output);
        printf("T' -> e\n");
    }
}

void F()
{
    int i, tempIndex = 0, length;
    for (i = 0; i <= strlen(Output); i++)
        if (Output[i] != 'e')
            Temp[tempIndex++] = Output[i];
    strcpy(Output, Temp);

    length = strlen(Output);
    for (tempIndex = 0; tempIndex < length && Output[tempIndex] != 'F'; tempIndex++)
        ;

    if (InputSymbols[InputPointer] == 'i' || InputSymbols[InputPointer] == 'I')
    {
        Output[tempIndex] = 'i';
        printf("E=%-25s", Output);
        printf("F -> i\n");
        InputPointer++;
    }
    else
    {
        if (InputSymbols[InputPointer] == '(')
        {
            InputPointer++;
            E();
            if (InputSymbols[InputPointer] == ')')
            {
                InputPointer++;
                i = tempIndex + 2;
                do
                {
                    Output[i + 2] = Output[i];
                    i++;
                } while (i <= length);
                Output[tempIndex++] = '(';
                Output[tempIndex++] = 'E';
                Output[tempIndex++] = ')';
                printf("E=%-25s", Output);
                printf("F -> (E)\n");
            }
        }
        else
        {
            printf("\n\t Syntax error");
            exit(1);
        }
    }
}

void main()
{
    printf("Grammar:");
    printf("\nE -> TE' \nE' -> +TE' | e \nT -> FT' \nT' -> *FT' | e \nF -> (E) | i");
    printf("\nEnter the input expression: ");
    scanf("%s", InputSymbols);
    printf("Expressions");
    printf("\tSequence of production rules\n");
    E();
    for (int i = 0; i < strlen(InputSymbols); i++)
    {
        if (InputSymbols[i] != '+' && InputSymbols[i] != '*' && InputSymbols[i] != '(' && InputSymbols[i] != ')' && InputSymbols[i] != 'i' && InputSymbols[i] != 'I')
        {
            printf("\nSyntax error");
            break;
        }
        int tempIndex = 0;
        for (i = 0; i <= strlen(Output); i++)
            if (Output[i] != 'e')
                Temp[tempIndex++] = Output[i];
        strcpy(Output, Temp);
        printf("\nE=%-25s", Output);
    }
}