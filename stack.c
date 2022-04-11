// Online C compiler to run C program online
#include <stdio.h>

struct stack {
 int arr[5];
 int tos ;

};
 void push(struct stack* , int);
 int pop(struct stack*);

int main()
{
   struct stack S;
   int i,x;
   S.tos = -1;

  /* for( i=1;i<=6;i++)
   {
       printf("\n Enter Element :");
       scanf("%d",&x);
       push(&S, x);

   }*/
   for( i=1;i<=6;i++)
   {
       x=pop(&S);
       printf("popped %d successfully ",x );

   }
    return 0;
}


void push (struct stack* ptr, int z)
{
    if(ptr->tos ==4)
    {
        printf("Stack overflow");
        return;
    }
    ptr->tos = ptr->tos+1;
    ptr->arr[ptr->tos] = z;
    printf("pushed successfully %d",z);
}



int pop(struct stack* ptr)
{
    int x;
   if(ptr->tos == -1)
   {
       printf("\nStack underflow\n");
       return;
   }
   x=ptr->arr[ptr->tos];
   printf("\npopped successfully %d", x);
   ptr->tos = ptr->tos-1;




}
