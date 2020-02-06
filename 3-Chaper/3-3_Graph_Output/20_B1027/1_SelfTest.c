#include<stdio.h>
#include<math.h>

int main() {
	
	int number;
	char character;
	scanf("%d %c", &number, &character);
	
	int MAXbottom = (int)sqrt(2.0 * (number + 1)) - 1;
	if(MAXbottom % 2 == 0)
		MAXbottom--;
	
	int usedCount = 0;
	// Display up triangle
	for(int currentBottom = MAXbottom; currentBottom > 0; currentBottom -= 2) {
		// Display space
		for(int i = 0; i < (MAXbottom - currentBottom) / 2; i++) {
			printf(" ");
		}
		
		// Display character
		for(int i = 0; i < currentBottom; i++) {
			putchar(character);
			usedCount++;
		}
		printf("\n");
	}
	
	// Display down triangle
	for(int currentBottom = 3; currentBottom <= MAXbottom; currentBottom += 2) {
		for(int i = (MAXbottom - currentBottom) / 2; i > 0; i--) {
			printf(" ");
		}
			
		for(int i = 0; i < currentBottom; i++) {
			putchar(character);
			usedCount++;
		}
		printf("\n");
	}
	printf("%d", number - usedCount);
	
	return 0;
}
