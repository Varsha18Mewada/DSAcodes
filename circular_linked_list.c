#include<stdio.h>
#include<stdlib.h>
struct cnode{
int data ;
struct cnode *next;

};
void append (struct cnode **,int);
void display(struct cnode *);
void del_first(struct cnode **);
void del_last(struct cnode **);
void del_any(struct cnode **,int );
void insert(struct cnode **,int x);
int main()
{
    struct cnode *start=NULL;
    int choice ,x;
    do{
    printf(" \n 1. Append \n 2. Display \n 3.Del_first \n 4.Del_last \n 5.insert \n 6.Del_any \n 7.Exit \n");
    printf("\n Enter choice  : ");
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
void append(struct cnode **ps,int x)
{
     struct cnode *p,*temp;
     p=(struct cnode*)malloc(sizeof(struct cnode));
     if(p==NULL)
     {
         printf("Insufficient memory ");
         return;
     }
     p->data=x;
     if(*ps==NULL)
     {
         *ps=p;
         p->next=p;
         printf("Node added successfully ");
         return;
     }
    temp = *ps;
    while(temp->next != *ps)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->next=*ps;
    printf("Node added successfully ");
}
void display(struct cnode *p)
{
    struct cnode *temp;
    if(p==NULL)
    {
        printf("List is empty ");
        return;
    }
    temp=p;
    do
    {
      printf("\n %d",temp->data) ;
      temp=temp->next;
    }while(temp != p);

}

void del_first(struct cnode **ps)
{
    struct cnode *temp;
    if(*ps==NULL)
    {
        printf("List is Empty");
        return;
    }
    if((*ps)->next==*ps)
    {
        free(*ps);
       *ps=NULL;
        printf("Node Deleted successfully ");
       return;
    }
    temp=*ps;
    while(temp->next != (*ps))
    {
        temp=temp->next;
    }

    temp->next=(*ps)->next;
    free(*ps);
    *ps=temp->next;
     printf("Node Deleted successfully ");

}
void del_last(struct cnode **ps)
{
    struct cnode *temp,*prev;
    if(*ps==NULL)
    {
        printf("List is Empty");
        return;
    }
    if((*ps)->next==*ps)
    {
        free(*ps);
       *ps=NULL;
        printf("Node Deleted successfully ");
       return;
    }
temp = *ps;
while(temp->next != (*ps))
{
    prev=temp;
    temp=temp->next;
}
free(temp);
prev->next=*ps;


}



void insert(struct cnode **ps,int x)
{
    struct cnode *p,*temp,*prev;
    p=(struct cnode*)malloc(sizeof(struct cnode));
    if(p==NULL)
    {
        printf("Insufficient memory ");
        return;
    }
    p->data=x;
    if(*ps==NULL)
    {
        *ps=p;
        p->next=*ps;
        printf("Node added successfully ");
        return;
    }
    if(x<(*ps)->data)
    {
        (*ps)->next = p;
        p->next=*ps;
        *ps = p;
         printf("Node added successfully ");
         return;
    }
     temp = *ps;
     while((temp->next != *ps) && (x>temp->data))
     {
         prev = temp;
         temp = temp->next;
     }

     if(temp->next == *ps)
     {
         temp->next=p;
         p->next=*ps;
          printf("Node added successfully ");
     }
     else{
        prev->next=p;
        p->next=temp;
         printf("Node added successfully ");
     }
}

void del_any(struct cnode **ps, int x)
{
    struct cnode *temp,*prev;
    if(*ps==NULL){
        printf("List is empty");
        return;
    }
    temp=*ps;
    if((*ps)->data==x){
        if((*ps)->next==(*ps)){
            free(temp);
            printf("Node deleted successfully");
            *ps=NULL;
            return;
        }
        else{
            while(temp->next!=(*ps)){
                temp=temp->next;
            }
            temp->next=(*ps)->next;
            free(*ps);
            *ps=temp->next;
            printf("Node deleted successfully");
            return;


        }
    }
    while(temp->next!=(*ps) && temp->data!=x){
        prev=temp;
        temp=temp->next;
    }
    if(temp->data==x){
        prev->next=temp->next;
        free(temp);
        printf("Node deleted successfully");
    }
    else{
        printf("Node not found");
    }
}
