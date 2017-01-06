#include<stdio.h>
int g[10][10],x[10],count=0,m,n;
void display();
void gcol(int k)
{
  int i;
  for(i=0; i<m; i++)
  {
    if(safecol(k,i)==1)
    {
      x[k]=i;
      if((k+1<n))
      {
        gcol(k+1);
        x[k+1]=m;
      }
      else
      display();
    }
  }
}
int safecol(int k1,int c)
{
  int i;
  for(i=0; i<n; i++)
  {
    if(g[i][k1]==1&&x[i]==c)
    return 0;
  }
  return 1;
}
void display()
{
  int i;
  printf("\n Solution %d",++count);
  for(i=0; i<n; i++)
    printf("\n Color of %d is c%d",i,x[i]);
  printf("\n Press any key to continue.");
}
void main()
{
  int i,j;
  printf("\nEnter the no. of nodes:");
  scanf("%d",&n);
  printf("Enter the no. of colors:");
  scanf("%d",&m);
  printf("Enter the weight matrix,i.e. if edge exists give 1 or else 0:");
  for(i=0; i<n; i++)
  for(j=0; j<n; j++)
  scanf("%d",&g[i][j]);
  for(i=0; i<n; i++)
  x[i]=m;
  gcol(0);
}
