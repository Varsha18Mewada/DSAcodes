#include<stdio.h>
void merge_sort(int *,int,int);
void merge(int *,int,int);
int main()
{
    int size,j;

    printf("Enter size of array : ");
    scanf("%d",&size);
     int arr[size];

    for(j=0; j<size; j++)
    {
        printf("Enter array element: ");
        scanf("%d",&arr[j]);
    }
    int f=0;
    int l=size-1;
    printf("Before sorting ");
    for(j=0; j<size; j++)
    {
        printf("%d ",arr[j]);
    }
    merge_sort(arr,f,l);
    printf(" \n After sorting ");
    for(j=0; j<size; j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}
void merge_sort(int arr[],int f1 , int l1)
{
    int mid;
    if(f1<l1)
    {
        mid=(f1+l1)/2;
        merge_sort(arr,f1,mid);
        merge_sort(arr,mid+1,l1);
        merge(arr,f1,l1);
    }
}
void merge(int arr[], int f1 , int l1)
{
    int temp[10];
    int mid=(f1+l1)/2;
    int i=f1;
    int j=mid+1;
    int k=f1;
    while(i<=mid && j<=l1)
    {
        if(arr[i]<=arr[j])
        {
             temp[k]=arr[i];
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i<=mid)
    {
        while(i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
    }
    else{
        while(j<=l1)
        {
             temp[k]=arr[j];
            j++;
            k++;
        }
    }
    i=0;
    while(i<k)
    {
        arr[i]=temp[i];
        i++;
    }
}
