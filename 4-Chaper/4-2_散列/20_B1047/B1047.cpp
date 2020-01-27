#include<cstdio>
#include<cstring>

int main() {
	
	int number;
	scanf("%d", &number);
	
	// Input the data and analyze
	int groupScore[1001] = {0};
	int tempScore = 0, groupID = 0, memberID = 0;
	for(int i = 0; i < number; i++) {
		scanf("%d-%d %d", &groupID, &memberID, &tempScore);
		groupScore[groupID] += tempScore;
	}
	
	// Find the champion and display the result
	int championScore = 0, championIndex = 0;
	for(int i = 0; i < (sizeof(groupScore) / sizeof(int)); i++) {
		if(groupScore[i] > championScore) {
			championScore = groupScore[i];
			championIndex = i;
		}
	}
	printf("%d %d", championIndex, championScore);
	
	
	return 0;
}
