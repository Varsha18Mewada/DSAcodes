#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct soldier {
char name[10];
struct soldier *next;
};
void append(struct soldier **,char[]);
void display(struct soldier *);
void josepheous(struct soldier **,int);
int main(){
    int n,x,i;
    printf("Enter the no. of soldier : ");
    scanf("%d",&n);
    struct soldier sold[n];
    struct soldier *start=NULL;


    for(i=1; i<=n; i++)
        {
        printf("Enter  The Name of Soldier : ");
        scanf("%s",sold[i].name);
        }
    for(i=1; i<=n; i++)
        {
            append(&start,sold[i].name);
        }
         printf("Enter the random no. : ");
    scanf("%d",&x);

josepheous(&start,x);
// display(start);
return 0;
}


void append(struct soldier **ps,char n1[]){
    struct soldier *p,*temp;
    p=(struct soldier *)malloc(sizeof(struct soldier));
    if(p==NULL){
        printf("\nInsufficient memory");
        return;
    }
    strcpy(p->name,n1);
    if(*ps==NULL){
        *ps=p;
        p->next=p;

        return;
    }
    temp=*ps;
    while(temp->next!=*ps){
        temp=temp->next;
    }
    temp->next=p;
    p->next=*ps;
}
void josepheous(struct soldier **ps,int x)
{
    struct soldier *prev, *temp;
    prev=temp=*ps;
    while(temp->next!=*ps){
        for(int i=1; i<x; i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        printf("%s has been Killed \n",temp->name);
        free(temp);
        temp=prev->next;

    }
    (*ps)=temp;
    printf("%s is winner \n",(*ps)->name);
    return;

}
void display(struct soldier *head)
{
    struct soldier *temp;

    temp = head;
    printf("%s   ", temp->name);
    temp = temp->next;
    while (head != temp)
    {
        printf("%s   ", temp->name);
        temp = temp->next;
    }
    printf("\n");
}
