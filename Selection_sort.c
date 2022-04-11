#include<stdio.h>
void selection(int *,int);
int main()
{
    int n , i,j;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array element : ");
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);

    printf("before sorting : ");
    for(i=0; i<n; i++)
        printf("%d",arr[i]);

    selection(arr,n);
     printf("After  sorting : ");
    for(i=0; i<n; i++)
        printf("%d",arr[i]);
    return 0;
}
void selection(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[min]>arr[j+1])
            {
                min=j;


            }
            if(min!=i)
            {
                int temp=arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
        }
    }
}
