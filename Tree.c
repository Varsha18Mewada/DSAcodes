#include<stdio.h>
#include<stdlib.h>
struct stack{
    struct bst *arr[10];
    int tos;
};
struct bst{
    struct bst *left;
    int data;
    struct bst *right;
    int flag;

};
void append(struct bst **,int);
void preorder(struct bst *);
void push(struct stack *,struct bst *);
struct bst *pop(struct stack *);
void inorder(struct bst *);
void postorder(struct bst *);
int searchnode( struct bst *,int,struct bst **,struct bst ** );
void del_node(struct bst **,int);
int checkbst(struct bst *);

int main(){
 struct bst *root=NULL;
 int choice,x;
    do{
    printf("\nEnter your choice : \n 1.Append \n 2.Preorder \n 3. Inorder \n 4. Postorder \n 5.DeleteNode \n 6.CheckBst \n 7.Exit\n");
    scanf("%d",&choice);
    switch(choice){

            case 1:
                printf("\nEnter a no. ");
                scanf("%d",&x);
                append(&root,x);
                printf("\n %d Inserted Successfully ",x);
                break;
            case 2:

                preorder(root);
                break;
            case 3:

                inorder(root);
                break;
            case 4:

                postorder(root);
                break;
            case 5:
                printf("Enter the element to delete");
                scanf("%d",&x);
                del_node(&root,x);
                break;
            case 6:

                x=checkbst(root);
                if(x==1){
                    printf("Tree is BST \n");
                }
                else{
                    printf("Not  BST \n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("\nInvalid choice ");

    }
    }
    while(choice!=7);
    return 0;
}
void append(struct bst **pr,int x){
    struct bst *p,*temp,*prev;
    p=(struct bst *)malloc(sizeof(struct bst));
    if(p==NULL){
        printf("Insufficient memory");
        return;
    }
    p->data=x;
    p->left=p->right=NULL;
    if(*pr==NULL){
        *pr=p;
        return;
    }
    temp=*pr;
    while(temp!=NULL){
        prev=temp;
        if(x<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(x<prev->data)
        prev->left=p;
    else
        prev->right=p;



}
void push(struct stack *p,struct bst *q){
    if(p->tos==9){
        printf("Overflow");
        return;
    }
    p->tos++;
    p->arr[p->tos]=q;
    //printf("Pushed successfully");

}
   struct bst* pop(struct stack *p){
    struct bst *temp;
    if(p->tos==-1)
        {
            return NULL;
            printf("UnderFlow");
    }
    temp=p->arr[p->tos];
    p->tos=p->tos-1;
    return temp;


}
void preorder(struct bst *p){
    struct stack s;
    if(p==NULL){
        printf("tree is empty");
        return;
    }
    s.tos=-1;
    push(&s,p);
    while(s.tos!=-1)
        {
        p=pop(&s);
        while(p!=NULL)
        {
            printf(" \t%d ",p->data);
            if(p->right!=NULL)
            {
                push(&s,p->right);
            }
            p=p->left;

        }
    }
}

void inorder(struct bst *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Tree is empty");
        return;
    }
    s.tos=-1;
    while(p!=NULL)

{

       while(p!=NULL)
        {
        push(&s,p);
        p=p->left;

        }
        p=pop(&s);
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            if(p->right!=NULL)
            {
                p=p->right;
                break;
            }
            p=pop(&s);
        }

}
}

/*
void inorder(struct bst *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Tree is empty");
        return;
    }
    s.tos=-1;
    push_node:
        while(p!=NULL)
        {
        push(&s,p);
        p=p->left;

        }
        p=pop(&s);
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            if(p->right!=NULL)
            {
                p=p->right;
                goto push_node;
            }
            p=pop(&s);
        }

}

*/
void postorder(struct bst *p)
{
    struct stack s;
    s.tos=-1;
    if(p==NULL)
    {
        printf("Tree is empty");
        return;
    }
    while(p!=NULL)
    {
    while(p!=NULL)
    {
        push(&s,p);
        p->flag=1;
        if(p->right!=NULL)
        {
            push(&s,p->right);
            p->right->flag=-1;
        }
        p=p->left;
    }
    p=pop(&s);
    while(p!=NULL && p->flag==1)
    {
      printf(" %d \t",p->data);
      p=pop(&s);
    }
    }
}
int searchnode(struct bst *root,int x, struct bst **pc,struct bst **pr)
{
   struct bst *q=NULL;
   while(root!=NULL)
   {
       if(root->data==x)
       {
           *pc=root;
           *pr=q;
           return 1;
       }
       q=root;
       if(x<root->data)
       {
           root=root->left;
       }
       else
        {
        root=root->right;
       }
   }
   return 0;
}

void del_node(struct bst **pr,int x)
{
   struct bst *child,*par,*q,*prev;
   int result;
   if(*pr==NULL)
   {
       printf("Tree is empty");
       return;
   }
   result=searchnode(*pr,x,&child,&par);
   if(result==0){
    printf("Node not found");
    return;
   }
if(child->left !=NULL && child->right!=NULL)
{
    par=child;
    q=child->right;
    while(q->left!=NULL){
        par=q;
        q=q->left;
    }


    child->data=q->data;
    child=q;


}
if(child->left==NULL && child->right==NULL)
{
    if(par==NULL)
    {
        *pr=NULL;
    }
    else if(par->left==child){
        par->left=NULL;
    }
    else{
        par->right=NULL;
    }
}
else if(child->left!=NULL && child->right==NULL)
{
    if(par==NULL)
    {
        *pr=child->left;
    }
    else if(par->left==child){
        par->left=child->left;
    }
    else{
        par->right=child->left;
    }
}
else if(child->left==NULL && child->right!=NULL)
{
    if(par==NULL)
    {
        *pr=child->right;
    }
    else if(par->left==child){
        par->left=child->right;
    }
    else{
        par->right=child->right;
    }
}


}
int checkbst(struct bst *root)
{
    if(root==NULL)
    {
        //printf("Empty Tree");
        return 0;
    }
    if( root->left!=NULL && maxValue(root->left)>root->data)
    {
        return 0;
    }
    if( root->right!=NULL && maxValue(root->right)<root->data)
    {
        return 0;
    }
    if((!checkbst(root->left)) || (!checkbst(root->right)) )
    {
        return 0;
    }
    return 1;
}

