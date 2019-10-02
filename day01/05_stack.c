/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-02 11:02:00
 */
#include <stdio.h>
#include <string.h>

//1. 栈区的内存自动申请,自动释放, 不需要程序手动管理

int* myfunc(){
    //不要返回局部变量的地址
    int a = 10; //该变量a在栈区
    return &a;
}

void test01(){
    //我们并不关心值是多少,因为局部变量a的内存已经被回收
    int *p = myfunc();
    printf("*p = %d\n", *p);
}

char *getString(){
    char str[] = "hello world"; //str数组在栈区, "hello world"在常量区
    return str;
}

void test02(){

    char *a = NULL;

    a = getString();
    printf("a = %ld\n", a); //a = 0, 说明a通过getString函数获取到的只是0
    printf("a = %s\n", a);
}

int main(){

    //test01();
    test02();

    return 0;
}