#include<stdio.h>

const int Galleon = 17 * 29;
const int Sickle = 29;

int main() {
	
	int payG, payS, payK;
	int priceG, priceS, priceK;
	scanf("%d.%d.%d %d.%d.%d", &priceG, &priceS, &priceK, &payG, &payS, &payK);
	
	// Convert to the min unit
	int price = ((priceG * 17) + priceS) * 29 + priceK;
	int pay = ((payG * 17) + payS) * 29 + payK;
	int diff = pay - price;
	
	if(diff >= 0) {
		printf("%d.%d.%d\n", diff / (Galleon), (diff / Sickle) % 17, diff % 29);
	}
	else {
		diff = -diff;
		printf("-%d.%d.%d\n", diff / (Galleon), (diff / Sickle) % 17, diff % 29);
	}
	
	return 0;
}
