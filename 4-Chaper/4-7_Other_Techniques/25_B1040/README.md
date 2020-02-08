# B1040 有几个PAT

字符串 `APPAPT` 中包含了两个单词 `PAT`，其中第一个 `PAT` 是第 2 位(`P`)，第 4 位(`A`)，第 6 位(`T`)；第二个 `PAT` 是第 3 位(`P`)，第 4 位(`A`)，第 6 位(`T`)。

现给定字符串，问一共可以形成多少个 `PAT`？

### 输入格式：

输入只有一行，包含一个字符串，长度不超过10^5，只包含 `P`、`A`、`T` 三种字母。

### 输出格式：

在一行中输出给定字符串中包含多少个 `PAT`。由于结果可能比较大，只输出对 1000000007 取余数的结果。

### 输入样例：

```in
APPAPT  
```

### 输出样例：

```out
2
```

---

## 思路

根据分步骤乘法计数原理，我们可以这么看：找到A，然后用左边P的个数 * 右边T的个数，即为答案。

这里我参考了网上的例子，用2次for循环完成。

1. 先从左到右扫一遍，统计T的个数
2. 再从左往右扫一遍，顺序执行以下操作：
   - 当字符为P时，numberP++；
   - 当字符为T时，numberT--； // 因为中间没有字符A，T的个数要减掉
   - 当字符为A时，sum = (sum + numberP * numberT) % MOD;

---

## 代码

```cpp
#include<cstdio>
#include<cstring>

const int MOD = 1000000007;

int main() {
	
	// Input the data
	char input[100001];
	scanf("%s", input);
	
	// Analyze the data
	int countP = 0, countA = 0, countT = 0;
	int sum = 0;
	for(int i = 0; i < strlen(input); i++) {
		if(input[i] == 'T') {
			countT++;
		}
	}
	for(int i = 0; i < strlen(input); i++) {
		if(input[i] == 'P') {
			countP++;
		}
		if(input[i] == 'T') {
			countT--;
		}
		if(input[i] == 'A') {
			sum = (sum + countP * countT) % MOD; 
		}
	}
	
	printf("%d", sum);
	
	return 0;
} 
```

