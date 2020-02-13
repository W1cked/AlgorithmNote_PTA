#include<stdio.h>

struct Problem {
	int score;
	int number;
	int correctNum;
	char Item[101];
};

struct Student {
	int itemNumber;
	int correctNum;
	int score;
	
	Student() {
		itemNumber = 0;
		correctNum = 0;
		score = 0;
	}
};

int main() {
	int studentNumber, problemNumber;
	char tempChar;
	scanf("%d%d", &studentNumber, &problemNumber);
	
	Problem problem[problemNumber];
	for(int i = 0; i < problemNumber; i++) {
		scanf("%d%d%d", &problem[i].score, &problem[i].number, &problem[i].correctNum);
		int temp = 0;
		while(temp != problem[i].correctNum) {
			tempChar = getchar();
			if(tempChar >= 'a' && tempChar <= 'z')
				problem[i].Item[temp++] = tempChar;
		}
	}
	
	Student stu[studentNumber];
	for(int k = 0; k < studentNumber; k++) {
		for(int j = 0; j < problemNumber; j++) {
			while((tempChar = getchar()) != ' ') {
				if(tempChar >= '0' && tempChar <= '0') {
					stu[k].itemNumber = tempChar -  '0';
					if(problem[j].correctNum != stu[k].itemNumber) {
						stu[k].score += 0;
						break;
					}
				}
			}
			
			/** Input the item and check the answer */
			for(int i = 0; i < stu[k].itemNumber; i++) {
				while((tempChar = getchar()) != ')') {
					if(tempChar >= 'a' && tempChar <= 'z') {
						bool flag = false;	// Assume this item is wrong
						for(int x = 0; x < problem[j].correctNum; x++) {
							if(tempChar == problem[j].Item[x]) {
								flag = true;
								stu[k].correctNum++;
								break;
							}
						}
						if(flag)
							continue;
						else {
							stu[k].score += 0;
							break;
						}
					}
				}	
			}
			if(stu[k].correctNum == stu[k].itemNumber)
				stu[k].score += problem[j].score;
		}
		printf("%d\n", stu[k].score);
	}
	
	return 0;
}
