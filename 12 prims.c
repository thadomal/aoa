#include<stdio.h>
#define max 20
#define infinity 9999

int graph[max][max],mst[max][max],n;
int prim();

int main()
{
    int i,j,totalcost;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjaceny matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    totalcost = prim();


    printf("\nMinimum Spanning Tree:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
            printf("%d\t",graph[i][j]);
        }
    }
    printf("\n\nTotal cost of minimum spanning tree: %d",totalcost);
    return 0;
}

int prim()
{
    int cost[max][max];
    int i,j,u,v,edges,mindist,mincost;
    int distance[max],from[max],visited[max];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(graph[i][j] == 0)
            {
                cost[i][j] = infinity;
            }
            else
            {
                cost[i][j] = graph[i][j];
                mst[i][j] = 0;
            }
        }
    }

    distance[0]=0;
    visited[0]=1;
    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }

    mincost = 0;
    edges = n-1;

    while(edges > 0)
    {
        mindist = infinity;
        for(i=1;i<n;i++)
        {
            if((visited[i]==0) && (mindist > distance[i]))
            {
                v=i;
                mindist = distance[i];
            }
        }

        u = from[v];
        mst[u][v] = distance[v];
        mst[v][u] = distance[v];
        edges--;
        visited[v]=1;

        for(i=1;i<n;i++)
        {
            if((visited[i] == 0) && (distance[i] > cost[i][v]))
            {
                distance[i] = cost[i][v];
                from[i]=v;
            }
        }
        mincost = mincost + cost[u][v];
    }
    return (mincost);
}
