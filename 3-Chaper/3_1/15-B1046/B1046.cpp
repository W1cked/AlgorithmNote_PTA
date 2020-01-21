#include<cstdio>

int main() {
	
	int round;
	scanf("%d", &round);
	
	int Asay[101], Ado[101];
	int Bsay[101], Bdo[101];
	for(int i = 1; i <= round; i++) {
		scanf("%d%d%d%d", &Asay[i], &Ado[i], &Bsay[i], &Bdo[i]);
	}
	
	int Adrink = 0, Bdrink = 0;
	for(int i = 1; i <= round; i++) {
		if(Ado[i] == Asay[i] + Bsay[i] && Bdo[i] == Asay[i] + Bsay[i]) {
			continue;
		}
		if(Ado[i] == Asay[i] + Bsay[i]) {
			Bdrink++;
		}
		if(Bdo[i] == Asay[i] + Bsay[i]) {
			Adrink++;
		}
	}
	
	printf("%d %d", Adrink, Bdrink);
	
	return 0;
}
