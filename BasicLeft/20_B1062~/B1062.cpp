#include<cstdio>
#include<algorithm>
using namespace std;

struct Fraction {
	int up;
	int down;
};

int compare(Fraction ref, Fraction input) {
	Fraction reference, refInput;
	reference.up = ref.up * input.down;
	refInput.up = input.up * ref.down;
	
	if(reference.up > refInput.up)	return 666;
	else if(reference.up == refInput.up)  return 0;
	else  return -666;
}

int gcd(int m, int n) {
	if(m < n) {
		int temp = m;
		m = n;
		n = temp;
	}
	if(n == 0) return m;
	else return gcd(n, m % n);
}

int main() {
	Fraction fra1, fra2, answer;
	scanf("%d/%d %d/%d %d", &fra1.up, &fra1.down, &fra2.up, &fra2.down, &answer.down);
	
	/** Find out who is bigger and who is smaller */
	if(compare(fra1, fra2) > 0) {	// We think that fra2 is bigger
		swap(fra1.up, fra2.up);
		swap(fra1.down, fra2.down);
	}
	
	Fraction small, big;
	big.down = small.down = fra1.down * fra2.down;
	big.up = fra2.up * fra1.down;
	small.up = fra1.up * fra2.down;
	
	/** Find the length of answer */
	int length = 0;
	for(int i = 1; i <= answer.down; i++) {
		answer.up = i;
		if(compare(big, answer) > 0 && compare(small, answer) < 0 && gcd(answer.down, i) == 1)
			length++;
	}
	
	/** Display the result */
	bool spaceFlag = false;
	for(int i = 1; i <= answer.down; i++) {
		answer.up = i;
		if(compare(big, answer) > 0 && compare(small, answer) < 0 && gcd(answer.down, i) == 1) {
			printf("%s%d/%d", spaceFlag == true ? " " : "", i, answer.down);
			spaceFlag = true;
		}
	}

	return 0;
}
