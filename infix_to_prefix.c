
#include<stdio.h>
#include<string.h>
struct stack{
    char arr[15];
    int tos;
};
void push( struct stack*,char);
char pop(struct stack *);
int isoperand(char);
int isempty(struct stack);
int prcd(char,char);
void convert(char [],char []);
int main(){


    char infix[15];
    char prefix[15];
    printf("Enter a valid infix  expression ");
    scanf("%s",infix);
    convert(infix,prefix);
    printf("%s",prefix);


return 0;

}
void push(struct stack *p,char ch){
    p->arr[++p->tos]=ch;

}
char pop(struct stack *p){
    return p->arr[p->tos--];
}
int isoperand(char ch){
    if((ch>=48 && ch<=57)||(ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z'))
        return 1;
    return 0;
}
int isempty(struct stack s){
    if(s.tos==-1)
        return 1;
    return 0;
}

int prcd( char op1,char op2)
{

    if(op1=='$')
        return 1;
    else if(op2=='$')
        return 0;
    else if(op1=='*'||op1=='/'||op1=='%')
        return 1;
    else if(op2=='*'||op2=='/'||op2=='%')
        return 0;
    else if(op1=='+'||op1=='-')
        return 1;
    else
        return 0;
}

void convert(char infix[], char prefix[]){
struct stack s;

int ans,i,j=0;
char ch;
s.tos=-1;
for(i=strlen(infix)-1; i>=0; i--){
        ch=infix[i];
        if(isoperand(ch)==1){
            prefix[j]=ch;
            j++;
        }
        else{
                while(isempty(s)==0){
                        ans=prcd(ch,s.arr[s.tos]);
                        if(ans==1)
                            break;
                        prefix[j]=pop(&s);
                        j++;}
                push(&s,ch);

        }
    }
        while(isempty(s)==0){
            prefix[j]=pop(&s);
            j++;}
        prefix[j]='\0';
        strrev(prefix);

    }

