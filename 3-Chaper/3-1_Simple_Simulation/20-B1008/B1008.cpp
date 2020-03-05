#include<cstdio>
#include<cstdlib>

int* move(int* arr, int num, int moveBit) {
	int* end = (int*)malloc(sizeof(int) * num);
	
	int count = 0;
	for(int i = 0; i < num; i++) {
		count = (i + moveBit) % num;
		end[count] = arr[i];
	}
	
	return end;
}

int main() {
	
	int num, moveBit;
	scanf("%d%d", &num, &moveBit);
	
	int* arr = (int*)malloc(sizeof(int) * num);
	for(int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	
	int* end = move(arr, num, moveBit);
	
	for(int i = 0; i < num - 1; i++) {
		printf("%d ", end[i]);
	}
	printf("%d", end[num - 1]);
	
	return 0;
}
