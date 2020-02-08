# B1035 插入与归并



根据维基百科的定义：

**插入排序**是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

**归并排序**进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

### 输入格式：

输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

### 输出格式：

首先在第 1 行中输出`Insertion Sort`表示插入排序、或`Merge Sort`表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。

### 输入样例 1：

```in
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0  
```

### 输出样例 1：

```out
Insertion Sort
1 2 3 5 7 8 9 4 6 0 
```

### 输入样例 2：

```in
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6   
```

### 输出样例 2：

```out
Merge Sort
1 2 3 8 4 5 7 9 0 6
```

---

## 思路

很明显，如果不是插入排序，就一定是归并排序。

我们先探测第2行的数列是不是插入排序所形成的。如果从头探测到尾均不符合插入排序的特点，那么我们就按归并排序的情况处理。

我们观察插入排序，可以发现一些特点，以样例1为example：

- 从1开始计数。前5项是从小到大的**有序**数列；
- 第6~第10项**和原数列是一样的**；

由此观之，我们可以用2个顺序执行的while循环来判断这个数列是不是插入排序形成的。步骤如下，设 number 为数列元素个数：

1. while(i < number && halftSort[i] <= halfSort[i + 1]) ，则 i++;
2. while(i < number && (halfSort[i + 1] == origin[i + 1]))，则i++;
3. 如果 i != number - 1，则该数列是由归并排序形成的。

判断完是什么类型的排序后，就可以借用sort()函数来完成下一步排序。

---

- 插入排序

  我们只需要找到原来给的有序数列有多长，直接长度加1继续排序后输出即可。

- 归并排序

  1. 从origin数组一步步模拟归并排序
  2. 每次排序后用一个自定义的函数来判断和题目给出的是不是一样的
  3. 如果是一样的，那就再模拟一次归并排序后输出

---

## 代码

```cpp
#include<cstdio>
#include<algorithm>
using namespace std;

void Display(int* array, int number) {
	for(int i = 0; i < number; i++) {
		printf("%d", array[i]);
		if(i != number - 1) {
			printf(" ");
		}
	}
}

bool isSame(int* origin, int* halfSort, int number) {
	for(int i = 0; i < number; i++) {
		if(origin[i] != halfSort[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int number;
	scanf("%d", &number);
	
	int origin[101];
	for(int i = 0; i < number; i++) {
		scanf("%d", &origin[i]);
	}
	int halfSort[101];
	for(int i = 0; i < number; i++) {
		scanf("%d", &halfSort[i]);
	}
	
	// If it is insertion sort, return length; otherwise return 0
	int length = 0, i = 0;
	while(i < number && halfSort[i] <= halfSort[i + 1]) {
		i++;
	}
	length = i + 1;
	while(i < number && halfSort[i + 1] == origin[i + 1]) {
		i++;
	}
	if(i != number - 1) {
		length = 0;
	}
	else {
		length += 1;
	}
	
	// Finish the sort and display them
	if(length) {	// insertion sort
		puts("Insertion Sort");
		sort(halfSort, halfSort + length);
		Display(halfSort, number);
		return 0;
	}
	else {			// merge sort
		puts("Merge Sort");
		bool flag = false;
		for(int step = 2; step / 2 <= number; step *= 2) {
			if(step != 2 && isSame(origin, halfSort, number)) {
				flag = true;
			}
			for(int i = 0; i < number; i += step) {
				sort(origin + i, origin + min(i + step, number));
			}
			if(flag == true) {
				Display(origin, number);
				return 0;
			}
		}
	}
	
}
```

