#include<cstdio>

int main() {
	
	int array[1010] = {0};
	int coef = 0, exp = 0, count = 0;
	
	while(scanf("%d%d", &coef, &exp) != EOF) {
		array[exp] = coef;
	}
	
	array[0] = 0;
	// Traversal from index low to high
	for(int i = 1; i <= 1000; i++) {
		array[i - 1] = array[i] * i;
		array[i] = 0;	// Show the item where exp equal i is finished.
		
		if(array[i - 1] != 0)
			count++;
	}
	if(count == 0) {
		printf("0 0");
	}
	else {
		// Travesal from index high to low
		for(int i = 1000; i >= 0; i--) {
			if(array[i] != 0) {
				printf("%d %d", array[i], i);
				count--;
				
				if(count != 0) {
					printf(" ");	
				}
			}
		}
	}
	
	
	return 0;
}
