#include<cstdio>

bool isPrime(int number) {
	if(number <= 1) {
		return false;
	}
	for(long long int i = 2; i * i <= number; i++) {
		if(number % i == 0)
			return false;
	}
	return true;
}

int main() {
	
	int M, N;
	scanf("%d%d", &M, &N);
	
	int counter = 0, nextLine = 0;
	for(int i = 1; i < 1000000; i++) {	// The i is very big!
		if(isPrime(i)) {
			counter++;
		}
		
		if(counter >= M && counter <= N && isPrime(i)) {
			nextLine++;
			printf("%d", i);
			
			if(nextLine % 10 != 0 && counter != N) {
				printf(" ");
			}
			if(nextLine % 10 == 0) {
				printf("\n");
			}
		}
		
		if(counter > N) {
			break;
		}
	}
	
	return 0;
}
