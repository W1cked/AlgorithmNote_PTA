#include<stdio.h>

int main() {
	int number;
	scanf("%d", &number);
	
	while(number--) {
		int K;
		scanf("%d", &K);
		
		int N;
		for(N = 1; N < 10; N++) {
			int sqrtNumber = K * K * N;
			int baseFlag;
			for(baseFlag = 1; baseFlag <= K; baseFlag *= 10) {
				if((sqrtNumber / baseFlag) % 10 != (K / baseFlag) % 10) 
					break;
			}
			if(baseFlag > K) {
				printf("%d %d\n", N, sqrtNumber);
				break;
			}
		}
		if(N == 10)
			printf("No\n");
	}
	
	return 0;
}
