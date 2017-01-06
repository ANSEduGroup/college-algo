#include<stdio.h>
int bsearch(int [],int,int,int);
int main()
{
   int i,n,l,h,key,pos;
   int a[100];
   printf("Enter the size:");
   scanf("%d",&n);
   printf("Enter the elements:");
   for(i=0; i<n; i++)
   {
      scanf("%d",&a[i]);
   }
   l=0;
   h=n-1;
   printf("Enter the no. to be searched:");
   scanf("%d",&key);
   pos=bsearch(a,h,l,key);
   if(pos!=-1)
   {
      printf("No. present at %d",(pos+1));
   }
   else
   {
      printf("Not present");
   }
   return 0;
}
int bsearch(int a[],int i,int l,int x)
{
   int mid;
   if(i==l)
   {
      if(x==a[i])
         return i;
      else
         return 0;
   }
   else
   {
      mid=(i+(l-i))/2;
      if(x==a[mid])
      {
         return mid;
      }
      else if(x<a[mid])
      {
         bsearch(a,i,mid-1,x);
      }
      else
      {
         bsearch(a,mid+1,l,x);
      }
   }
}
