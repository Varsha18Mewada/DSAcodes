#include<stdio.h>
#include<string.h>
#include<math.h>
struct stack {
float arr[20];
int tos;

};
void push(struct stack *p,float x)
{
    p->arr[++p->tos]=x;
}
float pop(struct stack *p)
{
    return p->arr[p->tos--];
}
int isoperand(char ch)
{
    if(ch>=48 && ch<=57)
        return 1;
    return 0;
}



float calculate(float op1,float op2,char ch){
switch(ch){
case '+':
    return op1+op2;
case '-':
    return op1-op2;
case '*':
    return op1*op2;
case '/':
    return op1/op2;
case '$':
    return pow(op1,op2);
case '%':
    return fmod(op1,op2);
default:
    return 0.0;
}
}
float solve( char prefix[20])
{
    struct stack s;
    s.tos = -1;
    int i;
    float op1,op2,ans;
    char ch;
    for(i=strlen(prefix)-1; i>=0; i--)
    {
        ch=prefix[i];
        if(isoperand(ch)==1)
        {
           push(&s,ch-'0');
        }
        else{
            op1=pop(&s);
            op2=pop(&s);
            ans = calculate(op1,op2,ch);
            push(&s,ans);
        }
    }
    return pop(&s);


}



int main()
{
    char prefix[20];
    printf("Enter a valid prefix Expression :");
    scanf("%s",prefix);

    float res = solve(prefix);
    printf("Result of prefix expression is :%f",res);
    return 0;
}
