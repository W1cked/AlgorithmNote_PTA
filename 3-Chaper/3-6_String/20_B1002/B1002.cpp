#include<cstdio>
#include<cstring>

int main() {
	
	char str[1000];
	scanf("%s", str);
	
	// Compute the sum
	int sum = 0;
	for(int i = 0; i < strlen(str); i++) {
		sum += str[i] - '0';
	}
	
	// Find the bits
	int bits = 0, number[10] = {0};
	while(sum != 0) {
		number[bits] = sum % 10;
		bits++;
		sum = sum / 10;
	}
	
	// Convert the integer into Character
	char hanzi[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	for(int i = bits - 1; i >= 0; i--) {
		printf("%s", hanzi[number[i]]);
		if(i != 0) {
			printf(" ");
		}
	}

	return 0;
}
