#include<stdio.h>
int binary(int * , int, int);
int main()
{
    int arr[5]={1,2,3,4,5};
    printf("Enter the element which you want to find ");
    int n=5;
    int f;
    scanf("%d",&f);
    printf("The search element is at index %d", binary(arr,n,f));
    return 0;

}
int binary(int arr[], int n, int f)
{
    int l=0;
    int h=n-1;
    int m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(arr[m]==f)
        {
            return m;
        }
        else if(f>arr[m])
        {
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return -1;

}
