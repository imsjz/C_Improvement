/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-03 12:04:32
 */
#include <stdio.h>
#include <string.h>

void test(){

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

//=============下面的地址是不断增大的，为什么呢？不是说栈的生长方向是从高地址到低地址的吗？
// 这个上下文里说的“栈”是函数调用栈，是以“栈帧”（stack frame）为单位的。
// 每一次函数调用会在栈上分配一个新的栈帧，在这次函数调用结束时释放其空间。
// 被调用函数（callee）的栈帧相对调用函数（caller）的栈帧的位置反映了栈的增长方向：
// 如果被调用函数的栈帧比调用函数的在更低的地址，那么栈就是向下增长；反之则是向上增长。
// 而在一个栈帧内，局部变量是如何分布到栈帧里的（所谓栈帧布局，stack frame layout），这完全是编译器的自由。
// 至于数组元素与栈的增长方向：C与C++语言规范都规定了数组元素是分布在连续递增的地址上的。

    printf("a = %ld\n", &a);
    printf("b = %ld\n", &b);
    printf("c = %ld\n", &c);
    printf("d = %ld\n", &d);

    int a1 = 0xaabbccdd;

    unsigned char *p = &a1;

    printf("p = %x\n", *p); //x是16进制显示
    printf("p + 1 = %x\n", *(p+1));

}

int main(){

    test();
    return 0;
}