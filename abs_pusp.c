#include<stdio.h>
 void update(int *a,int *b){
int X = *a+*b;
int Y = abs(*a-*b);
*a = X;
*b  = Y;
}

int main() {
    int a, b;
   int *pa = &a, *pb = &b;
    printf("Enter a and b");
    scanf("%d %d", &a, &b);


    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


/*
#include <stdio.h>
int max_of_four(int a,int b,int c,int d){
    int max;
    max = a>b?a:b;
    max = c>max?c:max;
    max = d>max?d:max;
    return max;
}
int main(){
    int a, b, c, d;
    printf("Enter the values a,b,c,d");
    scanf("%d%d%d%d\n", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    return 0;
}
*/
