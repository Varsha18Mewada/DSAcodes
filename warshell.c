void warshell(int[][4],int[][4]);
#include<stdio.h>
int main()
{
    int adj[4][4],path[4][4];
    int i,j;
    for(i=0; i<4; i++)
    {

        for(j=0; j<4; j++)
        {

            printf("\n is there any direct path from v[%d] to v[%d] ? yes-1, no-0 \n ",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }

    }
    warshell(adj,path);
    printf("Path matrix is :");
     for(i=0; i<4; i++)
    {

        for(j=0; j<4; j++)
        {

           printf("%d",path[i][j]);
        }
        printf("\n");
    }
return 0;
}
void warshell(int adj[][4],int path[][4])
{
    int i,j,k;
      for(i=0; i<4; i++)
    {

        for(j=0; j<4; j++)
        {

            path[i][j]=adj[i][j];
        }
        printf("\n");
    }

    for(k=0; k<4; k++)
    {


        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                path[i][j]= path[i][j]|| (path[i][k]&& path[k][j]);
            }
        }
    }


}
