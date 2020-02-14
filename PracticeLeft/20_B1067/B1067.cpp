#include<stdio.h>
#include<string.h>

int main() {
	int tryTimes;
	char correctPasswd[21] = {'\0'};
	scanf("%s%d", correctPasswd, &tryTimes);
	
	for(int i = 0; i < tryTimes; i++) {
		char input[1001] = {'\0'};
        getchar();      /* Absort the '\n' */
		scanf("%[^\n]s", input);
		
        if(strcmp(input, "#") == 0) {
            return 0;
        }
		if(strcmp(input, correctPasswd) == 0) {
			printf("Welcome in\n");
			return 0;
		}
		else {
			printf("Wrong password: %s\n", input);
		}
	}
    printf("Account locked\n");
	
	return 0;
}
