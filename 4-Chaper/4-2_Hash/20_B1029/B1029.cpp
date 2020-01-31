#include<cstdio>
#include<cstring>

int main() {
	
	char input[81];
	char inputActual[81];
	bool output[128] = {false};
	scanf("%s", input);
	scanf("%s", inputActual);
	
	for(int i = 0; i < strlen(input); i++) {
		int j;
		char cInput, cInputActual;
		for(j = 0; j < strlen(inputActual); j++) {
			cInput = input[i];
			cInputActual = inputActual[j];
			if(cInput >= 'a' && cInput <= 'z') {
				cInput = cInput - 32;	// Convert to the upper case
			}
			if(cInputActual >= 'a' && cInputActual <= 'z') {
				cInputActual -= 32;		// Convert to the upper case
			}
			if(cInput == cInputActual) {
				break;
			}
		}
		if(j == strlen(inputActual) && output[cInput] == false) {
			putchar(cInput);
			output[cInput] = true;
		}
	}
	
	return 0;
}
