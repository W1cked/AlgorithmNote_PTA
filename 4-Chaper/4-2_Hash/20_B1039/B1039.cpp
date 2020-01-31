#include<cstdio>
#include<cstring>

int main() {
	char stringShop[1001];
	char stringBuy[1001];
	
	// Input the data and analyze them
	scanf("%s", stringShop);
	scanf("%s", stringBuy);
	
	int color[128] = {0};
	for(int i = 0; i < strlen(stringShop); i++) {
		color[stringShop[i]]++;
	}
	
	int counter = 0;
	for(int i = 0; i < strlen(stringBuy); i++) {
		color[stringBuy[i]]--;
		if(color[stringBuy[i]] < 0) {
			counter++;
		}
	}
	
	if(counter != 0) {
		printf("No %d", counter);
	}
	else {
		printf("Yes %d", strlen(stringShop) - strlen(stringBuy));
	}
	
	return 0;
}
