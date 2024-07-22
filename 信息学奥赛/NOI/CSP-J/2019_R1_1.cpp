/*
 * @Author: 肖仲文 xiaozhongwen@mye.hk
 * @Date: 2024-07-22 09:39:42
 * @LastEditors: 肖仲文 xiaozhongwen@mye.hk
 * @LastEditTime: 2024-07-22 13:59:11
 * @FilePath: /CSP-J/2019_R1.cpp
 * @Description: CSP-J 2019 R1
 *
 *  2019年CSP-J完善程序第1题
 * （矩阵变幻）有一个奇幻的矩阵，在不停的变幻，其变幻方式为：数字0变成矩阵：
 *  0 0
 *  0 0
 *  数字1变成矩阵：
 *  1 1
 *  1 0
 *  最初该矩阵只有一个元素0，变幻n次后，矩阵会变成什么样？
 *
 *  输入一行一个不超过10的正整数n，输出变幻n次后的矩阵。
 *
 * Copyright (c) 2024 by xiaozhongwen, All Rights Reserved.
 */

#include <cstdio>
const int max_size = 1 << 10;
int res[max_size][max_size];
/*
 * 递归求解过程
 *  x,y为矩阵左上角的坐标：它是通过计算step得到的，因为子矩阵的左上角坐标(x,y)与矩阵的深度有关
 *  n为矩阵的深度：将大矩阵分解为小矩阵的过程中，深度减1
 *  t为矩阵的值：满足最初矩阵的变幻规则，因为矩阵是由最初的小矩阵[0]或[1]生长出来的
 */
void rescursive(int x, int y, int n, int t)
{
  if (n == 0)
  {
    res[x][y] = t;
    return;
  }
  // 计算矩阵的深度
  int step = 1 << (n - 1);
  // 递归处理左上角矩阵
  rescursive(x, y, n - 1, t);
  // 递归处理右上角矩阵
  rescursive(x + step, y, n - 1, t);
  // 递归处理左下角矩阵
  rescursive(x, y + step, n - 1, t);
  // 递归处理右下角矩阵
  rescursive(x + step, y + step, n - 1, !t);
}

int main()
{
  int n;
  scanf("%d", &n);
  rescursive(0, 0, n, 0);
  int size = 1 << n;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}