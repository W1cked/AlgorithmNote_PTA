# Stack栈

## 栈的常用行为

1. push()

   push(x)将x入栈，时间复杂度为O(1)

2. top()

   由于stack本身是一种后进先出的数据结构，在STL的stack中只能通过top()行为来访问栈顶元素。时间复杂度为O(1)

3. pop()

   pop()用以弹出栈顶元素，时间复杂度为O(1)

4. empty()

   empty()可以检测stack内是否为空，返回true为空，返回false为非空。时间复杂度为O(1)

5. size()

   size()返回stack内元素的个数，时间复杂度为O(1)



## 栈的常见用途

stack用来模拟实现一些递归，防止程序堆栈内存的限制而导致程序运行出错。一般来说，程序的栈内存空间很小，对有些题目来说，如果用普通的函数来进行递归，一旦递归层数过深(不同机器不同，约几千至几万层)，则会导致程序运行崩溃。

如果用栈来模拟递归算法的实现，则可以避免这一方面的问题。