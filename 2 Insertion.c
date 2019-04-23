#include<stdio.h>
int main()
{
    int a[20],n,i,j,key;
    printf("Enter the number of values:-");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element no. %d :",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n");
    for(i=1;i<n;i++)
    {
        key=a[i];
        for(j=i;j>0 && a[j-1]>key;j--)
            a[j]=a[j-1];
            a[j]=key;
        int k;
        for(k=0;k<n;k++)
        {
            printf("%d\t",a[k]);

        }
        printf("\n");
    }
    printf("The sorted array is:- ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return  0;
}
