#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int beg, int end);
void quicksort(int a[],int beg, int end);
int main()
{
    int arr[50],i,n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nGiven Array : \n");
    for(i=0;i<n; i++)
    {
        printf("%d\t",arr[i]);
    }
    quicksort(arr, 0, n-1);
    printf("\nSorted Array is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
int partition (int a[],int beg, int end)
{
    int left, right, loc, temp, flag;
    loc=left=beg;
    right=end;
    flag=0;
    while(flag!=1)
    {
        while((a[loc]<=a[right]) && (loc!=right))
            right--;
        if(loc==right)
            flag=1;
        else if(a[loc]>a[right])
        {
            temp=a[loc];
            a[loc]=a[right];
            a[right]=temp;
            loc=right;
        }
        if(flag!=1)
        {
            while((a[loc]>=a[left]) && (loc!=left))
                left++;
            if (loc==left)
                flag=1;
            else if(a[loc]<a[left])
            {
                temp=a[loc];
                a[loc]=a[left];
                a[left]=temp;
                loc=left;
            }
        }
        printf("\nPass:     ");
        int k;
        for(k=0; k<end; k++)
        {
            printf("%d\t",a[k]);
        }
    }
    return loc;
}

void quicksort(int a[],int beg, int end)
{
    int loc;
    if(beg<end)
    {
        loc=partition(a, beg, end);
        quicksort(a,beg,loc-1);
        quicksort(a,loc+1,end);
    }
}
