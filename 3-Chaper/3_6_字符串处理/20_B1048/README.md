# B1048数字加密

## 这题有个坑

如图所示：

![示意图](https://img-blog.csdn.net/20180816144546570?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTI1NjQxMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

如果两个string的长度不一样，短的那一个string要在前面补0；

---

## 我的思路

借鉴了网上和书上的许多例子，我是这样处理的：

1. 找到stringA和stringB的长度

2. 找到最大长度 MAX

3. 处理字符串，从左往右 (i = 0; i < MAX; i++)

   - 处理前导0的问题

     设 valueA = lengthA + i - MAX

     若 valueA < 0, 则 valueA = 0

     否则 valueA = stringA[lengthA + i - MAX];

     ----->同理处理stringB

4. 展示结果

   - 我是处理一个，展示一个

     1. 判断奇偶

        - 奇

          直接按照题意输出；

        - 偶

          putchar((valueB - valueA + 10 ) % 10 + '0');