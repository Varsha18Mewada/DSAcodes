#include<stdio.h>
#include<stdlib.h>
struct queue{
int arr[10];
int rear;
int front;
};
void insert(struct queue *p,int x){
    if(p->rear==9){
            printf("Queue Overflow");
            return;

    }
    else{
        p->rear++;
        p->arr[p->rear]=x;

    }

}
int del(struct queue *p){
    int x;
if(p->front>p->rear){
    printf("Queue Underflow");
    return -1;
}

x=p->arr[p->front];
p->front++;
return x;



}
int main(){
    struct queue Q;
    Q.rear=-1;
    Q.front=0;
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
