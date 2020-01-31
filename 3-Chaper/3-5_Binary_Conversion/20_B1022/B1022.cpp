#include<cstdio>

int main() {
	
	int A, B;
	int D;
	scanf("%d%d%d", &A, &B, &D);
	
	int sumDecimal = A + B;
	
	// Convert the sumDecimal into D digit number
	int ans[31], num = 0;
	do {
        ans[num] = sumDecimal % D;
        sumDecimal /= D;
        num++;
    }while(sumDecimal != 0);
	
	for(int i = num - 1; i >= 0; i--) {
		printf("%d", ans[i]);
	}
	
	return 0;
}
