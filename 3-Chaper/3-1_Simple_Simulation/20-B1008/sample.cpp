#include<cstdio>

int main() {
    int a[110];
    int n, m, count = 0;    //记录已是输出数的个数
    scanf("%d%d", &n, &m);

    m = m % n;      //修正m
    for(int i = 0 ; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = n - m; i < n; i++) {    //输出 n - m 号到 n - 1 号
        printf("%d", a[i]);
        count++;
        if(count < n) {
            printf(" ");
        }
    }
    for(int i = 0; i < n - m; i++) {
        printf("%d", a[i]);
        count++;
        if(count < n) {
            printf(" ");
        }
    }
    
    return 0;
}
