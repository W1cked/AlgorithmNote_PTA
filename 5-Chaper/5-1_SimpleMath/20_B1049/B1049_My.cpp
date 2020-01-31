/*
	This source code will run out of time.
*/
#include<cstdio>

int main() {
	
	int number;
	scanf("%d", &number);
	
	double input[100001];
	for(int i = 0; i < number; i++) {
		scanf("%lf", &input[i]);
	}
	
	double sum = 0;
	for(int i = 0; i < number; i++) {
		int counter = number - i;
		int tempLength = number;
		while(counter) {
			// Do an operation
			for(int j = i; j < tempLength; j++) {
				sum += input[j];
			}
			tempLength--;
			counter--;
		}
	}
	
	printf("%.2f\n", sum);
	
	return 0;
}
