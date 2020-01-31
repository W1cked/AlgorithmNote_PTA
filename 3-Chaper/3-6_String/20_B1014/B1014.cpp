#include<cstdio>
#include<cstring>

int main() {
	
	// Input the data
	char str[4][61];
	for(int i = 0; i < 4; i++) {
		scanf("%s", str[i]);
	}
	
	// Find the DAY
	char DAY[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	int i;
	for(i = 0; i < strlen(str[1]); i++) {
		if(str[1][i] == str[0][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
			printf("%s ", DAY[str[1][i] - 'A']);
			break;
		}
	}
	
	// Find the HOUR
	for(i++; i < strlen(str[1]); i++) {
		if(str[1][i] == str[0][i]) {
			if(str[1][i] >= '0' && str[1][i] <= '9') {
				printf("%02d:", str[1][i] - '0');
				break;
			}
			else if(str[1][i] >= 'A' && str[1][i] <= 'N'){
				printf("%02d:", str[1][i] - 'A' + 10);
				break;
			}
		}
	}
	
	// Find the MINUTE
	char tempMM;
	for(int i = 0; i < 60; i++) {
		if(str[2][i] == str[3][i]) {
			if((str[2][i] >= 'A' && str[2][i] <= 'Z') || (str[2][i] >= 'a' && str[2][i] <= 'z')) {
				printf("%02d", i);
				break;
			}	
		}
	}
	
	return 0;
}
