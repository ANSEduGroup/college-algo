#include<stdio.h>
#define INF 99999
int p[10];
long int m[10][10];int s[10][10];
void matchain(int n)
{
    int l,i,j,k;
    long int q;
    for(i=1;i<n;i++)
    m[i][i]=0;
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=(n-l+1);i++)
        {
            j=i+l-1;
            m[i][j]=INF;
            for(k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+((p[i-1])*(p[k])*(p[j]));
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}
void optimal(int i,int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        optimal(i,s[i][j]);
        optimal(s[i][j]+1,j);
        printf(")");
    }
}
int main()
{
    int i,j,n;
    printf("Enter no. of matrices:");
    scanf("%d",&n);
    printf("Enter dimensions:");
    for(i=0;i<=n;i++)
        scanf("%d",&p[i]);
    matchain(n);
    printf("Cost matrix is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",m[i][j]);
        printf("\n");
    }
    printf("Scalar matrix is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d\t",s[i][j]);
        printf("\n");
    }
    optimal(1,n);
    printf("\nThe cost is: %d",m[1][n]);
    return 0;

}
