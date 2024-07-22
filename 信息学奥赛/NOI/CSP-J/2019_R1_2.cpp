/*
 * @Author: 肖仲文 xiaozhongwen@mye.hk
 * @Date: 2024-07-22 14:00:28
 * @LastEditors: 肖仲文 xiaozhongwen@mye.hk
 * @LastEditTime: 2024-07-22 17:16:45
 * @FilePath: /CSP-J/2019_R1_2.cpp
 * @Description: CSP-J 2019 R1
 * 2019年CSP-J完善程序第2题
 * 计数排序
 * 计数排序是一种广泛使用的排序算法。下面的程序使用双关键字计数排序，将n对10000以内的整数，从小到大排序。
 * 例如有三对整数(3,4)、(2,4)、(3,3)，那么排序之后应该是(2,4)、(3,3)、(3,4)。
 * 输入第一行为n，接下来n行，第i行有两个数a[i]和b[i],分别表示第i对整数的第一个关键字和第二个关键字。
 * 从小到大排序后输出。
 */
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 10000000;
const int maxs = 10000;

unsigned int a[maxn], b[maxn], res[maxn], ord[maxn];

int n;
unsigned int cnt[maxs + 1];

void display(unsigned int a[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d  ", a[i]);
  }
}

int main()
{
  // 输入双关键字数组
  // scanf("%d", &n);
  // for (int i = 0; i < n; i++)
  // {
  //   scanf("%u %u", &a[i], &b[i]);
  // }
  int n = 3;
  a[0] = 3;
  a[1] = 2;
  a[2] = 3;

  b[0] = 4;
  b[1] = 4;
  b[2] = 3;

  // 初始化计数数组
  memset(cnt, 0, sizeof(cnt));

  // 按第二个关键字进行计数排序
  // 记录数组b中各关键字出现的次数
  for (int i = 0; i < n; i++)
  {
    cnt[b[i]]++;
  }

  // 对cnt进行累积计数, 得到各关键字在排序数组中的索引值
  for (int i = 1; i < maxs; i++)
  {
    cnt[i] += cnt[i - 1];
  }

  // 记录按第二个关键字排序后的排序数组中各关键字的索引值与在原数组b中的索引值的对应关系
  for (int i = 0; i < n; i++)
  {
    ord[--cnt[b[i]]] = i;
  }

  // 再按第一个关键字进行计数排序
  // 将计数数组清0
  memset(cnt, 0, sizeof(cnt));

  // 记录数组a中各关键字出现的次数
  for (int i = 0; i < n; i++)
  {
    cnt[a[i]]++;
  }

  // 对cnt进行累积计数, 得到各关键字在排序数组中的索引值
  for (int i = 1; i < maxs; i++)
  {
    cnt[i] += cnt[i - 1];
  }

  // 记录按第一个关键字排序后的排序数组中各关键字的索引值与在原数组a中的索引值的对应关系
  // 通过反向处理 ord 数组，确保了当 a 中有相同值的元素时，它们在 res 数组中的顺序与它们在 ord 数组中的顺序一致。
  // 由于 ord 数组已经按 b 排序且保持稳定性，反向处理 ord 确保了最终按 a 排序后的顺序也保持稳定。
  // 这种逆向遍历确保了对于相同 a 值的元素，先处理索引大的元素，再处理索引小的元素。
  // 因为 cnt 数组是累积的，在索引大的元素先被处理时，它会占据cnt[a]数组中的最后位置。
  // 然后，索引小的元素会放在其前面位置。
  for (int i = n - 1; i >= 0; i--)
  {
    res[--cnt[a[ord[i]]]] = ord[i];
  }

  for (int i = 0; i < n; i++)
  {
    printf("(%d %d) ", a[res[i]], b[res[i]]);
  }

  return 0;
}
