/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 21:37:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//const 修饰变量
void test01(){
    //1.定义const变量最好初始化
    const int j = 340;
    printf("j = %d\n", j);

    //2.c语言中const是一个只读变量，不是一个常量，可以通过指针进行修改
    const int k = 100;
    //k = 200; //err
    int *p = &k;
    *p = 200;
    printf("k = %d\n", k);
}


int main(int argc, char *argv[]){

    test01();

    return 0;
}
