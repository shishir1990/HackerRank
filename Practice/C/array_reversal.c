#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i, median, temp;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    median = (num%2 == 0? (num/2)-1: (num/2));

    for(i = 0; i <= median; i++) {
        temp = arr[i];
        arr[i]=arr[num-1-i];
        arr[num-1-i] = temp;
    }
    /* Write the logic to reverse the array. */

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}

