#include<stdio.h>
#include<conio.h>
int f1(int);
int main()
{
    int a=5;
    printf("%d",f1(a));
    //f1(a);
    return 0;
}
int f1(int n){
    if(n>0){
        //printf("\n %d ",n);
        return f1(n-1)+n;
       // printf("\n%d",n);
    }
}
