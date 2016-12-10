#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int board[20],count=0;
void queen(int row,int n);
void printboard(int n);
int safeplace(int row,int col);
int main()
{
   int n,i,j;
   printf("Enter no. of queens:");
   scanf("%d",&n);
   queen(1,n);
   return 0;
}
void queen(int row,int n)
{
   int col;
   for(col=1; col<=n; col++)
   {
      if(safeplace(row,col)==1)
      {
         board[row]=col;
         if(row==n)
            printboard(n);
         else
            queen(row+1,n);
      }
   }
}
int safeplace(int row,int col)
{
   int i;
   for(i=1; i<row; i++)
   {
      if(board[i]==col)
         return 0;
      else if(abs (board[i]-col)==abs(i-row))
         return 0;
   }
   return 1;
}
void printboard(int n)
{
   int i,j;
   printf("\nNo. of solution %d\n\n",++count);
   for(i=1; i<=n; i++)
      printf("\t%d",i);
   for(i=1; i<=n; i++)
   {
      printf("\n\n%d",i);
      for(j=1; j<=n; j++)
      {
         if(board[i]==j)
            printf("\tQ");
         else
            printf("\t-");
      }
   }
   printf("\n\nPress any key to continue");
}
