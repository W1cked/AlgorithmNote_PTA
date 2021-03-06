# B1056组合数的和



给定 N 个非 0 的个位数字，用其中任意 2 个数字都可以组合成 1 个 2 位的数字。要求所有可能组合出来的 2 位数字的和。例如给定 2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。

### 输入格式：

输入在一行中先给出 N（1 < N < 10），随后给出 N 个不同的非 0 个位数字。数字间以空格分隔。

### 输出格式：

输出所有可能组合出来的2位数字的和。

### 输入样例：

```in
3 2 8 5
```

### 输出样例：

```out
330
```

---

## 思路

假设我输入了4个数，分别是

```in
2 8 5 7
```

那么，那么能组合成的两位数分别有：

- 28 82
- 25 52
- 27 72
- 85 58
- 87 78
- 57 78

观察一下，可以发现：

1. 输入的第一个数2，它在**个位**出现了**3**次，在**十位**也出现了**3**次；
2. 同理观察其他输入的数，都是在个位出现了3次，在十位也出现了3次；
3. 推而广之，假设我输入了N个数，那每个输入的数字会在个位和十位出现(N - 1)次

这就很舒服了，设变量sum = 0, temp = input();

sum += temp + temp * 10;

---

## 代码

```c
#include<stdio.h>

int main() {
	int number;
	scanf("%d", &number);
	int sum = 0;
	for(int i = 0; i < number; i++) {
		int temp;
		scanf("%d", &temp);
		sum += temp * (number - 1) * 10 + temp * (number - 1);
	}
	printf("%d", sum);
	return 0;	
}

```

