# B1053住房空置率

在不打扰居民的前提下，统计住房空置率的一种方法是根据每户用电量的连续变化规律进行判断。判断方法如下：

- 在观察期内，若存在超过一半的日子用电量低于某给定的阈值 *e*，则该住房为“可能空置”；
- 若观察期超过某给定阈值 *D* 天，且满足上一个条件，则该住房为“空置”。

现给定某居民区的住户用电量数据，请你统计“可能空置”的比率和“空置”比率，即以上两种状态的住房占居民区住房总套数的百分比。

### 输入格式：

输入第一行给出正整数 *N*（≤1000），为居民区住房总套数；正实数 *e*，即低电量阈值；正整数 *D*，即观察期阈值。随后 *N* 行，每行按以下格式给出一套住房的用电量数据：

*K* *E*1 *E*2 ... *E_K*

其中 *K* 为观察的天数，*E*_*i* 为第 *i* 天的用电量。

### 输出格式：

在一行中输出“可能空置”的比率和“空置”比率的百分比值，其间以一个空格分隔，保留小数点后 1 位。

### 输入样例：

```in
5 0.5 10
6 0.3 0.4 0.5 0.2 0.8 0.6
10 0.0 0.1 0.2 0.3 0.0 0.8 0.6 0.7 0.0 0.5
5 0.4 0.3 0.5 0.1 0.7
11 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1
11 2 2 2 1 1 0.1 1 0.1 0.1 0.1 0.1  
```

### 输出样例：

```out
40.0% 20.0%   
```

（样例解释：第2、3户为“可能空置”，第4户为“空置”，其他户不是空置。）

---

## 思路

细心细心再细心，整道题没有什么难点，按着题目说的，一步步读入数据，分析数据，搞清楚 if() 判断的时候是 >= 还是 > 就OK了。

一开始我是不懂的，在不断地调试中，我认为题目说的“可能空置”的条件是不包含阈值e的，“空置”的条件：超过观察期D，也是不包括它本身的。所以在判断这两个条件的时候使用 > 或 < 而不是 >= 或 <=。

---

## 代码

```cpp
#include<stdio.h>

int main() {
	double number, dayLimit, powerLimit;
	scanf("%lf%lf%lf", &number, &powerLimit, &dayLimit);
	
	int problyEmpty = 0, EMPTY = 0;
	for(int i = 0; i < number; i++) {
		int watchDay;
		scanf("%d", &watchDay);
		
		int problyEmptyCount = 0;
		int EMPTYcount = 0;
		bool emptyFlag = false;
		for(int j = 0; j < watchDay; j++) {
			double temp;
			scanf("%lf", &temp);
			if(temp < powerLimit)  problyEmptyCount++;
		}
		if(problyEmptyCount > watchDay / 2 && watchDay > dayLimit) {
			emptyFlag = true;
			EMPTY++;
		}
		if(problyEmptyCount > watchDay / 2 && emptyFlag == false)  
			problyEmpty++;
	}
	printf("%.1f%c %.1f%c", (problyEmpty / number) * 100, '%', (EMPTY / number) * 100, '%');
	
	return 0;
}
```

注释：

最开始我是没有第14行的 emptyFlag 的。后面发现虽然“空置”的条件是被包含在“可能空置”这个集合里的，但是一个用户被当作“空置”了的话，就是不被算作“可能空置”的。所以我加了一个emptyFlag来确定这个用户是不是被当作“空置”来处理。