#include<stdio.h>
#define inf 999
void dijkstra(int s);
void prdistance(int s);
int w[10][10],d[10],vis[10],n;
int main()
{
   int s,j,i;
   printf("Enter the no. of nodes:");
   scanf("%d",&n);
   printf("Enter the weight of the matrix:\n");
   for(i=0; i<n; i++)
   {
      for(j=0; j<n; j++)
      {
         scanf("%d",&w[i][j]);
         while(w[i][j]<0)
         {
            printf("Enter positive weight:");
            scanf("%d",&w[i][j]);
         }
      }
   }
   printf("Enter source:");
   scanf("%d",&s);
   dijkstra(s);
   prdistance(s);
   return 0;
}
void dijkstra(int s)
{
   int i,k,min;
   for(i=0; i<n; i++)
   {
      d[i]=inf;
      vis[i]=0;
   }
   d[s]=0;
   for(k=0; k<n; k++)
   {
      min=-1;
      for(i=0; i<n; i++)
      {
         if((!vis[i])&&((min==-1)||(d[i]<d[min])))
            min=i;
      }
      vis[min]=1;
      for(i=0; i<n; i++)
      {
         if(w[min][i]!=0)
         {
            if((d[min]+w[min][i])<d[i])
               d[i]=d[min]+w[min][i];
         }
      }
   }
}
void prdistance(int s)
{
   int i;
   printf("Shortest path \n");
   for(i=0; i<n; i++)
   {
      printf(" %d-> %d,cost =%d",s,i,d[i]);
   }
}
