#include<cstdio>
#include<cstring>

const char oddBit[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main() {
	char strA[101], strB[101];
	scanf("%s %s", strA, strB);
	
	// Find the length of each string
	int lengthA = strlen(strA);
	int lengthB = strlen(strB);
	int lengthMAX = lengthA > lengthB ? lengthA : lengthB;
	
	for(int i = 0; i < lengthMAX; i++) {
		// Deal with the problem about zero
		int valueA = lengthA + i - lengthMAX;
		int valueB = lengthB + i - lengthMAX;
		
		if(valueA < 0) {
			valueA = 0;
		}
		else {
			valueA = strA[lengthA + i - lengthMAX] - '0';
		}
		if(valueB < 0) {
			valueB = 0;
		}
		else {
			valueB = strB[lengthB + i - lengthMAX] - '0';
		}
		
		// Display the result
		if((lengthMAX - i) % 2 != 0) {	// Odd bits
			putchar(oddBit[(valueA + valueB) % 13]);
		}
		else {	// Even bits
			putchar((valueB - valueA + 10 ) % 10 + '0');
		}
	}
	
	return 0;
}
