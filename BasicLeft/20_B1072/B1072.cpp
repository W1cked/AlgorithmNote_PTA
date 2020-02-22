#include<stdio.h>
#include<string.h>

int main() {
	int studentNum, checkNum;
	scanf("%d%d", &studentNum, &checkNum);

	char checkObj[7][5] = {'\0'};
	for (int i = 0; i < checkNum; i++) {
		scanf("%s", &checkObj[i]);
	}

	int problemStuNum = 0, problemObjectNum = 0;
	for (int i = 0; i < studentNum; i++) {
		char stuName[5];
		int stuObjectNum;
		scanf("%s%d", stuName, &stuObjectNum);

		char tempObject[5];
		bool flag = false;
		for (int j = 0; j < stuObjectNum; j++) {
			scanf("%s", tempObject);

			for (int k = 0; k < checkNum; k++) {
				if (flag == false && strcmp(checkObj[k], tempObject) == 0) {
					flag = true;
					problemStuNum++;
					printf("%s:", stuName);
				}
				if (flag && strcmp(checkObj[k], tempObject) == 0) {
					printf(" %s", tempObject);
					problemObjectNum++;
				}
			}
		}
		if (flag)  printf("\n");
	}
	printf("%d %d", problemStuNum, problemObjectNum);

	return 0;
}
