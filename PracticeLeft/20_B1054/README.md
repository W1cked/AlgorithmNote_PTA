# B1054求平均值

本题的基本要求非常简单：给定 *N* 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

### 输入格式：

输入第一行给出正整数 *N*（≤100）。随后一行给出 *N* 个实数，数字间以一个空格分隔。

### 输出格式：

对每个非法输入，在一行中输出 `ERROR: X is not a legal number`，其中 `X` 是输入。最后在一行中输出结果：`The average of K numbers is Y`，其中 `K` 是合法输入的个数，`Y` 是它们的平均值，精确到小数点后 2 位。如果平均值无法计算，则用 `Undefined` 替换 `Y`。如果 `K` 为 1，则输出 `The average of 1 number is Y`。

### 输入样例 1：

```in
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35   
```

### 输出样例 1：

```out
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38 
```

### 输入样例 2：

```in
2
aaa -9999   
```

### 输出样例 2：

```out
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
```

---

## 思路

> The scanf() function uses whitespace (**newlines**, **tabs**, **spaces**) to decide how to divide the input into separate fields.......
>
> ### Conversion Specifier
>
> | %s   | Interpret input as a string. Input begins with the first non-whitespace character and includes everything up to the next whitespace character. |
> | ---- | ------------------------------------------------------------ |
> |      |                                                              |

以样例一为例子：

分7次用 scanf("%s", input) 读取，然后再用sscanf()和sprintf()来帮助我们完成字符串与double类型变量直接的转换。读一个，分析一个，输出一个。

### sscanf()和sprintf()

#### Example1:

```cpp
#include<stdio.h>
int main() {
    int integer;
    double doubleKind;
    char str[100] = "2048:3.14:Hello", str2[100];
    
    sscanf(str, "%d:%lf,%s", &integer, &doubleKind, str2);
    printf("integer = %d\n", integer);
    printf("doubleKind = %lf\n", doubleKind);
    printf("string2 = %s\n", str2);
    
    return 0;
}
```

输出：

```out
integer = 2048
doubleKind = 3.14
string2 = Hello
```



#### Example2:

```cpp
#include<stdio.h>
int main() {
    int integer = 12;
    double doubleKind = 3.1415;
    char str[50], str2[50] = "Feeling good!";
    
    sprintf(str, "%d:%.2f-->%s", str2);
    printf("str = %s", str);
    
    return 0;
}
```

输出：

```out
str = 12:3.14--->Feeling good!
```

---

## 代码

```cpp
#include<stdio.h>
#include<string.h>

int main() {
	int totalNumber;
	scanf("%d",&totalNumber);
	
	char input[50], numToString[50];
	double temp, sum = 0;
	int vaildNumber = 0;
	for(int i = 0; i < totalNumber; i++) {
		scanf("%s", input);
		sscanf(input, "%lf", &temp);
		sprintf(numToString, "%.2f", temp);
		
		bool invaildFlag = false;
		for(int j = 0; j < strlen(input); j++) {
			if(input[j] != numToString[j])	invaildFlag = true;
		}
		if(invaildFlag || (temp > 1000) || (temp < -1000)) {
			printf("ERROR: %s is not a legal number\n", input);
			continue;
		}
		else {
			sum += temp;
			vaildNumber++;
		}
	}
	if(vaildNumber == 1)  printf("The average of 1 number is %.2f\n", sum / vaildNumber);
	else if(vaildNumber > 1) {
		printf("The average of %d numbers is %.2f\n", vaildNumber, sum / vaildNumber);
	}
	else {
		printf("The average of %d numbers is Undefined\n", vaildNumber);
	}
	
	return 0;
}
```

