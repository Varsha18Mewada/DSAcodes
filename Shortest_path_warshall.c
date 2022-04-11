#include<stdio.h>
#include<conio.h>

void shortest(int [][4],int[][4]);
int min(int,int);

int main()
{

    int adj[4][4],sp[4][4];
    int i,j;
        for(i=0;i<4;i++)
    {
       for(j=0;j<4;j++)
    {
        printf("Is there any path b/w v[%d] to v[%d] (Y-Weight,N-0)\n",i+1,j+1);
        scanf("%d",&adj[i][j]);

    }

    }

    shortest_path(adj,sp);
    printf("Following is the shortest path matrix : \n");

     for(i=0;i<4;i++)
    {
       for(j=0;j<4;j++)
    {
        printf("  %d  ",sp[i][j]);

    }
      printf("\n");
    }
    return 0;
}

void shortest_path(int adj[4][4],int sp[4][4])
{

     int infi=505050;
     int i,j,k;
     for(i=0;i<4;i++)
    {
       for(j=0;j<4;j++)
    {
        (adj[i][j]==0)?(sp[i][j]=infi) : (sp[i][j]=adj[i][j]);

    }

    }


for(k=0;k<4;k++)
{
    for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
        //sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
        if(sp[i][j]>sp[i][k]+sp[k][j])
        {
         sp[i][j]= sp[i][k]+sp[k][j];
        }
          }

        }

}
}

int min(int a,int b)
{
   return (a<b?a:b);

}
