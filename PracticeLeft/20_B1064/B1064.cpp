#include<cstdio>
#include<cstring>

int main() {
	int number;
	scanf("%d", &number);
	
	int Friend[99999] = {0};
	for(int i = 0; i < number; i++) {
		char input[10001];
		scanf("%s", input);
		
		int sum = 0;
		for(int i = 0; i < strlen(input); i++) {
			sum += input[i] - '0';
		}
		Friend[sum]++;
	}
	
	int counter = 0;
	for(int i = 0; i < 99999; i++) {
		if(Friend[i] != 0)
			counter++;
	}
	printf("%d\n", counter);
	
	bool spaceFlag = false;
	for(int i = 0; i < 99999; i++) {
		if(Friend[i] != 0) {
			printf("%s%d", spaceFlag == true ? " " : "", i);
			spaceFlag = true;
		}
	}
	
	return 0;
}
