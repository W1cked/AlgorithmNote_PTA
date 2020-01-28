#include<cstdio>

int Fibonacci(int number) {
    if(number == 0 || number == 1) {
        return 1;
    }
    else {
        return Fibonacci(number - 1) + Fibonacci(number - 2);
    }
}

int main() {
    int number;
    printf("Enter a number and we calculate its fibonacci: ");
    scanf("%d", &number);
    
    printf("Fibonacii(%d) = %d\n", number, Fibonacci(number));
    
    return 0;
}
