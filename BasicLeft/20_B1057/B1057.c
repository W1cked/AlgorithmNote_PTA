#include<stdio.h>

int main() {
	char input;
	int sum = 0;
	while((input = getchar()) != '\n') {
		if(input >= 'a' && input <= 'z')
			sum += input - 'a' + 1; 
		else if(input >= 'A' && input <= 'Z')
			sum += input - 'A' + 1;
	}
	
	int zero = 0, one = 0;
	while(sum) {
		int temp = sum % 2;
		if(temp == 1)  one += 1;
		else  zero += 1;
		sum /= 2;	
	}
	printf("%d %d", zero, one);
	
	return 0;
}
