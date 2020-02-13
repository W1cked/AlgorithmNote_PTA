# B1051复数乘法

复数可以写成 (*A*+*B*i) 的常规形式，其中 *A* 是实部，*B* 是虚部，*i* 是虚数单位，满足 *i*^2=−1；也可以写成极坐标下的指数形式 (*R*×*e*^(*Pi*))，其中 *R* 是复数模，*P* 是辐角，*i* 是虚数单位，其等价于三角形式 *R*(cos(*P*)+*i*sin(*P*))。

现给定两个复数的 *R* 和 *P*，要求输出两数乘积的常规形式。

### 输入格式：

输入在一行中依次给出两个复数的 *R*1, *P*1, *R*2, *P*2，数字间以空格分隔。

### 输出格式：

在一行中按照 `A+Bi` 的格式输出两数乘积的常规形式，实部和虚部均保留 2 位小数。注意：如果 `B` 是负数，则应该写成 `A-|B|i` 的形式。

### 输入样例：

```in
2.3 3.5 5.2 0.4
```

### 输出样例：

```out
-8.68-8.23i
```

---

## 思路

两个实现：

1. 把极坐标转换成直角坐标，在相乘得到结果
2. 在极坐标的形式先相乘，再把结果转换成直角坐标

我才有了第二个实现：

- 原式 = R1×(cos(P1) + i × sin(P1)) × R2(cos(P2) + i × sin(P2))

  ​		  = (R1 × cos(P1) + i × R1×sin(P1)) × (R2cos(P2) + i × R2 × sin(P2))

  ​		  = R1R2 × (cos(P1)cos(P2) - sin(P1)sin(P2)) + i × R1R2 × (cos(p1)sin(p2) + sin(p1)cos(p2))

  ​		  = R1R2 × (cos(P1 + P2)) + i × R1R2 × sin(P1 + P2)

### 注意

在输出的时候，如果得到一个很小的负数，比如“-0.0049”，再输出的时候

```c
printf("%.2f", -0.0049);
```

输出会四舍五入，得到

```out
-0.00
```

这样测试点会过不去。

我们要加入判断，当出现这样的情况时，直接给相应的变量赋0。

---

## 代码

```c
#include<stdio.h>
#include<math.h>

int main() {
	
	double R1, R2, P1, P2;
	scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
	
	double answerA, answerB;
	answerA = R1 * R2 * cos(P1 + P2);
	answerB = R1 * R2 * sin(P1 + P2);
	
	if(answerA < 0 && answerA > -0.005)
		answerA = 0;
	if(answerB < 0 && answerB > -0.005)
		answerB = 0;
	
    printf("%.2f%+.2fi", answerA, answerB);
	
	return 0;
}
```

