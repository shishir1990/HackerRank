#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check_max(int prev, int curr, int k)
{
    if(curr < k)
        return (curr > prev ? curr : prev);
    else
        return prev;
}

void calculate_the_maximum(int n, int k) {
    int i,j, max_and = 0, max_or = 0, max_xor = 0, temp;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n;j++)
        {
            temp = i & j;
            max_and = check_max(max_and, temp, k);
            temp = i | j;
            max_or = check_max(max_or, temp, k);
            temp = i ^ j;
            max_xor = check_max(max_xor, temp, k);
        }
    }
    printf("%d\n%d\n%d\n", max_and, max_or, max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}