#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int graph[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void dfs(int i)
{
    int j;
    visited[i] = 1;
    printf("visit : %d\n", i);

    for (j = 0; j < 7; j++)
    {
        if (graph[i][j] == 1 && !visited[j])
        {
            dfs(j);
        }
    }
}
int main()
{
    dfs(0);

    return 0;
}