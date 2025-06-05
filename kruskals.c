#include<stdio.h>
#include<stdlib.h>
int kruskals(int n,int mincost,int cost[10][10])
{
    int parent[10]={0};
    int ne=1,a=0,b=0,u=0,v=0,min,i,j;
    while(ne<n)
    {
        min=999;
         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
         }
         while(parent[u]>0)
            u=parent[u];
        while(parent[v]>0)
            v=parent[v];
        if(u!=v)
        {
            printf("%d minimum edge is %d-->%d and its cost is %d\n",ne,a,b,min);
            mincost+=min;
            parent[u]=v;
            ne++;
        }
        cost[a][b]=cost[b][a]=999;
    }
    return mincost;
}

int main()
{
    int i,j,mincost=0,n;
    int cost[10][10];
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
          scanf("%d",&cost[i][j]);
        }
    }
    mincost=kruskals(n,mincost,cost);
    printf("The minimum spanning tree cost is:%d",mincost);
    return 0;
}