#include<cstdio>
#include<iostream>
using namespace std;

int change(char ch) {
	if(ch == 'B') {
		return 0;
	} 
	else if(ch == 'C') {
		return 1;
	}
	else 
		return 2;
}

int main() {
	
	//Inpute the number
	int N;
	scanf("%d", &N);
	
	char mp[3] = {'B', 'C', 'J'}; //0_B, 1_C, 2_J
	int flagA[3] = {0};
	int flagB[3] = {0};		//0_Win 1_Lose 2_Fair
	int handA[3] = {0};
	int handB[3] = {0};		//Hand win
	
	char A, B;
	for(int i = 0; i < N; i++) {
		cin >> A >> B;
		int a = change(A);
		int b = change(B);
		
		if((a + 1) % 3 == b) {	//A win
			flagA[0]++;
			flagB[1]++;
			handA[a]++;
		}
		else if(a == b) {		//Fair
			flagA[2]++;
			flagB[2]++;
		}
		else {		//B win
			flagA[1]++;
			flagB[0]++;
			handB[b]++;
		}
	}
	
	//Display the result
	printf("%d %d %d\n", flagA[0], flagA[2], flagA[1]);
	printf("%d %d %d\n", flagB[0], flagB[2], flagB[1]);
	
	//Find the most win hand
	int ia = 0, ib = 0;
	for(int i = 0; i < 3; i++) {
		if(handA[i] > handA[ia]) {
			ia = i;
		}
		if(handB[i] > handB[ia]) {
			ib = i;
		}
	}
	printf("%c %c", mp[ia], mp[ib]);
	
	return 0;
}
