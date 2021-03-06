# B1027打印沙漏

本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

```
*****
 ***
  *
 ***
*****  
```

所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

### 输入格式:

输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

### 输出格式:

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。

### 输入样例:

```in
19 *   
```

### 输出样例:

```out
*****
 ***
  *
 ***
*****
2
```

---

## 思路

### 观察与归纳

我们观察沙漏发现，图案可以由一个 **上三角** 和一个 **下三角** 构成。

- 当三角形只有1 个char时，底边长度为1

- 当三角形有 4 个char时，底边长度为3

- 当三角形有9 个char时，底边长度为5

- ……

- 我们设三角形的底边长度为x

- 由等差数列求和公式：
  $$
  总char数 = \frac{(1 + x)* (\frac {1 + x}{2})}{2} * 2 - 1
  $$

  $$
  即\ 总char数 = \frac{(1 + x)^2}{2} - 1
  $$

  -1 是减掉沙漏中间的共用char

  ×2 是沙漏由**两个**三角形组成

---

题目输入一个Number，我们构建起 Number 和 x 的映射关系，即找到一个函数表达式来描绘变量Number 和 x 的关系。

- 我们很容易发现：
  $$
  \frac{(1 + x)^2}{2} - 1 \leq Number
  $$
  整理一下我们有：
  $$
  x \leq \sqrt{2 (Number + 1)} - 1
  $$
  

---

### 基本流程

1. 输入一个变量 Number;

2. 设一个变量 MAXbottom, MAXbottom = (int)sqrt(2.0 * (Number + 1)) - 1;

3. 计算使用的char数: int used = (MAXbottom) * (MAXbottom) / 2 - 1;

4. 展示上三角(当前最大底边 <- MAXbottom; 当前最大底边 > 0; 当前最大底边 -= 2)

   - 输出空格

     (i <- 0; i < (MAXbottom - 当前最大底边) / 2; i++)

   - 输出图案

     (j <- 0; j < 当前最大底边; j++)

5. 展示下三角(当前最大底边 <- 3; 当前最大底边 <= MAXbottom; 当前最大底边 += 2)

   - 输出空格

     (i <- （MAXbottom - 当前最大底边) / 2; i > 0; i--)

     ~~正好与第四步输出空格的部分相反~~

   - 输出图案

     (j <- 0; j < 当前最大底边; j++)

---

## 代码

```c
#include<stdio.h>
#include<math.h>

int main() {
	
	int number;
	char character;
	scanf("%d %c", &number, &character);
	
	int MAXbottom = (int)sqrt(2.0 * (number + 1)) - 1;
	if(MAXbottom % 2 == 0)
		MAXbottom--;
	
	int usedCount = 0;
	// Display up triangle
	for(int currentBottom = MAXbottom; currentBottom > 0; currentBottom -= 2) {
		// Display space
		for(int i = 0; i < (MAXbottom - currentBottom) / 2; i++) {
			printf(" ");
		}
		
		// Display character
		for(int i = 0; i < currentBottom; i++) {
			putchar(character);
			usedCount++;
		}
		printf("\n");
	}
	
	// Display down triangle
	for(int currentBottom = 3; currentBottom <= MAXbottom; currentBottom += 2) {
		for(int i = (MAXbottom - currentBottom) / 2; i > 0; i--) {
			printf(" ");
		}
			
		for(int i = 0; i < currentBottom; i++) {
			putchar(character);
			usedCount++;
		}
		printf("\n");
	}
	printf("%d", number - usedCount);
	
	return 0;
}

```

