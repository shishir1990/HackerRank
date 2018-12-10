#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n, i, j;
    scanf("%d", &n);
    
    for(i=n; i>0; i--)
    {
        for(j=n; j>i; j--)
            printf("%d ", j);
        for(j=0; j<(2*i-1); j++)
            printf("%d ", i);
        for(j=i; j<n ;j++)
            printf("%d ", j+1);
        printf("\n");
    }

    for (i=1;i<n;i++)
    {
        for(j=n;j>i;j--)
            printf("%d ", j);
        for(j=0;j<(2*i-1);j++)
            printf("%d ", i+1);
        for(j=i;j<n;j++)
            printf("%d ", j+1);
        printf("\n");
    }

    return 0;
}