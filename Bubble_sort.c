#include<stdio.h>

int main()
{
    int size,i,j;
    printf("Enter array size :");
    scanf("%d",&size);

    int arr[size];
    printf("ENTER ARRAY ELEMENTS :");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);

        printf("Before sorting :");
        for(i=0;i<size;i++)
            printf("%d  ",arr[i]);

    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {

            if(arr[j]>arr[j+1])
            {
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
            }
        }
    }

     printf("\nAfter sorting :");
        for(i=0;i<size;i++)
            printf("%d  ",arr[i]);
    return 0;
}
