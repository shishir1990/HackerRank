#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s, w[10];
    int i,j;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    for(i=0, j=0;i<=strlen(s);i++, j++)
    {
        if(s[i] == ' ' || s[i] == '\0')
        {
            w[j] = '\0';
            printf("%s\n", w);
            j = -1;
        }
        else
            w[j] = s[i];
    }
    return 0;
}