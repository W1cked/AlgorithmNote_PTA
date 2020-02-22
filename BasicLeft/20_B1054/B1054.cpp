#include<stdio.h>
#include<string.h>

int main() {
	int totalNumber;
	scanf("%d",&totalNumber);
	
	char input[50], numToString[50];
	double temp, sum = 0;
	int vaildNumber = 0;
	for(int i = 0; i < totalNumber; i++) {
		scanf("%s", input);
		sscanf(input, "%lf", &temp);
		sprintf(numToString, "%.2f", temp);
		
		bool invaildFlag = false;
		for(int j = 0; j < strlen(input); j++) {
			if(input[j] != numToString[j])	invaildFlag = true;
		}
		if(invaildFlag || (temp > 1000) || (temp < -1000)) {
			printf("ERROR: %s is not a legal number\n", input);
			continue;
		}
		else {
			sum += temp;
			vaildNumber++;
		}
	}
	if(vaildNumber == 1)  printf("The average of 1 number is %.2f\n", sum / vaildNumber);
	else if(vaildNumber > 1) {
		printf("The average of %d numbers is %.2f\n", vaildNumber, sum / vaildNumber);
	}
	else {
		printf("The average of %d numbers is Undefined\n", vaildNumber);
	}
	
	return 0;
}
