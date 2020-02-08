#include<stdio.h>

int main() {
	int row, col, begin, end, value;
	scanf("%d%d%d%d%d\n", &row, &col, &begin, &end, &value);
	
	for(int i = 0; i < row; i++) {
		int temp;
		for(int j = 0; j < col; j++) {
			scanf("%d", &temp);
			
			if(temp >= begin && temp <= end) {
				printf("%03d", value);
				if(j != col - 1)
					printf(" ");
			}
			else {
				printf("%03d", temp);
				if(j != col - 1)
					printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
