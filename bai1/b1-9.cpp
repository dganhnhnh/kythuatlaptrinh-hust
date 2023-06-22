#include <stdio.h>
#include <stdlib.h>
int n;
int *a;

void printSubArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                printf("%d ", *(a + k));
            // printf("\n%d %d",i,j);
            if(i <= j && i!= n-1) printf("\n");
        }
    }
}

int main()
{
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", (a + i));

    // for (int i = 0; i < n; i++)
    //     printf("%d ", *(a + i));
    printSubArray(a, n);
    return 0;
}