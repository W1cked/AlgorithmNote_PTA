#include<cstdio>

int main()
{
    int num;
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++) {
        long long int A, B, C;
        scanf("%lld%lld%lld", &A, &B, &C);
    
        if(A + B > C) {
            printf("Case #%d: true\n", i + 1);
        }
        else {
            printf("Case #%d: false\n", i + 1);
        }
    }
 
       
    return 0;
}
