#include<stdio.h>
void sel_sort(int a[],int n);
int a[50];
int main()
{
    int i,n;
    printf("Enter the no of elements :");
    scanf("%d",&n);
    printf("Enter the elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sel_sort(a,n);
    printf("the sorted array is:");
    for(i=0;i<n;i++)
    {
        printf("\t %d",a[i]);
    }
    return 0;
}

void sel_sort(int a[],int n)
{
    int i,j,k,temp,l;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[k]>a[j])
            k=j;
        }
        if(k!=i)
        {
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
        }
        for(l=0;l<n;l++)
        {
            printf("\t%d",l,a[l]);
        }
        printf("\n");
    }
}
