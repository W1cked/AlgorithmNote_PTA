# B1030 完美数列

给定一个正整数数列，和正整数 *p*，设这个数列中的最大值是 *M*，最小值是 *m*，如果 *M* ≤ m&times;p，则称这个数列是完美数列。

现在给定参数 *p* 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

### 输入格式：

输入第一行给出两个正整数 *N* 和 *p*，其中 *N*（≤10^5）是输入的正整数的个数，*p*（≤10^9）是给定的参数。第二行给出 *N* 个正整数，每个数不超过 10^9。

### 输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。

### 输入样例：

```
10 8
2 3 20 4 5 1 6 7 8 9
```

### 输出样例：

```
1 8 
```

---

## 思路

以样例来说：

设数列a = {2, 3, 20, 4, 5, 1, 6, 7, 8, 9}

- 我们先给数列a排序，得到数列new

  new = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}

- 设2个指针, firstIndex 和 lastIndex；

  初始化两个指针，都指向第0个元素

- 设 元素个数 maxLength = lastIndex - firstIndex

- 遍历数组，条件是：

  当 lastIndex < number && number - lastIndex > maxLength，则firstIndex++

  进入循环后执行while循环，当 lastIndex < number && new[lastIndex] <= data[firstIndex] * p，则 lastIndex++

- 时刻更新 maxLength 的值



### 注意

题目给定的判别式 **M <= mp** 中的 **mp** 可能会大过int型能承受的范围，所以数组最好用long long int 型来存。

---

## 代码

```cpp
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int number, p;
	scanf("%d%d", &number, &p);
	
	long long int A[100001];
	for(int i = 0; i < number; i++) {
		scanf("%lld", &A[i]);
	}
	
	sort(A, A + number);
	
	// Count the number of perfect array
	int firstIndex = 0, lastIndex = 0, counter = 0;
	while(firstIndex < number && lastIndex < number) {
		// Keep moving the lastIndex till the end
		while(lastIndex < number && A[lastIndex] <= A[firstIndex] * p) {
			lastIndex++;
		}
		if(counter < lastIndex - firstIndex) {	// Update the counter
			counter = lastIndex - firstIndex;
		}
		firstIndex++;
	}
	
	printf("%d", counter);
	
	return 0;
}
```

