#include<cstdio>

int main() {
	int number;
	int score[110] = {0};
	
	// Input the data and analyze them
	scanf("%d", &number);
	int tempScore;
	for(int i = 0; i < number; i++) {
		scanf("%d", &tempScore);
		score[tempScore]++;
	}
	
	// Input the scores you wanna search
	int searchNumber;
	scanf("%d", &searchNumber);
	for(int i = 0; i < searchNumber; i++) {
		scanf("%d", &tempScore);
		printf("%d", score[tempScore]);
		if(i != searchNumber - 1) {
			printf(" ");
		}
	}
	
	return 0;
}
