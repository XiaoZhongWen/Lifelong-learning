/*
 * @Author: 肖仲文 xiaozhongwen@mye.hk
 * @Date: 2024-07-23 14:33:31
 * @LastEditors: 肖仲文 xiaozhongwen@mye.hk
 * @LastEditTime: 2024-07-23 17:18:59
 * @FilePath: /CSP-J/dynamic_programming/climbStairs.cpp
 * 假设你正在爬楼梯。需要n阶你才能到达楼顶
 * 每次你可以爬1或2个台阶。你有多少种不同的方法可以爬到楼顶？
 */

#include <cstdio>
#include <cstring>

/**
 * 分析: 
 * 用f(x)表示爬到第x级台阶的总方法数
 * 考虑爬最后一步需要爬1级或2级台阶，那么f(x) = f(x - 1) + f(x - 2)
 * 表示爬到第x级台阶的总方法数等于爬到第x-1级台阶的总方法数与爬到第x-2级台阶的总方法数之和
 * 再考虑边界条件，爬第0级台阶的方法数是1、爬第1级台阶的方法数也是1
 */
int climbStairs(int n) {
  // 声明数组step来存储爬到各级台阶的方法总数
  int step[n+1];
  // 将数组step初始化
  memset(step, 0, sizeof(step));
  // 保存爬到第0级和第1级台阶的方法数
  step[0] = 1;
  step[1] = 1;
  for (int i = 2; i <= n; i++) {
    step[i] = step[i - 1] + step[i - 2]; 
  }
  return step[n];
}

int climbStairs1(int n) {
  // 初始条件
  // 爬到第0级台阶的方法数
  int a = 1;
  // 爬到第1级台阶的方法数
  int b = 1;

  if (n == 0 || n == 1) {
    return 1;
  }

  // 爬到第n级台阶的方法数
  int c = 0;
  for (int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main() {
  return 0;
}