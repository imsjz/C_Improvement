/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-02 18:33:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//宏函数,不是一个真正的函数
#define MYADD(x,y) ((x) + (y))

//宏函数在一定场景下效率比函数高

int main(){

    int a = 10, b = 20;

    printf("a + b = %d\n", MYADD(a, b)); //进行简单的文本替换 MYADD(a,b) --> ((a) + (b))

    return 0;
}