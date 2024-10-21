#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct expr
{
    char op[2], arg1[5], arg2[5], res[5];
    int flag;
} arr[10];

void main()
{
    int n, arg1, arg2, res,f=0;
    char op, res1[5];

    printf("Enter the maximum number of expressions : ");
    scanf("%d", &n);
    printf("\nEnter the input (Op arg1 arg2 result):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s %s", arr[i].op, arr[i].arg1, arr[i].arg2, arr[i].res);
        arr[i].flag = 0;
    }

    char result[5];
    strcpy(result, arr[n - 1].res);
    for (int i = 0; i < n; i++)
    {
        if (isdigit(arr[i].arg1[0]) && isdigit(arr[i].arg2[0]) || strcmp(arr[i].op, "=") == 0)
        {
            arg1 = atoi(arr[i].arg1);
            arg2 = atoi(arr[i].arg2);
            op = arr[i].op[0];
            switch (op)
            {
            case '+':
                res = arg1 + arg2;
                break;
            case '-':
                res = arg1 - arg2;
                break;
            case '*':
                res = arg1 * arg2;
                break;
            case '/':
                res = arg1 / arg2;
                break;
            case '=':
                res = arg1;
                break;
            }
            sprintf(res1, "%d", res);
            arr[i].flag = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (strcmp(arr[i].res, arr[j].arg1) == 0)
                    strcpy(arr[j].arg1, res1);
                else if (strcmp(arr[i].res, arr[j].arg2) == 0)
                    strcpy(arr[j].arg2, res1);
            }
        }
    }

    printf("\nCode after constant propagation:\n");
    for (int i = 0; i < n; i++)
    {
        if (!arr[i].flag){
            f=1;
            printf("%s %s %s %s\n", arr[i].op, arr[i].arg1, arr[i].arg2, arr[i].res);
        }
    }
    if(f==0)
        printf("%s = %s\n", result, res1);
}