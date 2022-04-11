#include<stdio.h>
#include<stdlib.h>
struct edge{
    char data;
    struct edge *next;
};
struct node{
    char data;
    struct node *next;
    struct edge *enext;
};
void addvertex(struct node **,char);
void insertedge(struct node*,char,char);
void display(struct node *);
struct node* findvertex(struct node*,char);
int main()
{
    struct node *start=NULL;
    int choice;
    char ch1,ch2;
    do{
        printf("\n 1. Add Vertex");
        printf("\n 2. Insert Edge");
        printf("\n 3. Display");
        printf("\n4. Quit");

        printf("\n Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter node data:");
           fflush(stdin);
            scanf("%c",&ch1);
            addvertex(&start,ch1);
            break;
        case 2:
            printf("\n Enter source and target vertex : \n");
            fflush(stdin);
            scanf("%c %c",&ch1,&ch2);
            insertedge(start,ch1,ch2);
            break;
        case 3:
            display(start);
            break;
        case  4:
            exit(0);
            break;
        default:
            printf("\n Wrong choice ! Try Again");
        }

    }
    while(choice !=5);
    return 0;
}


void addvertex(struct node **pr,char c)
{
    struct node *p,*temp;
    p=(struct node*) malloc(sizeof(struct node));
    p->data=c;
    p->next=NULL;
    p->enext=NULL;

    if(*pr==NULL)
    {

        *pr=p;
        printf("\n Node added successfully");
        return;

    }
    temp=*pr;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=p;

printf("\n Node added successfully");
}
struct node*findvertex(struct node *p,char c1)
{
    while(p!=NULL)
    {
        if(p->data==c1)
            return p;
        p=p->next;
    }
    return NULL;
}

void insertedge(struct node *p,char src,char dest)
{
    struct node *q;
    struct edge *r,*t;
    if(p==NULL)
    {
        printf("Empty Graph");
        return;
    }
    q=findvertex(p,src);
    if(q==NULL)
    {
        printf("Source vertex not Found !");
        return;
    }
    if(findvertex(p,dest)==NULL)
    {
        printf("Target vertex not Found !");
        return;
    }
    r=(struct edge*)malloc(sizeof(struct edge));
    r->data=dest;
    r->next=NULL;
    if(q->enext==NULL)
    {
        q->enext=r;
        return;
    }
    t=q->enext;
    while(t->next!=NULL)
    {

        t=t->next;
    }
    t->next=r;
    printf("Edge between %c and %c added successfully!",src,dest);
}
void display(struct node *p)
{

    struct edge *temp;
    if(p==NULL)
    {
        printf("Graph is Empty");
        return;
    }
    while(p!=NULL)
    {
        printf("\n %c:",p->data);
        temp=p->enext;
        while(temp!=NULL)
        {
            printf("%c,",temp->data);
            temp=temp->next;
        }
        if(p->enext!=NULL)
            printf("\b ");
       p=p->next;

    }
}
