# B1067试密码

当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。本题就请你实现这个小功能。

### 输入格式：

输入在第一行给出一个密码（长度不超过 20 的、不包含空格、Tab、回车的非空字符串）和一个正整数 N（≤ 10），分别是正确的密码和系统允许尝试的次数。随后每行给出一个以回车结束的非空字符串，是用户尝试输入的密码。输入保证至少有一次尝试。当读到一行只有单个 # 字符时，输入结束，并且这一行不是用户的输入。

### 输出格式：

对用户的每个输入，如果是正确的密码且尝试次数不超过 N，则在一行中输出 `Welcome in`，并结束程序；如果是错误的，则在一行中按格式输出 `Wrong password: 用户输入的错误密码`；当错误尝试达到 N 次时，再输出一行 `Account locked`，并结束程序。

### 输入样例 1：

```in
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
Correct%pw
#  
```

### 输出样例 1：

```out
Wrong password: correct%pw
Wrong password: Correct@PW
Wrong password: whatisthepassword!
Account locked    
```

### 输入样例 2：

```in
cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#  
```

### 输出样例 2：

```out
Wrong password: coolman@gplt
Wrong password: coollady@gplt
Welcome in
```

---

## 思路

第一次写的时候，我在读取密码时用的是

```c
char input[1001];
scanf("%s", input);
```

后面提交到平台测试点2和测试点5是过不去的。

我才想起来，用户输入密码的时候，“空格”可是是组成密码的一部分，但是

```c
scanf("%s");
```

代码却是是 whitespce(换行符、空格、tab) 来作为分割的。

如果用户输入的密码保护了“空格”，那在输出

```out
Wrong password: 用户输入的错误密码
```

的时候肯定是错的。

查阅资料后，这道题可以改进scanf()函数读取数字的方式，即使用 **扫描集(scan set)**

---

## 扫描集(scan set)

### Example1

```c
#include <stdio.h> 

int main(void) 
{ 
	char scanset[128];
    char input[128];

	printf("Enter a string: "); 
	scanf("%[A-Z]", str);	/* This is a scanset format */
    scanf("%s", input);

	printf("scanset: %s\n", str);
    printf("input: %s\n", input);

	return 0; 
} 
```

输入:

```input
GEeKS_For_GeeKs
```

输出是：

```output
scanset: GE
input: eKS_For_GeeKs
```

#### 结论1

由此观之，**扫描集**会读取到一个不符合指定集合的元素位置为止，在输入缓冲区中仍包含着这个不符合规定的元素，在下一个输入语句中被一起读进新的字符数组。

---

### Example2

$$

$$

> If first character of scanset is ‘^’, then the specifier will stop reading after first occurrence of that character. For example, given below scanset will read all characters but stops after first occurrence of ‘o’
>
> ```c
> scanf("%[^o]", input);
> ```
>
> 

测试代码如下：

```c
#include <stdio.h> 

int main(void) 
{ 
	char scanset[128];
    char input[128];

	printf("Enter a string: "); 
	scanf("%[^o]", scanset);
    scanf("%s", input);

	printf("scanset: %s\n", scanset);
    printf("input: %s\n", input);

	return 0; 
} 
```

输入：

```input
http://geeks for___Geeks
```

输出：

```output
scanset: http://geeks f
input: or___Geeks
```

#### 结论2

反义特性'^'十分有用。

我们可以利用这个特性来完成对一整行字符的读取，即实现gets()函数的功能（PAT平台不允许使用gets()函数）。

即：

```c
scanf("%[^\n]", input);
```

由此我们可以得到本题的AC参考代码

## 代码

```cpp
#include<stdio.h>
#include<string.h>

int main() {
	int tryTimes;
	char correctPasswd[21] = {'\0'};
	scanf("%s%d", correctPasswd, &tryTimes);
	
	for(int i = 0; i < tryTimes; i++) {
		char input[1001] = {'\0'};
        getchar();			/* Absort the '\n' */
		scanf("%[^\n]", input);
		
        if(strcmp(input, "#") == 0) {
            return 0;
        }
		if(strcmp(input, correctPasswd) == 0) {
			printf("Welcome in\n");
			return 0;
		}
		else {
			printf("Wrong password: %s\n", input);
		}
	}
    printf("Account locked\n");
	
	return 0;
}
```

