// Online C compiler to run C program onlin
// Online C compiler to run C program onlin
#include<stdio.h>
#include<math.h>
#include<string.h>
struct stack{
    float arr[20];
    int tos;

};

float solve(char[]);
int isoperand(char);
void push(struct stack *,float);
float pop(struct stack *);

float calculate(float,float,char);

int main(){

    char postfix[20];
    float ans;
    printf("Enter a valid postfix expression:");
    scanf("%s",postfix);
    ans=solve(postfix);
    printf("result of expression is %f",ans);
    return 0;
}
float solve(char postfix[20]){
    struct stack s;
    s.tos=-1;
    int i;
    char op;
    float pop1,pop2,result;
    for (i=0; postfix[i]!='\0'; i++){
      op=postfix[i];
      if(isoperand(op)==1){
        push(&s,op-'0');
      }
      else{
    pop2=pop(&s);
    pop1=pop(&s);
    result=calculate(pop1,pop2,op);

    push(&s,result);


      }
    }
    result=pop(&s);
    return result;

}
void push(struct stack *p,float val){
    //s->tos=s->tos+1;
    p->arr[++p->tos]=val;


}
float pop(struct stack *p){
    //float x;
    return p->arr[p->tos--];
    //s->tos=s->tos-1;
    //return x;

}
int isoperand(char ch){
    if(ch>=48 && ch<=57)
        return 1;
    return 0;
}

float calculate(float pop1,float pop2,char op){
switch(op){
case '+':
    return pop1+pop2;
case '-':
    return pop1-pop2;
case '*':
    return pop1*pop2;
case '/':
    return pop1/pop2;
case '$':
    return pow(pop1,pop2);
case '%':
    return fmod(pop1,pop2);
default:
    return 0.0;
}
}

