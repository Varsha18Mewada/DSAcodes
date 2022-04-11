#include<stdio.h>

int main()
{
    int adj[4][4];
    int i,j;
    for(i=0;i<4;i++)
    {
         for(j=0;j<4;j++)
    {
        printf("Is there any path from V[%d] to V[%d] ? (Yes-1,No-0 ) \n",i+1,j+1);
        scanf("%d",&adj[i][j]);

    }
    }

    printf("Adjacency matrix of the Graph is : \n");
     for(i=0;i<4;i++)
    {
         for(j=0;j<4;j++)
    {
        printf(" %d  ",adj[i][j]);


    }
    printf("\n");
    }

    return 0;
}
