#include<cstdio>
#include<cmath>

int main() {
	int Number;
	char ch;
	scanf("%d %c", &Number, &ch);
	
	// Compute the number
	int MAXbottom = (int)sqrt(2.0 * (Number + 1)) - 1;
	if(MAXbottom % 2 == 0) {
		MAXbottom--;
	}
	int used = (MAXbottom + 1) * (MAXbottom + 1) / 2 - 1;
	
	// Display the UP Triangle
	for(int currentCharNumber = MAXbottom; currentCharNumber > 0; currentCharNumber -= 2) {
		// Display SPACE
		for(int i = 0; i < (MAXbottom - currentCharNumber) / 2; i++) {
			printf(" ");
		}
		
		// Display Character
		for(int j = 0; j < currentCharNumber; j++) {
			printf("%c", ch);
		}
		
		printf("\n");
	}
	
	// Display the DOWN Triangle
	for(int currentCharNumber = 3; currentCharNumber <= MAXbottom; currentCharNumber += 2) {
		// Display SPACE
		for(int i = (MAXbottom - currentCharNumber) / 2; i > 0; i--) {
			printf(" ");
		}
		
		// Display Character
		for(int j = 0; j < currentCharNumber; j++) {
			printf("%c", ch);
		}
		printf("\n");
	}
	printf("%d\n", Number - used);
	
	return 0;
}
