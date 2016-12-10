#include<stdio.h>
#define IN 999
int n,e,d[10];
int bell(int);
void printd(int);
struct edge
{
    int u,v,w;
    char label[10];
};
struct edge Edge[20];
main()
{
  int weight,i,j,s;
  printf("Enter no. of nodes:");
  scanf("%d",&n);
  printf("Label the node:");
  for(i=0;i<n;i++)
    scanf("%s",&Edge[i].label);
  e=0;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {
          printf("Weight of %s to %s=",Edge[i].label,Edge[j].label);
          scanf("%d",&weight);
          if(weight!=0 && weight!=IN)
          {
              Edge[e].u=i;
              Edge[e].v=j;
              Edge[e].w=weight;
              e++;
          }
      }
  }
  printf("Enter the source node:");
  scanf("%d",&s);
  bell(s);
  printd(s);
}
int bell(int s)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        d[i]=IN;
        d[s]=0;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<e;j++)
        {
            if(d[Edge[j].v]>d[Edge[j].u]+Edge[j].w)
            {
                d[Edge[j].v]=d[Edge[j].u]+Edge[j].w;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(d[Edge[j].v]>d[Edge[j].u]+Edge[j].w)
            {
                printf("Error");
                exit(1);
            }
        }
    }
    return 0;
}
void printd(int s)
{
    int i;
    printf("Shortest distance is:");
    for(i=0;i<n;i++)
    {
        printf("%s->%s=distance=%d\n",Edge[s].label,Edge[i].label,d[i]);
    }
}
