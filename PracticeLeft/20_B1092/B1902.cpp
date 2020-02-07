#include<stdio.h>

const int KIND = 1001;
const int CITY = 101;

int main() {
	
	int cityNumber, kindNumber;
	scanf("%d%d", &kindNumber, &cityNumber);
	
	// Input the data
	int mooncake[CITY][KIND] = {0};
	for(int i = 0; i < cityNumber; i++) {
		for(int j = 0; j < kindNumber; j++) {
			scanf("%d", &mooncake[i][j]);
		}
	}
	
	// Traversal and compute the max
	int saleCounter[KIND] = {0};
	for(int j = 0; j < kindNumber; j++) {
		for(int i = 0; i < cityNumber; i++) {
			saleCounter[j] += mooncake[i][j];
		}
	}
	int MAX = 0;
	for(int i = 0; i < kindNumber; i++) {
		if(saleCounter[i] > MAX) {
			MAX = saleCounter[i];
		}
	}
	
	int championCount = 0;
	for(int i = 0; i < kindNumber; i++) {
		if(MAX == saleCounter[i]) {
			championCount++;
		}
	}
	
	// Display the result
	printf("%d\n", MAX);
	for(int i = 0; i < kindNumber; i++) {
		if(saleCounter[i] == MAX) {
			printf("%d", i + 1);
			if(i != kindNumber - 1 && championCount > 1)
				printf(" "); 
		}
	}
	
	return 0;
}
