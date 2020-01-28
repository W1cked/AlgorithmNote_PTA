#include<cstdio>

int main() {
	int number[10] = {0};
	for(int i = 0; i < 10; i++) {
		scanf("%d", &number[i]);
	}
	
	// Display a min number but not zero
	for(int i = 1; i < 10; i++) {
		if(number[i] != 0) {
			printf("%d", i);
			number[i]--;
			break;
		}
	}
	
	// Display the remain number from min to max
	for(int i = 0; i < 10; i++) {
		if(number[i] != 0) {
			while(number[i]) {
				printf("%d", i);
				number[i]--;
			}
		}
	}
	
	return 0;
}
