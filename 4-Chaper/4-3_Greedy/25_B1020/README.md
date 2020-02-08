# B1020月饼

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

### 输入格式：

每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 *N* 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 *D* 表示市场最大需求量。随后一行给出 *N* 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 *N* 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

### 输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。

### 输入样例：

```in
3 20
18 15 10
75 72 45
```

### 输出样例：

```out
94.50
```

---

## 思路

1. 总是选择单价最高的月饼，由此获得最大利润
   - 由 **库存量** 和 **总销售价** 来计算月饼单价
   - 把月饼单价由 高到低 排序
2. 从单价高的月饼开始枚举
   1. 如果 库存量 < 需求量，则该类月饼全卖掉；此时 需求量 = 需求量 - 该类月饼库存量，收益值 += 该类月饼总销售量
   2. 如果 库存量 > 需求量，则要多少给多少；此时 收益值 = 需求量 * 月饼单价，而后需求量减为0

---

## 代码

```cpp
#include<cstdio>
#include<algorithm>
using namespace std;

struct mooncake {
	double store;
	double price;
	double totalSell;
}cake[1001];

bool cmp(mooncake a, mooncake b) {
	return a.price > b.price;
}

int main() {
	int number;
	double needNumber;
	scanf("%d %lf", &number, &needNumber);
	
	// Input the data
	for(int i = 0; i < number; i++) {
		scanf("%lf", &cake[i].store);
	}
	for(int i = 0; i < number; i++) {
		scanf("%lf", &cake[i].totalSell);
		cake[i].price = cake[i].totalSell / cake[i].store;
	}
	
	// Sort the price, high to low
	sort(cake, cake + number, cmp);
	
	// Compute the earnings
	double earnings = 0;
	for(int i = 0; i < number; i++) {
		if(cake[i].store <= needNumber) {
			needNumber = needNumber - cake[i].store;
			earnings += cake[i].totalSell;
		}
		else {
			earnings = earnings + (cake[i].price * needNumber);
			break;
		}
	}
	
	// Display the result
	printf("%.2f\n", earnings);
	
	return 0;
}
```

