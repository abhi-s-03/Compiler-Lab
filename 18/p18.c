#include <stdio.h>
#include <string.h>

void process_operator(char *inp, char operator, char * reg)
{
    int i = 0, j = 0;
    char temp[100];

    while (inp[i] != '\0')
    {
        if (inp[i] == operator)
        {
            printf("%c\t%c\t%c\t%c\n", operator, temp[j - 1], inp[i + 1], *reg);
            temp[j - 1] = *reg;
            i += 2;
            (*reg)--;
        }
        else
            temp[j++] = inp[i++];
    }
    temp[j] = '\0';
    strcpy(inp, temp);
}

int main()
{
    char inp[100], reg = 'Z', opr[] = {'/', '*', '+', '-', '='};
    printf("Enter expression: ");
    scanf("%s", inp);

    printf("Opr\tArg1\tArg2\tResult\n");
    for (int i = 0; i < 5; i++)
        process_operator(inp, opr[i], &reg);
    return 0;
}