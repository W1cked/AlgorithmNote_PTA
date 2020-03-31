#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int sum = 0, before = -1, counter = 0;
    for(int i = 1; i <= n; i++) {
        sum = (i / 2) + (i / 3) + (i / 5);
        if(sum > before) counter++;
        before = sum;
    }
    printf("%d\n", counter);

    return 0;
}
