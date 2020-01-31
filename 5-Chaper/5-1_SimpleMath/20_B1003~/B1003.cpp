#include<cstdio>
#include<cstring>

bool judge(char* input) {
	bool flagP, flagT, flagA;
	for(int i = 0; i < strlen(input); i++) {
		if(input[i] == 'P')
			flagP = true;
		else if(input[i] == 'T')
			flagT = true;
		else if(input[i] == 'A')
			flagA = true;
		else
			return false; 
	}
	
	// Make sure the characters only contain 'P' 'T' 'A'
	if(flagP && flagT && flagA) {
		// Find the position of 'P' and 'T'
		int positionT, positionP;
		for(int i = 0; i < strlen(input); i++) {
			if(input[i] == 'P') {
				positionP = i;
				break;
			}
		}
		for(int i = strlen(input) - 1; i >= 0; i--) {
			if(input[i] == 'T') {
				positionT = i;
				break; 
			}
		}
		
		// If something else hides between 'P' and 'T'
		for(int i = positionP + 1; i < positionT; i++) {
			if(input[i] != 'A') {
				return false;
			}
		}
		
		int countAbeforeP = positionP;
		int countAbetweenPT = positionT - positionP - 1;
		int countAafterT = strlen(input) - positionT - 1;
		if(countAbeforeP * countAbetweenPT == countAafterT) {
			return true;
		}
		return false;
	}
	
	return false;
}

int main() {
	
	int number;
	scanf("%d", &number);
	
	char input[101];
	while(number) {
		scanf("%s", input);
		if(judge(input)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		number--;
	}
	
	return 0;
}
