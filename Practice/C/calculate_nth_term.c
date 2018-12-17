#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
int *arr;
int recursion(int i, int n)
{
  if (i < n) {
      recursion(i+1, n);
  }
  return (arr[n - 1] + arr[n - 2] + arr[n - 3]);
}

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
  arr = (int *) malloc (sizeof(int)* n);
  arr[0] = a; arr[1] = b; arr[2] = c;
  recursion(3,n);
  return arr[n];
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}