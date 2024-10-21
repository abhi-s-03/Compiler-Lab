#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
int visited[100];

void closure(int state, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        if (matrix[state][i] == 1 && !visited[i])
        {
            visited[i] = 1;
            printf("q%d ", i);
            closure(i, matrix);
        }
    }
}

int main()
{
    char input[3], state1[3], state2[3];
    int s1, s2;

    printf("Enter no of states: ");
    scanf("%d", &n);

    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 0; 
        }
    }

    int t;
    printf("Enter no of transitions: ");
    scanf("%d", &t);

    printf("Enter State1 input Symbol and State2 (for epsilon transitions, input 'e'):\n");
    for (int i = 0; i < t; i++)
    {
        scanf("%s %s %s", state1, input, state2);
        if (strcmp(input, "e") == 0)
        {
            s1 = state1[1] - '0';  
            s2 = state2[1] - '0';  
            mat[s1][s2] = 1;
        }
    }

    printf("Epsilon closure of\n");
    for (int k = 0; k < n; k++)
    {
        memset(visited, 0, sizeof(visited)); 
        printf("q%d: q%d ", k, k); 
        visited[k] = 1; 
        closure(k, mat);
        printf("\n");
    }
    return 0;
}
