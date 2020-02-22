#include<cstdio>
#include<cstring>

int main() {
	char flag = getchar();
	getchar();	// Absort the '\n'
	char input[1001];
	scanf("%[^\n]s", input);
	
	if(flag == 'C') {
		int letterCount = 0;
		for(int i = 0; i < strlen(input); i++) {
			if(input[i] != input[i + 1] && letterCount == 0)
				putchar(input[i]);
			else if(input[i] == ' ' && input[i + 1] != ' ' && letterCount > 0) { 
				printf("%d ", letterCount + 1);
				letterCount = 0;
			}
			else if(input[i] != input[i + 1] && letterCount > 0) {
				printf("%d%c", letterCount + 1, input[i]);
				letterCount = 0;
			}
			else
				letterCount++;
		}
	}
	else {
		for(int i = 0; i < strlen(input); i++) {
			if(input[i] >= '0' && input[i] <= '9') {
				int count = input[i] - '0';
				while(input[i + 1] >= '0' && input[i + 1] <= '9') {
					count = count * 10 + input[i + 1] - '0';
					i++;
				}
				while(count--) {
					putchar(input[i + 1]);
				}
				i++;
			}
			else
				putchar(input[i]);
		}
	}
	return 0;
}
