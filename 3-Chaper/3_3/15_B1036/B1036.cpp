#include<cstdio>

int main() {
	// Input the number and character
	int number;
	char ch;
	scanf("%d %c", &number, &ch);
	
	// Number is odd or even
	int col = number;
	int row = 0;
	if(number % 2 == 0) {
		row = number / 2;
	}
	else {
		row = number / 2 + 1;
	}
	
	// Display row 1
	for(int i = 0; i < col; i++) {
		printf("%c", ch);
	}
	printf("\n");
	
	// Display row 2 ~ (row - 1)
	for(int i = 1; i <= row - 2; i++) {
		for(int j = 1; j <= col; j++) {
			if(j == 1 || j == col)
				printf("%c", ch);
			else 
				printf(" ");
		}
		printf("\n");
	}
	
	// Display row end
	for(int i = 0; i < col; i++) {
		printf("%c", ch);
	}
	printf("\n");
	
	return 0;
}
