#include<stdio.h>

int main() 
{
    int n, counter = 0;
    
    scanf("%d", &n);

    if(n == 1) {
        printf("0");
        return 0;
    }

    while(n != 1) {
        if(n % 2 == 0) {
            n = n / 2;
            counter ++;
        }
        else {
            n = 3 * n + 1;
            n = n / 2;
            counter ++;
        }
    }
    
    printf("%d", counter);
    
    return 0;
}
