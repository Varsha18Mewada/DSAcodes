#include<stdio.h>
#include<stdlib.h>
struct poly{
int data;
int exp;
struct poly *next;
};
void append(struct poly **,int ,int);
void show (struct poly *);
void add(struct poly*,struct poly*,struct poly** );
int main(){
    struct poly *first,*second,*third;
    first=second=third=NULL;
    int choice,e,c;
    do{
        printf("Enter your choice \n 1.Append for 1st Polynomial \n 2.Append for 2nd Polynomial \n 3.Show for 1st polynomial  \n 4.Show for 1st polynomial \n 5.Add \n 6.Show for 3rd polynomial \n 7.Exit \n");
        scanf("%d",&choice);
        switch(choice){
    case 1:
        printf("\n Enter coefficient :");
        scanf("%d",&c);
        printf("\n Enter Exponent :");
        scanf("%d",&e);
        append(&first,c,e);
        break;
     case 2:
        printf("\n Enter coefficient :");
        scanf("%d",&c);
        printf("\n Enter Exponent :");
        scanf("%d",&e);
        append(&second,c,e);
        break;
     case 3:
        show(first);
        break;
     case 4:
        show(second);
        break;
    case 5:
        add(first,second,&third);
        break;
    case 6:
        show(third);
        break;
    case 7:
        exit(0);
    default:
        printf("Invalid choice");
        }
}
  while(choice !=7);
}

void append(struct poly **pf,int c,int e)
{
    struct poly *p,*temp;
    p=(struct poly*)malloc(sizeof(struct poly));
    if(p==NULL)
    {
        printf("Insufficient Memory");
        return;
    }
    p->data=c;
    p->exp=e;
    p->next=NULL;

        if(*pf==NULL)
        {
            *pf=p;
            return;
        }
        temp=*pf;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
        return;

}

void show(struct poly* p)
{
    if(p==NULL)
    {
        printf("Polynomial is empty \n");
        return;
    }
    while(p!=NULL)
    {
       printf("%dx^%d+",p->data,p->exp);
       p=p->next;
    }
 printf("\b \n");
}
void add(struct poly*f,struct poly *s,struct poly ** pt)
{
    struct poly *p,*temp,*q=NULL;

    if(f==NULL && s==NULL)
    {
        printf("Addition not possible ");
        return;

    }
    while(f!=NULL && s!=NULL)
    {
       p=(struct poly *)malloc(sizeof(struct poly));
       p->next=NULL;
       if(*pt==NULL){
        *pt=p;
        return;
       }
       else
            temp->next=p;
    temp=p;
    if(f->exp<s->exp){
        temp->exp=f->exp;
        temp->data=f->data;
        f=f->next;
        printf("Addition successfully");
    }
    else if(s->exp<f->exp){
        temp->exp=s->exp;
        temp->data=s->data;
        s=s->next;
        printf("Addition successfully");
    }
    else{
        temp->data=(f->data)+(s->data);
        temp->exp=f->exp;
        f=f->next;
        s=s->next;
        printf("Addition successfully");
    }
    }
    if(f!=NULL)
        q=f;
    else if(s!=NULL)
        q=s;
    while(q!=NULL){
        p=(struct poly *)malloc(sizeof(struct poly));
    p->exp=q->exp;
    p->data=q->data;
       p->next=NULL;
       printf("Addition successfully");
       if(*pt==NULL){
        *pt=p;
        return;
       }
       else
            temp->next=p;
    temp=p;

    }
printf("Polynomial addition successfully");
}




