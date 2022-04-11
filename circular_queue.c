#include<stdio.h>
#include<stdlib.h>
struct Cqueue{
int arr[10];
int rear;
int front;
};

void insert(struct Cqueue *p,int x){
   if((p->rear==9 && p->front==0) || (p->rear+1==p->front))
   {
       printf("Circular queue overflow ");
       return;
   }

   if(p->rear==9)
   {
       p->rear=0;
   }
   p->rear++;
   p->arr[p->rear]=x;

   if(p->front==-1)
   {
       p->front=0;
   }

}
int del(struct Cqueue *p)
{
    int x;
if(p->front==-1)
{
    printf("Circular queue underflow ");
    return -1;
}
x = p->arr[p->front];
if(p->front == p->rear)
{
   p->rear = p->front = -1;
}
else if (p->front==9)
    p->front=0;
else
   p->front++;


return x;
}

int main(){
    struct Cqueue Q;
    Q.rear=-1;
    Q.front=-1;
    int choice,x;
    do{
    printf(" \n 1.Insert \n 2.Delete \n 3.Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice){

            case 1:
                printf("\nEnter a no. ");
                scanf("%d",&x);
                insert(&Q,x);
                printf("\n %d Inserted Successfully ",x);
                break;
            case 2:

                x=del(&Q);
                if(x!=-1){
                    printf("\nDeleted element is %d",x);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice ");

    }
    }
    while(1);

    return 0;



}
