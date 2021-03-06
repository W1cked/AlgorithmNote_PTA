# Map映射

在定义数组(如 int array[100])时，其实是定义了一个从int型到int型的映射，比如：

- array[0] = 25;
- array[1] = 66;

分别把

- 0 映射到 25;
- 1 映射到66;

同理，一个double型数组，则是将int型映射到double型。

但是，当我有一本字典，上面提供了很多字符串和对应的页码，如果需要用数组来表示“字符串——>页码”的对应关系，就会有些力不从心。由此我们引出map。

---

**map可以将任何基本类型(包括STL) 映射到 任何基本类型(包括STL)**

**map会以键从小到大的顺序自动排序**

---

## map常见用途

1. 需要建立字符(或string)与整数之间映射的题目，使用map以减少代码量；
2. 判断大整数或者其他类型数据是否存在的题目，可以把map当bool数组；
3. string和string的映射

延伸：**map的键和值是唯一的**，而如果一个叫键需要对应多个值，就只能使用multimap。另外，C++11标准还增加了unordered_map，以散列代替map内部的红黑树实现，使其可以用来处理只映射而不按key排序的需求，速度比map要快得多。