# B1030完美数列

### 输入样例：

```
10 8
2 3 20 4 5 1 6 7 8 9
```

### 输出样例：

```
1 8 
```

---

## 思路

以样例来说：

设数列a = {2, 3, 20, 4, 5, 1, 6, 7, 8, 9}

- 我们先给数列a排序，得到数列new

  new = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}

- 设2个指针, firstIndex 和 lastIndex；

  初始化两个指针，都指向第0个元素

- 设 元素个数 maxLength = lastIndex - firstIndex

- 遍历数组，条件是：

  当 lastIndex < number && number - lastIndex > maxLength，则firstIndex++

  进入循环后执行while循环，当 lastIndex < number && new[lastIndex] <= data[firstIndex] * p，则 lastIndex++

- 时刻更新 maxLength 的值



## 注意

题目给定的判别式 **M <= mp** 中的 **mp** 可能会大过int型能承受的范围，所以数组最好用long long int 型来存。