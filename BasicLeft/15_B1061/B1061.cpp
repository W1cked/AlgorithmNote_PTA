#include<stdio.h>

int main() {
	
	int studentNum, problemNum;
	scanf("%d%d\n", &studentNum, &problemNum);
	
	int problemScore[problemNum] = {0};
	for(int i = 0; i < problemNum; i++) {
		scanf("%d", &problemScore[i]);
	}
	int problemAns[problemNum] = {0};
	for(int i = 0; i < problemNum; i++) {
		scanf("%d", &problemAns[i]);
	}
	
	for(int i = 0; i < studentNum; i++) {
		int sum = 0;
		for(int j = 0; j < problemNum; j++) {
			int temp;
			scanf("%d", &temp);
			if(temp == problemAns[j]) {
				sum += problemScore[j];
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
