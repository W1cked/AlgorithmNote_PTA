#include<cstdio>

int main() {
	
	int N, temp;
	int count[5] = {0};
	int answer[5] = {0};
	
	//Scan and analyze
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		//Deal with A1
		if(temp % 5 == 0) {
			if(temp % 2 == 0) {
				answer[0] += temp;
				count[0]++;
			}
		}
		
		//Deal with A2
		if(temp % 5 == 1) {
			if(count[1] % 2 == 0) {	//Odd index
				answer[1] += temp;
			}
			else {  //Even index
				answer[1] -= temp;
			}
			count[1]++;
		}
		
		//Deal with A3
		if(temp % 5 == 2) {
			answer[2]++;
			count[2]++;
		}
		
		//Deal with A4
		if(temp % 5 == 3) {
			answer[3] += temp;
			count[3]++;
		}
		
		//Deal with A5
		if(temp % 5 == 4) {
			if(temp > answer[4]) {
				answer[4] = temp;
			}
			count[4]++;
		}
		
	}
	
	//analyze and display the result
	if(count[0] == 0) {
		printf("N ");
	}
	else {
		printf("%d ", answer[0]);
	}
	
	if(count[1] == 0) {
		printf("N ");
	}
	else {
		printf("%d ", answer[1]);
	}
	
	if(count[2] == 0) {
		printf("N ");
	}
	else {
		printf("%d ", answer[2]);
	}
	
	if(count[3] == 0) {
		printf("N ");
	}
	else {
		printf("%.1f ", (double)answer[3] / count[3]);
	}
	
	if(count[4] == 0) {
		printf("N");
	}
	else {
		printf("%d", answer[4]);
	}
	
	return 0;
}
