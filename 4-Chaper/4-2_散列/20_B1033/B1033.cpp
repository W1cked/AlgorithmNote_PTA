#include<cstdio>
#include<cstring>

int main() {
	int keyboard[256] = {0};
	char tempChar;
	while((tempChar = getchar()) != '\n') {
		if(tempChar >= 'A' && tempChar <= 'Z') {
			keyboard[tempChar - 'A' + 'a'] = 1;		// The lowerCase key is broken
		}
		keyboard[tempChar] = 1;		// The upperCase key is broken
	}
	
	if(keyboard['+']) {     // All the upperCase keys are broken
		for(int i = 'A'; i < 'Z'; i++) {
			keyboard[i] = 1;
		}
	}
	
	// Display the result
	while((tempChar = getchar()) != '\n') {
		if(keyboard[tempChar]) {
			continue;
		}
		putchar(tempChar);
	}

	return 0;
}

