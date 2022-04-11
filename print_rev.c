#include<stdio.h>
#include<stdlib.h>
struct node{

int data;
struct node *next;

};
 struct stack {
    int tos;
    int arr[10];
    };
  void append(struct node** ,int);
  void print_rev(struct node *);
  int pop(struct stack*);
  void push(struct stack*,int);
  void del_any(struct node **,int);


int main()
{ struct node *start=NULL;
    int x,choice;
    do{
        printf("\n 1.Append \n 2.print_rev \n  3. del_any \n 4. insert \n 5. Quit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
    switch(choice)
    {
     case 1:
         printf("\n Enter a element : ");
         scanf("%d",&x);
         append(&start,x);
         break;
     case 2:
        print_rev(start);
        break;
    case 3:
        printf("\nEnter a element : ");
        scanf("%d",&x);
        del_any(&start,x);
        break;
    case 4:
        printf("\nEnter a element : ");
        scanf("%d",&x);
        insert(&start,x);
        break;
    case 5:
        return 0;
        break;
     default:
        printf("invalid choice");
        break;

    }
 }while(choice != 5);


return 0;
}

void append(struct node **ps,int x){
 struct node *p,*temp;

 p=(struct node*)malloc(sizeof(struct node));
 if(p==NULL)
   {
      printf("\n Cannot add new Node ");
      return;
   }
   p->data=x;
   p->next=NULL;
 if(*ps==NULL)
 {
     *ps=p;
     printf("\n Node added Successfully");
     return;
 }
 temp=*ps;
 while(temp->next != NULL)
 {
     temp=temp->next;

 }
 temp->next=p;
 printf("\n Node added Successfully");

}



    int pop(struct stack *p){
        int x;
        if(p->tos==-1){
            return 0;
        }
        x=p->arr[p->tos];
        p->tos--;
        return x;
    }
    void push(struct stack *p,int x){
    if(p->tos==9){
        printf("Stack overflow");
        return ;
    }
    p->tos++;
    p->arr[p->tos]=x;
    }
void print_rev(struct node *p)
{
    struct stack s;
    s.tos=-1;
    int i=0;
    /*if(p==NULL){
        printf("List is empty ");
        return ;
    }*/
    while(p!=NULL){
            i++;
            push(&s,p->data);
            p=p->next;
    }
    int data;
    for(int n=i; n>=0; n--)
    {
        data=pop(&s);
        if(data!=0)
       {
            printf("reversed list is %d\n",data);
        }}
}

