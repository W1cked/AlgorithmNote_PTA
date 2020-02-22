#include<stdio.h>

int main() {
	int tokens, times;
	scanf("%d%d", &tokens, &times);
	
	for(int i = 0; i < times; i++) {
		int number1, number2, pay, judge;
		scanf("%d%d%d%d", &number1, &judge, &pay, &number2);	
		
		if(tokens >= pay) {
			if((number1 < number2 && judge == 1) || 
				(number1 > number2 && judge == 0)) {
				tokens += pay;
				printf("Win %d!  Total = %d.\n", pay, tokens);
			}
			else {
				tokens -= pay;
				printf("Lose %d.  Total = %d.\n", pay, tokens);
				if(tokens <= 0) {
					printf("Game Over.\n");
					break;
				}
			}
		}
		else {
			printf("Not enough tokens.  Total = %d.\n", tokens);
		}
	}
	
	return 0;
}
