//Maximum and Minimun elements of an array in C
#include<stdio.h>
int max,min;
int main()
{
   int i,n;
   int a[100];
   printf("Enter size of array : ");
   scanf("%d",&n);
   printf("Enter elements in array:\n");
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   max=min=a[0];
   maxmin(a,0,n-1);
   printf("Minimum : %d",min);
   printf("\nMaximum : %d",max);
   return 0;
}
void maxmin(int a[],int l,int h)
{
   int mid,max1,min1;
   if(l==h)
     max=min=a[l];
     else if(l==h-1)
     {
     if(a[l]<a[h])
     {
       min=a[l];
       max=a[h];
     }
     else
     {
       min=a[h];
       max=a[l];
     }
     }
   else
    {
     mid=(l+h)/2;
     maxmin(a,l,mid);
     max1=max;
     min1=min;
     maxmin(a,mid+1,h);
     if(max1>max)
         max=max1;
     if(min1<min)
         min=min1;
   }
}
