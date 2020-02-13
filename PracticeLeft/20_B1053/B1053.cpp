#include<stdio.h>

int main() {
	double number, dayLimit, powerLimit;
	scanf("%lf%lf%lf", &number, &powerLimit, &dayLimit);
	
	int problyEmpty = 0, EMPTY = 0;
	for(int i = 0; i < number; i++) {
		int watchDay;
		scanf("%d", &watchDay);
		
		int problyEmptyCount = 0;
		int EMPTYcount = 0;
		bool emptyFlag = false;
		for(int j = 0; j < watchDay; j++) {
			double temp;
			scanf("%lf", &temp);
			if(temp < powerLimit)  problyEmptyCount++;
		}
		if(problyEmptyCount > watchDay / 2 && watchDay > dayLimit) {
			emptyFlag = true;
			EMPTY++;
		}
		if(problyEmptyCount > watchDay / 2 && emptyFlag == false)  
			problyEmpty++;
	}
	printf("%.1f%c %.1f%c", (problyEmpty / number) * 100, '%', (EMPTY / number) * 100, '%');
	
	return 0;
}
