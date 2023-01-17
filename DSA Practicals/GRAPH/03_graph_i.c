#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define INF 9999999
#define V 5
int G[V][V] = {
    {0, 7, 75, 0, 0},
    {7, 0, 95, 15, 42},
    {75, 95, 0, 29, 66},
    {0, 15, 29, 0, 24},
    {0, 42, 66, 24, 0}};
int main()
{
    printf("\n\tName : Umang Dalvadi\n");
    printf("\tEnroll no. : 210210116020\n");
    int no_edge;
    int selected[V];
    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    int x;
    int y;
    printf("Edge : Weight\n");
    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }
    return 0;
}
