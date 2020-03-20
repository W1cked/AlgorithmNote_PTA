# B1045 快速排序

著名的快速排序算法里有一个经典的划分过程：我们通常采用某种方法取一个元素作为主元，通过交换，把比主元小的元素放到它的左边，比主元大的元素放到它的右边。 给定划分后的 *N* 个互不相同的正整数的排列，请问有多少个元素可能是划分前选取的主元？

例如给定 &#36;N = 5&#36;, 排列是1、3、2、4、5。则：

- 1 的左边没有元素，右边的元素都比它大，所以它可能是主元；
- 尽管 3 的左边元素都比它小，但其右边的 2 比它小，所以它不能是主元；
- 尽管 2 的右边元素都比它大，但其左边的 3 比它大，所以它不能是主元；
- 类似原因，4 和 5 都可能是主元。

因此，有 3 个元素可能是主元。

### 输入格式：

输入在第 1 行中给出一个正整数 *N*（≤10<sup>5</sup>）； 第 2 行是空格分隔的 *N* 个不同的正整数，每个数不超过 10<sup>9</sup>。

### 输出格式：

在第 1 行中输出有可能是主元的元素个数；在第 2 行中按递增顺序输出这些元素，其间以 1 个空格分隔，行首尾不得有多余空格。

### 输入样例：

```in
5
1 3 2 4 5 
```

### 输出样例：

```out
3
1 4 5
```

---

# 思路

- 从左往右遍历一遍，找每个元素的左边最大值
- 从右往左遍历一遍，找每个元素的右边最小值
- 再从左往右遍历一遍，当该项元素的 **左边最大值** < 该项 && **右边最小值** > 该项，则把该项加入到 **答案数组** 里，主元计数器+1
- 输出**答案数组**

---

# 代码

```cpp
#include<cstdio>

const int INF = 0x3fffffff;

int main() {
	// Input the data
	int number;
	int input[100001];
	scanf("%d", &number);
	for(int i = 0; i < number; i++) {
		scanf("%d", &input[i]);
	}
	
	// Analyze the leftMax and rightMin
	int leftMax[100001], rightMin[100001];

	leftMax[0] = 0;		// There is nothing bigger than input[0]
	for(int i = 1; i < number; i++) {
		if(leftMax[i - 1] > input[i - 1]) {
			leftMax[i] = leftMax[i - 1];
		}
		else {
			leftMax[i] = input[i - 1];
		}
	}
	
	rightMin[number - 1] = INF; 	// There is nothing smaller ther input[number - 1]
	for(int i = number - 2; i >= 0; i--) {
		if(rightMin[i + 1] > input[i + 1]) {
			rightMin[i] = input[i + 1];
		}
		else {
			rightMin[i] = rightMin[i + 1];
		}
	}
	
	int answer[100001] = {0};
	int counter = 0;	// Count the number of pivot
	for(int i = 0; i < number; i++) {
		if(leftMax[i] < input[i] && rightMin[i] > input[i]) {
			answer[counter] = input[i];
			counter++;
		}
	}
	
	// Display the result
	printf("%d\n", counter);
	for(int i = 0; i < counter; i++) {
		printf("%d", answer[i]);
		if(i != counter - 1) {
			printf(" ");
		}
	}
	printf("\n");
	
	return 0;
}
```

