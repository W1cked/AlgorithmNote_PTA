#include<cstdio>
#include<cstring>

const int MOD = 1000000007;

int main() {
	
	// Input the data
	char input[100001];
	scanf("%s", input);
	
	// Analyze the data
	int countP = 0, countA = 0, countT = 0;
	int sum = 0;
	for(int i = 0; i < strlen(input); i++) {
		if(input[i] == 'T') {
			countT++;
		}
	}
	for(int i = 0; i < strlen(input); i++) {
		if(input[i] == 'P') {
			countP++;
		}
		if(input[i] == 'T') {
			countT--;
		}
		if(input[i] == 'A') {
			sum = (sum + countP * countT) % MOD; 
		}
	}
	
	printf("%d", sum);
	
	return 0;
} 
