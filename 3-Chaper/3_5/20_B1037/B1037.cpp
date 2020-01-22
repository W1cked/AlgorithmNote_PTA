#include<cstdio>

const int Galleon = 17 * 29;
const int Sickle = 29;

int main() {
	// Comvert into Knut and then compute
	int PriceG, PriceS, PriceK;
	int PayG, PayS, PayK;
	scanf("%d.%d.%d", &PriceG, &PriceS, &PriceK);
	scanf("%d.%d.%d", &PayG, &PayS, &PayK);
	
	int Price = PriceG * Galleon + PriceS * Sickle + PriceK;
	int Money = PayG * Galleon + PayS * Sickle + PayK;
	int Change = Money - Price;	

	// Display the result
	if(Change < 0) {
		printf("-");
		Change = -Change;
	}
	printf("%d.%d.%d", Change / Galleon, Change % Galleon / Sickle, Change % Sickle);
	
	
	return 0;
}
