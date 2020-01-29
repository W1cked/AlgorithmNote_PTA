#include<cstdio>
#include<algorithm>
using namespace std;

void Display(int* array, int number) {
	for(int i = 0; i < number; i++) {
		printf("%d", array[i]);
		if(i != number - 1) {
			printf(" ");
		}
	}
}

bool isSame(int* origin, int* halfSort, int number) {
	for(int i = 0; i < number; i++) {
		if(origin[i] != halfSort[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int number;
	scanf("%d", &number);
	
	int origin[101];
	for(int i = 0; i < number; i++) {
		scanf("%d", &origin[i]);
	}
	int halfSort[101];
	for(int i = 0; i < number; i++) {
		scanf("%d", &halfSort[i]);
	}
	
	// If it is insertion sort, return length; otherwise return 0
	int length = 0, i = 0;
	while(i < number && halfSort[i] <= halfSort[i + 1]) {
		i++;
	}
	length = i + 1;
	while(i < number && halfSort[i + 1] == origin[i + 1]) {
		i++;
	}
	if(i != number - 1) {
		length = 0;
	}
	else {
		length += 1;
	}
	
	// Finish the sort and display them
	if(length) {	// insertion sort
		puts("Insertion Sort");
		sort(halfSort, halfSort + length);
		Display(halfSort, number);
		return 0;
	}
	else {			// merge sort
		puts("Merge Sort");
		bool flag = false;
		for(int step = 2; step / 2 <= number; step *= 2) {
			if(step != 2 && isSame(origin, halfSort, number)) {
				flag = true;
			}
			for(int i = 0; i < number; i += step) {
				sort(origin + i, origin + min(i + step, number));
			}
			if(flag == true) {
				Display(origin, number);
				return 0;
			}
		}
	}
	
}
