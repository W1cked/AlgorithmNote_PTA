# Priority_Queue优先队列

## 常用行为

1. push()

   push(x)将令x入队，时间复杂度为O(logN)，其中N为当前优先队列中元素个数。

2. top()

   和**队列**不一样，**优先队列**没有front()和back()行为，而只能通过top()行为来访问队首元素(或者说堆顶元素)，也就是优先级最高的元素。时间复杂度为O(1)。

3. pop()

   pop()令队首元素出队，时间复杂度为O(logN)。

4. empty()

   empty()检测优先队列是否为空，返回true则空，返回false则非空。时间复杂度为O(1)。

5. size()

   size()返回优先队列内元素的个数，时间复杂度为O(1).



## 优先级的设置

### 基本数据类型

此处基本数据类型就是 int型，double型，char型等可以直接使用的数据类型。

以下有两种等价的定义形式：

```c++
priority_queue<int> testQueue;
priority_queue<int, vector<int>, less<int> > testQueue; 
```

第二种定义方式多了2个参数：

- vector<int> 是承载底层数据结构堆的容器，如果第一个参数是 char， 那第二个参数就写vector<char>

- 第三个参数是比较的类型。**less<int>**表示数字大的优先级大，而**greater<int>**表示数字小的优先级大。例如：

  ```c++
  #include<cstdio>
  #include<queue>
  using namespace std;
  
  int main() {
  	priority_queue<int, vector<int>, greater<int> > testQueue;
  	testQueue.push(3);
      testQueue.push(4);
      testQueue.push(1);
      
      printf("%d\n", testQueue.top());
      
      return 0;
  }
  ```

  输出的结果是：

  ```output
  1
  ```

  

### 结构体

例如我们定义一个水果结构体

```c++
struct fruit {
	string name;
	int price;
};
```

我们希望按水果价格高的为优先级高。那么我吗需要**重载**(Overload)小于号“ < ”。**重载**是对已有的运算符进行重新定义。例子如下：

```c++
struct fruit {
	string name;
    int price;
    friend bool operator < (fruit f1, fruit f2) {
        return f1.price < f2.price;
    }
};
```

注意，重载大于号会编译错误，因为从数学上来说，只需要重载小于号，即 f1 > f2 等价于判断 f2 < f1 ，而 f1 == f2 则等价于判断 !(f1 < f2) && !(f2 < f1) , 函数内部为 return f1.price < f2.price; 因此重载后小于号还是小于号的作用。

同理，如果想要以价格低的水果为优先级高，那么只需要把return中的小于号改为大于号即可。例子如下：

```c++
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct fruit {
	string name;
	int price;
	friend bool operator < (fruit f1, fruit f2) {
		return f1.price > f2.price;
	}
}f1, f2, f3;

int main() {
	priority_queue<fruit> testQueue;
	f1.name = "Peach";
	f1.price = 3;
	f2.name = "Pear";
	f2.price = 4;
	f3.name = "Apple";
	f3.price = 1;
	
	testQueue.push(f1);
	testQueue.push(f2);
	testQueue.push(f3);
	
	cout << testQueue.top().name << " " << testQueue.top().price << endl;
	
	return 0;
}
```

输出结果为：

```output
Apple 1
```

---

除此之外，我们还可以用第二种定义方式来写。例子如下：

```c++
#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct fruit {
	string name;
	int price;
}f1, f2, f3;

struct cmp {
	bool operator() (fruit f1, fruit f2) {
		return f1.price > f2.price;
	}
};

int main() {

	priority_queue<fruit, vector<fruit>, cmp> testQueue;
	f1.name = "Peach";
	f1.price = 3;
	f2.name = "Pear";
	f2.price = 4;
	f3.name = "Apple";
	f3.price = 1;
	
	testQueue.push(f1);
	testQueue.push(f2);
	testQueue.push(f3);
	
	cout << testQueue.top().name << " " << testQueue.top().price << endl;
	
	return 0;
}
```

输出为：

```output
Apple 1
```

---

当结构体内数据较为庞大(例如出现了字符串或者数组)，建议使用**引用**来提高效率。例子如下所示：

```c++
friend bool operator < (const fruit &f1, const fruit &f2) {
    return f1.price > f2.price;
}
bool operator() (const fruit &f1, const fruit &f2) {
    return f1.price > f2.price;
}
```

---

## priority_queue的常见用途

解决一些贪心问题，也可以对Dijkstra算法进行优化(因为priority_queue的实现是堆)。

有一点需要注意，使用top()行为前，必须用empty()行为判断优先队列是否为空，否则可能因为队空而出现错误。