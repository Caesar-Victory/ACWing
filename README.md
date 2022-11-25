# ACWing



## 第一部分：基础知识



1. 快速排序
    - [ ] [912. 排序数组 - 力扣（LeetCode）](https://leetcode.cn/problems/sort-an-array/)
2. 归并排序
    - [ ] [912. 排序数组 - 力扣（LeetCode）](https://leetcode.cn/problems/sort-an-array/)
3. 二分
    1. 整数二分；
        - [ ] [69. x 的平方根 - 力扣（LeetCode）](https://leetcode.cn/problems/sqrtx/)
    2. 浮点数二分；
4. 高精度
    1. 高精度加法
    2. 高精度减法
    3. 高精度乘法
    4. 高精度除法
5. 前缀与差分
    1. 一维前缀和
    2. 二维前缀和
    3. 前缀和
        - [ ] [862. 和至少为 K 的最短子数组 - 力扣（Leetcode）](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/description/)
        - [ ] https://leetcode.cn/problems/subarray-sum-equals-k/description/
    4. 差分
        - [ ] [370. 区间加法 - 力扣（LeetCode）](https://leetcode.cn/problems/range-addition/)
        - [ ] [1094. 拼车 - 力扣（LeetCode）](https://leetcode.cn/problems/car-pooling/)
        - [ ] [基础算法：差分讲解_八百标兵奔北坡666的博客-CSDN博客_差分计算公式](https://blog.csdn.net/weixin_43705195/article/details/88370758)
    5. 差分矩阵
6. 离散化
    - [ ] [493. 翻转对 - 力扣（LeetCode）](https://leetcode.cn/problems/reverse-pairs/)
    - [ ] [1036. 逃离大迷宫 - 力扣（LeetCode）](https://leetcode.cn/problems/escape-a-large-maze/)
    - [ ] [1854. 人口最多的年份 - 力扣（LeetCode）](https://leetcode.cn/problems/maximum-population-year/)
7. xxx



## 第二部分：数据结构



1. ###### 单链表
2. 双链表
3. 栈
4. 队列
5. 单调栈
6. 单调队列
7. KMP
    - [x] [28. 找出字符串中第一个匹配项的下标 - 力扣（Leetcode）](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

8. Trie
9. 并查集
10. 堆

    - [ ] [1046. 最后一块石头的重量 - 力扣（Leetcode）](https://leetcode.cn/problems/last-stone-weight/solutions/)

11. 哈希表

     1. 拉链法
     2. 开放寻址法
     3. 字符串前缀哈希法[polymonial rolling hash]
         - [ ] [1044. 最长重复子串 - 力扣（Leetcode）](https://leetcode.cn/problems/longest-duplicate-substring/description/)
         - [ ] [1392. 最长快乐前缀 - 力扣（Leetcode）](https://leetcode.cn/problems/longest-happy-prefix/solutions/)
         - [ ] 备注：同时兼容KMP
         - [ ] [2223. 构造字符串的总得分和 - 力扣（Leetcode）](https://leetcode.cn/problems/sum-of-scores-of-built-strings/)



# 第三部分搜索与图论



## DFS

## BFS



- [ ] [1254. 统计封闭岛屿的数目 - 力扣（Leetcode）](https://leetcode.cn/problems/number-of-closed-islands/?envType=study-plan&id=graph-theory-basic&plan=graph&plan_progress=150m33d)
- [ ] [1020. 飞地的数量 - 力扣（Leetcode）](https://leetcode.cn/problems/number-of-enclaves/?envType=study-plan&id=graph-theory-basic&plan=graph&plan_progress=150m33d)
- [ ] [1905. 统计子岛屿 - 力扣（Leetcode）](https://leetcode.cn/problems/count-sub-islands/?envType=study-plan&id=graph-theory-basic&plan=graph&plan_progress=150m33d)



## 树与图的优先遍历

## 树与图的广度优先遍历

## 拓扑排序

## Dijkstra

- [ ] [847. 访问所有节点的最短路径 - 力扣（Leetcode）](https://leetcode.cn/problems/shortest-path-visiting-all-nodes/solutions/)
- [ ] [743. 网络延迟时间 - 力扣（Leetcode）](https://leetcode.cn/problems/network-delay-time/solutions/)

## Bellman-Ford算法

## SPFA算法

## Floyd

## Prim

## Kruskal

## 染色法判定二分图

## 匈牙利算法









## 最后一部分：调试技巧



1. 边界判断，输出的值，其数量超过预期，有可能是边界问题，应当考虑数值为0的情况；
2. 涉及到多个函数，可以注释大多数保留一个，逐个子函数调试，并且在对应位置查看输出；
3. 高频出错点：for循环的上界和下界；变量名；自增减运算符前后位置；