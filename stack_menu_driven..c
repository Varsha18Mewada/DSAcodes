#include <stdio.h>
#include<stdlib.h>


    struct stack {
    int arr[5];
    int tos;
};

void push(struct stack*,int);
int pop(struct stack*);

int main(){
    struct stack s;
	s.tos=-1;
    int x,C;

do{
    printf("\nselect the operation");
    printf("\n1. PUSH");
    printf("\n2. POP");
    printf("\n3. QUIT");


 printf("\n Enter your choice:");
 int ch;
 scanf("%d",&ch);

 switch(ch){
     case 1:

            printf("\nEnter an element which you want to push : ");
            scanf("%d",&x);
            push(&s,x);
            break;



     case 2:
            pop(&s);
            break;



    case 3:
        exit(0);


    default:
        printf("Enter valid operation ");


 }

printf("\nDo you want to continue (1/0)  : ");
scanf("%d",&C);

}
while(C==1);

return 0;
}

void push(struct stack*p,int x){
    if(p->tos==4){
        printf("\nStack overflow ");
        return ;
    }
    else{
        p->tos=p->tos+1;
        p->arr[p->tos]=x;
        printf("\n %d Pushed successfully ",x);

    }

}

int pop(struct stack *p){
    if(p->tos==-1){
        printf("\nStack underflow ");
        return 0;
    }
    else{
        int popped=p->arr[p->tos];
         printf("\nPopped element is %d ",popped);
         p->tos=p->tos-1;

    }
}

