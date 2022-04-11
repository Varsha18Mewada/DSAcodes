#include<stdio.h>
void insert(int * ,int);
int main()
{
    int size ,i;
    printf("Enter size of array :");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array element : ");
    for(i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n Before sorting ");
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    insert(arr,size);
    printf("\n After sorting ");
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
void insert(int arr[],int n)
{
    int i,j,temp;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j>0; j--)
        {
            if(arr[j-1]>arr[j])
            {
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
            else{
                break;
            }
        }

    }
}
