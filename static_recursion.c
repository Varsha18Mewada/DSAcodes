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
    static int x=0;
    if(n>0){
        x++;

        //printf("\n %d ",n);
        return f1(n-1)+x;
       // printf("\n%d",n);
    }
}
