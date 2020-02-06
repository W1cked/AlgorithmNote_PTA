#include<stdio.h>

int main() {
	
	int N, M;
	scanf("%d%d", &N, &M);
	
	int array[N];
	for(int i = 0; i < N; i++) {
		int index = (M + i) % N;
		scanf("%d", &array[index]);
	}
	
	for(int i = 0; i < N; i++) {
		printf("%d", array[i]);
		if(i != N - 1)
			printf(" ");
	}
	
	return 0;
}
