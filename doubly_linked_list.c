#include<stdio.h>
#include<stdlib.h>
struct doubly{
int data ;
struct doubly *next,*prev;

};
void append (struct doubly **,int);
void display(struct doubly *);
void del_first(struct doubly **);
void del_last(struct doubly **);
void del_any(struct doubly **,int );
void insert(struct doubly **,int );
int main()
{
    struct doubly *start=NULL;
    int choice ,x;
    do{
    printf("\n  \n 1. Append \n 2. Display \n 3.Del_first \n 4.Del_last \n 5.insert \n 6.Del_any \n 7.Exit \n");
    printf("\n Enter choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:
         printf("Enter a Element ");
         scanf("%d",&x);
         append(&start,x);
         break;
     case 2:
        display(start);
        break;
      case 3:
        del_first(&start);
        break;
      case 4:
        del_last(&start);
        break;
      case 5:
         printf("Enter a Element ");
         scanf("%d",&x);
        insert(&start,x);
        break;
      case 6:
         printf("Enter data to Delete ");
         scanf("%d",&x);
        del_any(&start,x);
        break;
     case 7:
        return 0;
        break;
     default:
        printf("Invalid choice ");
        break;


    }
    }
    while(choice != 7);
    return 0;
}
void append(struct doubly **ps,int x)
{
    struct doubly *temp,*p;
    p=(struct doubly *)malloc(sizeof(struct doubly));
    if(p==NULL){
        printf("Insufficient memory");
        return;
    }
    p->data=x;
    p->next=NULL;
    if(*ps==NULL){
        *ps=p;
        p->prev=NULL;
        printf("Node Added successfully");
        return;

    }
    temp=*ps;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=p;
    p->prev=temp;
    printf("Node Added successfully");

}
void del_first(struct doubly**ps){
    struct doubly *temp;
if(*ps==NULL){
    printf("Doubly List is empty");
    return;
}
temp=*ps;
*ps=(*ps)->next;
free(temp);
(*ps)->prev=NULL;
printf(" First Node Deleted successfully");

   }
void display(struct doubly*p){
if(p==NULL){
    printf("List is empty");
    return;
       }
    while(p!=NULL){
        printf("\n %d",p->data);
        p=p->next;
    }

   }

   void del_last(struct doubly **ps){
       struct doubly *temp;
       if(*ps==NULL){
        printf("List is empty");
        return;
       }
       if((*ps)->next==NULL){
        free(*ps);
         printf("Last Node Deleted successfully");
        *ps=NULL;
        return;
       }
       temp=*ps;
       while(temp->next!=NULL){

        temp=temp->next;
       }
       free(temp);
       temp->prev->next=NULL;
       printf("Last Node Deleted successfully");
}
void del_any(struct doubly **ps,int x)
{
struct doubly *temp;
if(*ps==NULL)
    {
    printf("Doubly List is empty");
    return;
   }
temp=*ps;
if(temp->data==x)
{
    if((*ps)->next==NULL)
    {
        free(*ps);
        printf("%d deleted successfully",x);
        *ps=NULL;
        return;
    }
    else
    {
        *ps=(*ps)->next;
        (*ps)->prev=NULL;
        free(temp);
        printf("%d deleted successfully",x);
        return;
    }
}
    while(temp->next!=NULL)
    {
    if(temp->data==x)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        printf("%d  deleted successfully",x);
        return;
    }
    temp=temp->next;
    }
    if(temp->data==x)
    {
        temp->prev->next=NULL;
        free(temp);
        printf("%d deleted successfully",x);
        return;
    }

    else
    {
        printf("%d Not found",x);
    }
}
void insert(struct doubly **ps,int x)
{
struct doubly *temp, *p;
p=(struct doubly *)malloc(sizeof(struct doubly));
if(p==NULL)
    {
    printf("insufficient memory");
    return;
    }
p->data=x;
p->next=NULL;
if(*ps==NULL)
{
    *ps=p;
    p->prev=NULL;
    printf("Node Added successfully");
    return;
}
if(x<(*ps)->data)
{
    p->prev=NULL;
    p->next=*ps;
    (*ps)->prev=p;
    *ps=p;
    printf("Node Added successfully");
    return;
}
    temp=*ps;
    while(temp->next!=NULL && x>temp->next->data)
        {
        temp=temp->next;
        }
    if(temp->next==NULL)
    {
        temp->next=p;
        p->prev=temp;
        p->next=NULL;
        printf("Node Added successfully");
        return;
    }
    else
        {
                p->next=temp->next;
                p->prev=temp;
                temp->next->prev=p;
                temp->next=p;
                printf("Node Added successfully");
        }
}







