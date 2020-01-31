#include<cstdio>
#include<cstring>

const char PAT[6] = {'P', 'A', 'T', 'e', 's', 't'};

int main() {
	
	char input[10001];
	scanf("%s", input);
	
	int numberPAT[6] = {0};
	int sum = 0;
	for(int i = 0; i < strlen(input); i++) {
		for(int j = 0; j < 6;j ++) {
			if(input[i] == PAT[j]) {
				numberPAT[j]++;
				sum++;
				break;
			}
		}
	}
	
	// Dsiplay the result
	while(sum) {
		for(int i = 0; i < 6; i++) {
			if(numberPAT[i]) {
				putchar(PAT[i]);
				numberPAT[i]--;
				sum--;
			}
		}
	}
	
	return 0;
}
