#include<stdio.h>
float ratio[20];
float weight[20], profit[20];
void knapsack(int n, float capacity)
{
    float x[20], tp = 0.0;
    int i,j,k;
    int p,q;
    float u = capacity;
    for(i = 0; i < n; i++)
    {
        if(weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if (i < n)
    {
        x[i] = u / weight[i];
    }
    tp = tp + (x[i] * profit[i]);
    printf("\nThe result vector is:\n");
    for (k = 0;k<n;k++)
    {
        if(x[k]!=0.0)
            printf("Item %d : %.3f\n",k+1,x[k]);
    }
    printf("\nTotal profit is : %f\n",tp);
    printf("Item\tValue\tWeight\tP(i)\n");
    for(p=0;p<n;p++)
    {
        printf("%d \t%.2f \t%.2f \t%.2f\n",p+1,profit[p],weight[p],ratio[p]);
    }
    printf("\nItem\tValue\tWeight\tP(i)\n");
    for(p=n-1;p>=0;p--)
    {
        printf("%d \t%.2f \t%.2f \t%.2f\n",p+1,profit[p],weight[p],ratio[p]);
    }
}
int main()
{
    float capacity;
    int num, i, j;
    float temp;
    int p,q;
    printf("\nEnter the no of objects:");
    scanf("%d",&num);

    printf("\nEnter the weights and values of each object:");
    for(i=0;i<num;i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for(i=0;i<num;i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }

        }
    }
    knapsack(num, capacity);
    return 0;
}
