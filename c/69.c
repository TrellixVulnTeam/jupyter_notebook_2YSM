/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/
#include <stdio.h>
#include <stdlib.h>
int mySqrt(int x) {
    long xk = x; //避免 xk*xk 溢出，故采用long整型
    double err = 1e-6; // err为误差，1e-6就是1乘10的-6次幂
    while( xk*xk > x ) //判断条件
    {
        xk = ( xk + x/xk )/2; //迭代公式
    }
    return xk; 
}
