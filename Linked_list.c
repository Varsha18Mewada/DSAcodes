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
 void append(struct node **,int);
 void display(struct node *);
 int countNode(struct node *);
 int searchNode(struct node *,int);
 void add_at_beg(struct node **,int);
 void insert( struct node **,int);
 void print_rev(struct node *);
 void del_first(struct node **);
 void del_last(struct node **);
 void del_any(struct node **,int);
 int pop(struct stack*);
 void push(struct stack*,int);


int main()
{
struct node *start = NULL;
int choice,x,y;
do{
    printf("\n 1.Append \n 2.Display \n 3.CountNode \n 4.insert \n 5.searchNode \n 6.del_first \n 7.del_last \n 8.add_at_beg\n 9.print_rev \n  10.del_any \n 11.Exit \n \n");
    printf("\n Enter operation. ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("\n Enter a element : ");
        scanf("%d",&x);
        append(&start,x);
        break;
    case 2:
        display(start);
        break;
     case 3:
        printf("Total number of nodes in list is %d ",countNode(start));
        break;
    case 4:
        printf("Enter an element ");
        scanf("%d",&x);
        insert(&start,x);
        break;
    case 5:
        printf("\n Enter a value to search : ");
        scanf("%d",&y);

        int c = searchNode(start,y);
        if(c == 0)
            printf("List is empty ");
        else if(c == -1)
            printf("Element not Found ");
        else
            printf(" Position of the element is %d",c);
        break;

    case 6:
        del_first(&start);
        break;
    case 7:
        del_last(&start);
        break;
    case 8:
        printf("\n Enter a element : ");
        scanf("%d",&x);
        add_at_beg(&start,x);
        break;

    case 9:
        print_rev(start);
        break;

    case 10:
        printf("\n Enter a element for deletion: ");
        scanf("%d",&x);
        del_any(&start,x);
        break;
    case 11:
        return 0;
        break;
    default:
        printf("\n Invalid choice");
        break;
    }
}
while(choice != 11);
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
  void display(struct node *p)
  {
      if(p==NULL)
      {
          printf("\n No element in the list ");
          return;
      }
      while(p!=NULL)
      {
         printf("\n %d",p->data);
         p=p->next ;
      }
  }
  int countNode(struct node *p)
  {
    int count = 0;

  while(p != NULL)
  {
     count++;
     p = p->next;
  }
  return count;

  }

int searchNode(struct node *p,int x)
{     int count =0;
    while(p!=NULL)
    {
       count++;
      if(x==p->data)
      {
        p=p->next;
        return count;
      }
      else
     {
        return -1;
      }


    }

    return 0;
}





void del_first(struct node **ps)
{
    struct node *temp;
    if(*ps==NULL)
    {
        printf("List is Empty ");
        return;
    }
    // Below if block code is optional
    if((*ps)->next==NULL)
    {
        free(*ps);
        *ps=NULL;
        printf("Node deleted successfully ");
        return;
    }
    // optional.....
    temp=*ps;
    *ps=(*ps)->next;
    free(temp);
    printf("Node deleted successfully ");


}

/**void del_last(struct node **ps)
{
    struct node *temp,*prev;
    if(*ps==NULL)
    {
        printf("List is Empty ");
        return;
    }
    if((*ps)->next==NULL)
    {
        free(*ps);
        *ps=NULL;
        printf("Node deleted successfully ");
        return;
    }
    temp = *ps;
    while(temp->next != NULL)
    {
        prev = temp;
        temp=temp->next;
    }
    free(temp);
    prev->next =NULL;
    printf("Node deleted successfully ");

}
**/

//------------->>>>>del_last without prev pointer<<<<--------------
void del_last(struct node **ps)
{
    struct node *temp;
    if(*ps==NULL)
    {
        printf("List is Empty ");
        return;
    }
    if((*ps)->next==NULL)
    {
        free(*ps);
        *ps=NULL;
        printf("Node deleted successfully ");
        return;
    }
    temp = *ps;
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted successfully ");
}

void add_at_beg(struct node**ps,int x){
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if(p==NULL){
    printf("Insufficient memory");
    return ;
}
p->data=x;
p->next=*ps;
*ps=p;
 printf("Node added successfully ");

}
void insert(struct node **ps, int x){
    struct node *p,*temp,*prev;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL){
    printf("Insufficient memory");
    return ;
}
p->data=x;
if(*ps==NULL){
    *ps=p;
    p->next=NULL;
    printf("Node added successfully");
    return ;
}

if(x<(*ps)->data){
        p->next=*ps;
        *ps=p;
        printf("Node added successfully");
        return ;}
temp=*ps;

while(temp!=NULL && x>temp->data){
    prev=temp;
    temp=temp->next;
}
if(temp==NULL){
    prev->next=p;
    p->next=NULL;
    printf("Node added successfully");
}
else{
    prev->next=p;
    p->next=temp;
       printf("Node added successfully");
    }
}

/** Without prev. pointer
while(temp->next->next!=NULL && x>temp->data){
    temp=temp->next;
}
if(temp->next==NULL){
    temp->next=p;
    p->next=NULL;
}
else{
    temp->next=p;
    p->next=temp->next->next;
}
/* with prev. pointer */

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
void print_rev(struct node *p){
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
        }
    }


}

void del_any(struct node **ps, int x){
    struct node *temp,*prev;
    if(*ps==NULL){
        printf("List is empty");
        return;
    }
    temp=*ps;
    if(temp->data==x){
        *ps=(*ps)->next;
        free(temp);
        printf("node delete successfully");
        return;
    }
    while(temp!=NULL && temp->data!=x){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Node not found");
    }
    else{
        prev->next=temp->next;
        free(temp);
        printf("node delete successfully");
    }
}
