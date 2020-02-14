#include<cstdio>
#include<cstring>

struct Problem {
	int itemNum;
	int score;
	int correctNum;
	char answer[6];
	Problem() {
		for (int i = 0; i < 6; i++)
			answer[i] = { '\0' };
	}
};

struct Student {
	int score;
	int itemNum;
	int correctNum;
	Student() {
		score = 0;
		itemNum = 0;
		correctNum = 0;
	}
};

int main() {
	int stuNum, problemNum;
	scanf("%d%d", &stuNum, &problemNum);

	/** Read the problem information */
	Problem* pro = new Problem[problemNum];
	for (int i = 0; i < problemNum; i++) {
		scanf("%d%d%d", &pro[i].score, &pro[i].itemNum, &pro[i].correctNum);

		int temp = 0;
		while (temp != pro[i].correctNum)
			scanf(" %c", &pro[i].answer[temp++]);
	}

	int* statistics = new int[problemNum];
	for (int i = 0; i < problemNum; i++) {	/* Initialize the statistics array */
		statistics[i] = 0;
	}

	/** Read the student information */
	Student* stu = new Student[stuNum];
	int wrongCounter = 0;
	for (int i = 0; i < stuNum; i++) {
		char stuAns[10001] = {'\0'};
		getchar();					/* Absort the '\n' */
		scanf("%[^\n]", stuAns);
		
		for (int j = 0; j < problemNum; j++) {
			stu[i].itemNum = 0;
			stu[i].correctNum = 0;
			sscanf(stuAns, "(%d", &stu[i].itemNum);
			if (stu[i].itemNum != pro[j].correctNum) {
				stu[i].score += 0;
				statistics[j]++;
				wrongCounter++;
				continue;
			}

			char stuItem[101] = {'\0'};	/* Read the student's each item */
			sscanf(stuAns, "%[^')']", stuItem);
			for (int k = 0; k < strlen(stuItem); k++) {
				if (stuItem[k] >= 'a' && stuItem[k] <= 'z') {
					for (int x = 0; x < pro[j].correctNum; x++) {
						if (stuItem[k] == pro[j].answer[x]) {
							stu[i].correctNum++;
							break;
						}
					}
				}
			}
			strcpy(stuAns, stuAns + (stu[i].itemNum * 2 + 4));    /* Pointer move right to next problem */
			if (stu[i].correctNum == pro[j].correctNum)
				stu[i].score += pro[j].score;
			else {
				stu[i].score += 0;
				statistics[j]++;
				wrongCounter++;
			}
		}
		printf("%d\n", stu[i].score);
	}

	int MAX = 0;
	for (int i = 0; i < problemNum; i++) {
		if (statistics[i] > MAX)  MAX = statistics[i];
	}
	
	if (wrongCounter) {
		printf("%d", MAX);
		for (int i = 0; i < problemNum; i++)
			if (statistics[i] == MAX)  printf(" %d", i + 1);
	}
	else
		printf("Too simple\n");

	delete[] pro;
	delete[] stu;
	return 0;
}
