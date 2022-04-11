#include<stdio.h>
#include<stdlib.h>
int partition(int *,int,int);
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void quick_sort(int arr[],int lb,int ub)
{
    int pivot_loc;
    if(lb<ub)
    {
        pivot_loc = partition(arr,lb,ub);
        quick_sort(arr,lb,pivot_loc);
        quick_sort(arr,pivot_loc+1,ub);

    }
}
int partition(int arr[],int l,int h)
{
    int pivot=arr[l];
    int start=l;
    int end=h;
    do
    {
    do
    {
        start++;
    }while(arr[start]<=pivot);

   do
    {
    end--;
   }while(arr[end]>pivot);



    if(l<h)
    {
    swap(&arr[start],&arr[end]);
    }
   }while(start<end);
   swap(&arr[l],&arr[end]);
   return end;
}
int main()
{
    int arr[]={11,13,7,12,16,9,24,5,10,3,1000};
    int size=10;

    quick_sort(arr,0,size);


    for(int j=0; j<10; j++)
    {
        printf("  %d ",arr[j]);
    }
    printf(" \n ");
    return 0;
}
