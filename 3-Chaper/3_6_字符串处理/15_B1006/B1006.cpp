#include<cstdio>

int main() {
	
	// Input the data
	int number;
	scanf("%d", &number);
	
	// Partition
	int B = 0, S = 0, G = 0;
	B = number / 100 % 10;
	S = number / 10 % 10;
	G = number % 10;
	
	// Display the result
	for(int i = 0; i < B; i++) {
		printf("B");
	}
	for(int i = 0; i < S; i++) {
		printf("S");
	}
	for(int i = 1; i <= G; i++) {
		printf("%d", i);
	}
	
	return 0;
}
