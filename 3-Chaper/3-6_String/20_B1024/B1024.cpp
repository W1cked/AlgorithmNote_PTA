#include<cstdio>
#include<cstring>

int main() {
	
	char str[10000];
	scanf("%s", str);
	
	// Is it positive or negative?
	if(str[0] == '-') {
		printf("-");
	}
	
	// Find the position of Exp
	int positionE;
	for(int i = 0; i < strlen(str); i++) {
		if(str[i] == 'E') {
			positionE = i;
		}
	}
	
	// Find the value of exp
	int valueExp = 0;
	for(int i = positionE + 2; i < strlen(str); i++) {	// Qin Jiu Shao Algorithm
		valueExp = valueExp * 10 + (str[i] - '0');
	}	
	if(valueExp == 0) {
		for(int i = 1; i < positionE; i++) {
			printf("%c", str[i]);
		}
	}
	
	// Display the resule, aparted by positive notion
	if(str[positionE + 1] == '-') {
		// Display zero
		printf("0.");
		for(int i = 0; i < valueExp - 1; i++) {
			printf("%d", 0);
		}
		
		// Display number
		for(int i = 0; i < positionE; i++) {
			if(str[i] >= '0' && str[i] <= '9') {
				printf("%c", str[i]);
			}
		}
	}
	else {
		// Display number after the '.' moved
		for(int i = 1; i < positionE; i++) { 
			if(str[i] >= '0' && str[i] <= '9') {
				printf("%c", str[i]);
			}
			
			if((i == valueExp + 2) && (valueExp != positionE - 3)) { // Import Line!
				printf(".");
			}
		}
		
		// Displat the zero which is more remained
		for(int i = 0; i < valueExp - (positionE - 3); i++) {
			printf("0");
		}
		
	}
	
	return 0;
}
