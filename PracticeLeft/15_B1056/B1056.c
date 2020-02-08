#include<stdio.h>

int main() {
	int number;
	scanf("%d", &number);
	int sum = 0;
	for(int i = 0; i < number; i++) {
		int temp;
		scanf("%d", &temp);
		sum += temp * (number - 1) * 10 + temp * (number - 1);
	}
	printf("%d", sum);
	return 0;	
}
