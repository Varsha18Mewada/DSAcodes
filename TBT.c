#include<stdio.h>
#include<stdlib.h>
struct tbt {
    struct tbt *left;
    int data;
    struct tbt *right;
    int flag;
};
void append(struct tbt **,int);
void inorder(struct tbt*);
int main()
{
    struct tbt *root=NULL;
    int x;

    for(int i=1; i<=5; i++)
    {
    printf("Enter the elements ");
    scanf("%d",&x);
    append(&root,x);
    }

    inorder(root);
    return 0;


}
void append(struct tbt **pr,int x)
{
    struct tbt *p,*prev,*temp;
    p=(struct tbt *)malloc(sizeof(struct tbt));
    if(p==NULL)
    {
        printf("Insufficient memory");
        return;
    }
    p->data=x;
    p->left=p->right=NULL;
    if(*pr==NULL)
    {
        *pr=p;
        return;
    }
    temp=*pr;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->data>x)
        {
           temp=temp->left;
        }
        else{
            temp=temp->right;
        }
        if(prev->flag==1)
            break;
    }
    if(prev->data>x)
    {
        prev->left=p;
        p->right=prev;
        p->flag=1;
    }
    else{
        p->right=prev->right;
        prev->right=p;
        if(p->right!=NULL)
        {
            p->flag=1;
        }
        else
            p->flag=0;
        prev->flag=0;
    }
}
void inorder(struct tbt*p)
{
    if(p==NULL)
    {
        printf("Tree is empty ");
        return;
    }
    while(p!=NULL)
    {
        while(p->left!=NULL)
            p=p->left;
        printf("%d \t",p->data);
        while(p->flag==1)
          {
              p=p->right;
              printf("%d \t",p->data);
          }
        p=p->right;

    }
}
