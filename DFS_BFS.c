#include<stdio.h>
#include<conio.h>
struct stack {
    int arr[4];
    int tos;
};
void push(struct stack *,int);
int pop(struct stack *);
void dfs(int [][4],int);
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
    dfs(adj,v);
    return 0;

}
void push(struct stack *p,int x)
{

    p->tos++;
    p->arr[p->tos]=x;
}
int pop(struct stack *p)
{
    int x=p->arr[p->tos];
    p->tos--;
    return x;

}
void dfs(int adj[][4],int v)
{
    struct stack s;
    s.tos=-1;
    int flag[4]={0,0,0,0};
    int i;
    push(&s,v);
    while(s.tos!=-1)
    {
        v=pop(&s);
        if(flag[v]==0)
        {
            printf("\n V[%d]",v);
            flag[v]=1;
        }
        for(i=3; i>=0; i--)
        {
            if(adj[v][i]==1 && flag[i]==0)
            {
                push(&s,i);
            }
        }
    }
}
