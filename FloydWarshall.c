#include<stdio.h>
void display(int);
int min(int,int);
void floyd(int);
int w[10][10],d[10][10][10],p[10][10][10];
main()
{
   int i,j,v;
   printf("Enter the no. of vertices: ");
   scanf("%d",&v);
   printf("\nEnter the weight matrix: \n");
   for(i=1; i<=v; i++)
      for(j=1; j<=v; j++)
         scanf("%d",&w[i][j]);
   floyd(v);
   display(v);
}
int min(int a,int b)
{
   if(a<b)
      return a;
   else
      return b;
}
void floyd(int v)
{
   int i,j,k=0;
   for(i=1; i<=v; i++)
      for(j=1; j<=v; j++)
         d[k][i][j]=w[i][j];

   for(i=1; i<=v; i++)
      for(j=1; j<=v; j++)
      {
         if(d[k][i][j]!=0 && d[k][i][j] !=999)
            p[k][i][j]=i;
         else
            p[k][i][j]=0;
      }
   for(k=1; k<=v; k++)
      for(i=1; i<=v; i++)
         for(j=1; j<=v; j++)
            d[k][i][j]=min(d[k-1][i][j],d[k-1][i][k]+d[k-1][k][j]);
   for(k=1; k<=v; k++)
      for(i=1; i<=v; i++)
         for(j=1; j<=v; j++)
         {
            if(d[k-1][i][j]<=d[k-1][i][k]+d[k-1][k][j])
               p[k][i][j]=p[k-1][i][j];
            else
               p[k][i][j]=p[k-1][k][j];
         }

   for(k=0; k<=v; k++)
   {
      printf("D=%d\n",k);
      for(i=1; i<=v; i++)
      {
         printf("\n");
         for(j=1; j<=v; j++)
         {
            if(d[k][i][j]==999)
               printf("\tINF");
            else
               printf("\t%d",d[k][i][j]);
         }
      }
      printf("\n\n");
   }
   for(k=0; k<=v; k++)
   {
      printf("P=%d\n",k);
      for(i=1; i<=v; i++)
      {
         printf("\n");
         for(j=1; j<=v; j++)
         {
            if(p[k][i][j]==0)
               printf("\t-");
            else
               printf("\t%d",p[k][i][j]);
         }
      }
      printf("\n\n");
   }
}
void display(int v)
{
   int i,j,k,a;
   char ch,c;
   while(1)
   {
      printf("\n\nEnter source node(1 to %d):",v);
      scanf("%d",&a);
      printf("\nShortest path from node %d is:\n",a);
      for(i=1; i<=v; i++)
      {
         if(p[v][a][i]==0)
            printf("- -> %d\t Cost= INF \n",i);
         else
            printf("%d -> %d\t Cost= %d\n",p[v][a][i],i,d[v][a][i]);
      }
      printf("Press E to exit, or any other key to continue.!");
      ch=getchar();
      if(ch=='E'|| ch == 'e')
         break;
   }
}
