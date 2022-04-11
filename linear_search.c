#include<stdio.h>
int linear(int *,int, int);
int main()
{
    int arr[10]={10,20,4,6,7,9,99};
    printf("which element you want to search ");
    int n=10;
    int  sr;
    scanf("%d",&sr);
    printf("The search element is  at index %d ",linear(arr,n,sr));

    return 0;
}
int linear(int arr[],int n, int f)
{
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]==f)
        {
            return i;
        }

    }
    return -1;
}
