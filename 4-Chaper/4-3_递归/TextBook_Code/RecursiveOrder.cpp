#include<cstdio>

int Order(int n) {
    if(n == 0) {
        return 1;
    }
    else 
        return Order(n - 1) * n;
}

int main() {
    int number;

    printf("Enter a number and we calculate its order: ");
    scanf("%d", &number);
    printf("%d! = %d\n", number, Order(number));

    return 0;
}
