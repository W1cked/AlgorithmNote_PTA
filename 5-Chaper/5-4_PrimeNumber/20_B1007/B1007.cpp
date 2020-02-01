#include<cstdio>

bool isPrime(int number) {
	if(number <= 1)
		return false;
	else {
		for(long long int i = 2; i * i <= number; i++) {
			if(number % i == 0) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	
	// Find the prime number table
	int Prime[100000], primeNumber = 0;
	for(int i = 2; i <= 100001; i++) {
		if(isPrime(i)) {
			Prime[primeNumber] = i;
			primeNumber++;
		}
	}
	
	int answerCount = 0;
	for(int i = 0; i <= N; i++) {
		if(Prime[i + 1] - Prime[i] == 2 && Prime[i + 1] <= N) {
			answerCount++;
		}
		if(Prime[i + 1] >= N) {
			break;
		}
	}
	
	printf("%d", answerCount);
	
	return 0;
}
