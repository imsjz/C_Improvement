/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-02 12:33:39
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//extern int a = 10； 默认外部链接
int a = 10; //全局区

//静态全局变量是内部链接
static int b = 20; //静态区

//内部链接和外部链接有什么区别?
//1. 如果变量是内部链接的话,那么此变量只能在当前文件内访问
//2. 如果变量是外部链接的话,那么此变量可以被其他文件使用


//1. 全局静态变量和局部静态变量都存储在静态区，在程序运行期间都是合法和有效的
//2. 局部静态变量符合的可范围仅限于当前函数内部，全局静态变量可见范围从定义到文件结尾

void test01(){

    static int c = 30; //静态区
}

//头文件不参与编译,每一个.c文件叫做一个编译单元
//编译器独立编译每一个.c文件
//头文件不要放定义,只能放声明
void test02(){

    //声明, 表示告诉编译器这个符合是存在的,你让我先编译通过, 让链接器去找到这个符号在哪
    extern int g_a;

    printf("g_a = %d\n", g_a);
}
//=================================================
const int g_c = 100;
void test03(){

    //直接修改不行
    //g_c = 200;

    int *p = (int *)&g_c; //&g_c类型是const int*
    //全局const放在常量区,一旦初始化,不能修改
    *p = 200; //error
}

//const 局部变量
void test04(){

    //栈上
    const int a = 100;
    //a = 200; //直接修改不行

    //但是可以间接修改
    int *p = &a;
    *p = 200;

    printf("a = %d\n", a);
}

//字符串常量
void test05(){

    char *p = "hello world";
    char *p2 = "hello world";

    printf("p = %d\n", p);
    printf("p = %d\n", &"hello world"); //这两条语句输出的值一样,说明地址一样

    printf("p2 = %d\n", p2);
}

int main(){
    //test02();
    //test03();
    // test04();
    test05();

    //c = 20;
    return 0;
}