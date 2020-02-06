#include<stdio.h>
#include<stdbool.h>

bool isPrime(int N) {
	if(N <= 1)
		return false;
	else {
		for(long long int i = 2; i * i <= N; i++) {
			if(N % i == 0)
				return false;
		}
		return true;
	} 
}

int main() {
	
	int number;
	scanf("%d", &number);
	
	int PrimeCounter = 0;
	int primeNumber[100001];
	for(int i = 0; i <= number; i++) {
		if(isPrime(i)) {
			primeNumber[PrimeCounter++] = i;
		}
	}
	
	int answerCounter = 0;
	for(int i = 0; i < PrimeCounter; i++) {
		if((i + 1) <= PrimeCounter && primeNumber[i + 1] - primeNumber[i] == 2) {
			answerCounter++;
		}
	}
	
	printf("%d", answerCounter);
	
	return 0;
}
