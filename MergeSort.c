#include<stdio.h>
void merge(int [],int ,int ,int);
void mergesort(int [],int ,int );
int main()
{
    int a[10],i,n;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements which to be sort: ");
    for(i=0;i<n;i++)
        {
         scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printf("After merge sorting elements are: ");
    for(i=0;i<n;i++)
    {
         printf("%d ",a[i]);
    }
   return 0;
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
        {
         mid=(low+high)/2;
         mergesort(a,low,mid);
         mergesort(a,mid+1,high);
         merge(a,low,mid,high);
    }
}
void merge(int a[],int low,int mid,int high)
{
    int i,m,k,l,temp[10];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high))
        {
       if(a[l]<=a[m])
       {
             temp[i]=a[l];
             l++;
         }
         else{
             temp[i]=a[m];
             m++;
         }
         i++;
    }
    if(l>mid)
        {
         while(m<=high)
         {
             temp[i]=a[m];
             m++;
             i++;
         }
    }
    if(m>high)
    {
         while(l<=mid)
         {
             temp[i]=a[l];
             l++;
             i++;
         }
    }
    for(k=low;k<=high;k++){
         a[k]=temp[k];
    }
}
