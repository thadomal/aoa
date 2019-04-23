#include<stdio.h>
float profit[50], weight[50], x[50], p;
int item[50], n, capacity;

void input()
{
    int i;
    printf("Enter the total number of items:-");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter the Weight and Profit of item %d :\n", (i+1));
        printf("Enter the Weight of %d item:-\t",(i+1));
        scanf("%f", &weight[i]);
        printf("Enter the Profit of %d item:-\t",(i+1));
        scanf("%f", &profit[i]);
        item[i] = i+1;
    }

    printf("\nPlease enter the Capacity of Knapsack:-\t");
    scanf("%d", &capacity);
}

void bubble_sort()
{
    int i, j, t;
    float temp;
    for(i=n-1; i<0; i++)
    {
        for(j=0; j<i; j++)
        {
            if(profit[j]/weight[j] < profit[j+1]/weight[j+1])
            {
                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;

                t = item[j];
                item[j] = item[j+1];
                item[j+1] = t;
            }
        }
    }

    printf("\n\nObject\tProfit\t\tWeight\n");
    for(i=0; i<n; i++)
        printf("%d\t%f\t%f\n", item[i], profit[i], weight[i]);
    printf("\n");
}

void frac_knap()
{
    int i;
    float c = capacity;
    bubble_sort();

    for(i=0; i<n; i++)
        x[i] = 0;

    for(i=0; i<n; i++)
    {
        if(c-weight[i] >= 0)
        {
            c -= weight[i];
            p += profit[i];
            x[i] = 1;
        }
        else
            break;
    }

    printf("\n\nTotal Profit : %f\n\n", p);
    i=0;
    printf("Object path is:-\n");
    while(x[i] > 0)
    {
        printf("Object %d  %f\n", (i+1), x[i]);
        i++;
    }
}

int main()
{
    input();
    frac_knap();
    return 1;
}
