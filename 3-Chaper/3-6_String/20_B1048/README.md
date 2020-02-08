# B1048数字加密

本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

### 输入格式：

输入在一行中依次给出 A 和 B，均为不超过 100 位的正整数，其间以空格分隔。

### 输出格式：

在一行中输出加密后的结果。

### 输入样例：

```in
1234567 368782971 
```

### 输出样例：

```out
3695Q8118
```

---

## 这题有个坑

如图所示：

![示意图](https://img-blog.csdn.net/20180816144546570?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTI1NjQxMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

如果两个string的长度不一样，短的那一个string要在前面补0；

---

## 思路

借鉴了网上和书上的许多例子，我是这样处理的：

1. 找到stringA和stringB的长度

2. 找到最大长度 MAX

3. 处理字符串，从左往右 (i = 0; i < MAX; i++)

   - 处理前导0的问题

     设 valueA = lengthA + i - MAX

     若 valueA < 0, 则 valueA = 0

     否则 valueA = stringA[lengthA + i - MAX];

     ----->同理处理stringB

4. 展示结果

   - 我是处理一个，展示一个

     1. 判断奇偶

        - 奇

          直接按照题意输出；

        - 偶

          putchar((valueB - valueA + 10 ) % 10 + '0');

---

## 代码

```cpp
#include<cstdio>
#include<cstring>

const char oddBit[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};

int main() {
	char strA[101], strB[101];
	scanf("%s %s", strA, strB);
	
	// Find the length of each string
	int lengthA = strlen(strA);
	int lengthB = strlen(strB);
	int lengthMAX = lengthA > lengthB ? lengthA : lengthB;
	
	for(int i = 0; i < lengthMAX; i++) {
		// Deal with the problem about zero
		int valueA = lengthA + i - lengthMAX;
		int valueB = lengthB + i - lengthMAX;
		
		if(valueA < 0) {
			valueA = 0;
		}
		else {
			valueA = strA[lengthA + i - lengthMAX] - '0';
		}
		if(valueB < 0) {
			valueB = 0;
		}
		else {
			valueB = strB[lengthB + i - lengthMAX] - '0';
		}
		
		// Display the result
		if((lengthMAX - i) % 2 != 0) {	// Odd bits
			putchar(oddBit[(valueA + valueB) % 13]);
		}
		else {	// Even bits
			putchar((valueB - valueA + 10 ) % 10 + '0');
		}
	}
	
	return 0;
}

```

