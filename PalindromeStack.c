// Online C compiler to run C program online
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack
{
    char arr[10];
    int tos;
};
void push(struct stack *,char );
char pop(struct stack *);

int main()
{
    char name[10];
    printf("Enter String \n");

    scanf("%s",name);
    fflush(stdin);
    struct stack S;
    S.tos=-1;


    int length=strlen(name);
    for(int i=0; i<length; i++)
    {

        push(&S,name[i]);
    }
    for(int j=0; j<length; j++)
    {

        if(pop(&S)!=name[j])
        {
            printf("Not Palindrome");
            return 0 ;
        }
    }
    printf("String is palindrome ");
    return 0;
}
void push(struct stack *p,char n)
{
   if(p->tos==9)
   {
       printf("Stack Overflow ");
       return ;
   }
   p->tos++;
   p->arr[p->tos]=n;

}
char pop(struct stack *p)
{
    if(p->tos==-1)
    {
        printf("Underflow");
    }
    char x=p->arr[p->tos];
    p->tos--;
    return x;
}
