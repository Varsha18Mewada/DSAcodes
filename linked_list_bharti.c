#include<stdio.h>
int main(){
    struct node{
        int data;
        struct node* next;

    };
    void append(struct node ** ps,int x){
        struct node* p,*temp;
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        if(*ps==NULL){
                *ps=p;
                return ;
        }
        temp=*ps;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
        return ;

        }
        void display(struct node*p){
            if(p==NULL){
                printf("List is empty ");
                return ;
            }

            while(p!=NULL){
                    printf("The data is : ",p->data);
                    p=p->next;

            }
            }
    int searchnode(struct node *p,int x){
        if(p==NULL){

            return 0;
        }

        int pos=0;
        while(p!=NULL){
                pos++;
            if(x==p->data)
                return pos;
            p=p->next;

        }
        return -1;
        }
    int countnode(struct node*p){
    if(p==NULL){
        printf("No Node ");
        return ;
    }
    int pos=0;
    while(p!=NULL){
    pos++;
    p=p->next;

    }
    return pos;
}
void add_at_beg(struct node**ps,int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=*ps;
    *ps=p;

}
void insert(struct node**ps,int x){
struct node *p,*temp,*prev;
p=(struct node *)malloc(sizeof(struct node));
p->data=x;
if(p==NULL){
    printf("Insufficient memory ");
    return ;}
if(*ps==NULL){
    *ps=p;
    p->next=NULL;
    return ;
}

if(x<(*ps)->data){
    p->next=*ps;
    *ps=p;
    return;}
    temp=*ps;
while(temp==NULL && x>temp->data){
    prev=temp;
    temp=temp->next;
}
if(temp==NULL){
   prev->next=p;
   p->next=NULL;
}
else{
    prev->next=p;
    p->next=temp;
}
    }

void del_first(struct node **ps){
    struct node *temp;
if(*ps==NULL){
    printf("List is empty ");
}
if((*ps)->next==NULL){

    free(*ps);
    *ps=NULL;
    return;
}
temp=*ps;
(*ps)=(*ps)->next;
free(temp;)

}
 void del_last(struct node**ps){
     struct node *temp,*prev;
     if(*ps==NULL){
    printf("List is empty ");
}
if((*ps)->next==NULL){

    free(*ps);
    *ps=NULL;
    return;
}
temp=*ps;
while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
}
free(temp);
prev->next=NULL;
}


return 0;
}
