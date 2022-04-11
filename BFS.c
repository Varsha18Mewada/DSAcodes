#include<stdio.h>
#include<conio.h>
struct queue {
    int arr[4];
    int rear;
    int front;
};
void insert(struct queue*,int);
int del(struct queue *);
void bfs(int [][4],int);
int main()
{
    int adj[4][4];
    int i,j,v;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf(" is there  path between v[%d] to v[%d] YES-1,NO-0 \n",i+1,j+1);
            scanf("%d",&adj[i][j]);
        }

    }
    printf("Enter source vertex : ");
    scanf("%d",&v);
    bfs(adj,v);
    return 0;

}
void insert(struct queue *p,int x)
{
    p->rear++;
    p->arr[p->rear]=x;

}
int del(struct queue *p)
{
    int x=p->arr[p->front];
    p->front++;
    return x;

}

void bfs(int adj[][4],int v)
{
    struct queue q;
    q.rear=-1;
    q.front=-1;
    int flag[4]={0};
    int i;

     insert(&q,v);

     while(q.front==-1 !! q.front>q.rear)
     {
          v=del(&q);
          if(flag[v]==0)
          {
              printf("V[%d] ",v);
              flag[v]=1;
          }
          for(i=3; i>=0; i--)
          {

              if(adj[v][i]==1 && flag[i]==0)
              {
                  insert(&q,i);
              }
          }
     }


}
