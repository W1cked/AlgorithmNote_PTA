# B1093 字符串A+B

给定两个字符串 *A* 和 *B*，本题要求你输出 *A*+*B*，即两个字符串的并集。要求先输出 *A*，再输出 *B*，但**重复的字符必须被剔除**。

### 输入格式：

输入在两行中分别给出 *A* 和 *B*，均为长度不超过 10^6^的、由可见 ASCII 字符 (即码值为32~126)和空格组成的、由回车标识结束的非空字符串。

### 输出格式：

在一行中输出题面要求的 *A* 和 *B* 的和。

### 输入样例：

```in
This is a sample test
to show you_How it works
```

### 输出样例：

```out
This ampletowyu_Hrk
```

---

# 代码

打表查表类型题

```cpp
#include<stdio.h>

int main() {
	
	char answer[1000001];
	int length = 0;
	int ASCII[128] = {0};
	char tempChar;
	
	while((scanf("%c", &tempChar)) != EOF) {
		if(ASCII[tempChar] == 0 && tempChar != '\n') {
			ASCII[tempChar]++;
			answer[length++] = tempChar;
		}
		else {
			continue;
		}
	}
	for(int i = 0; i < length; i++) {
		putchar(answer[i]);
	}
	
	return 0;
}
```

