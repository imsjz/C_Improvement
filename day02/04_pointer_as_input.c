/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 11:16:13
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printString(const char *str){

    printf("str is: %s\n", str);
}

void printStringArray(double **str, int len){

    for(int i = 0; i < len; ++i){
        printf("%s\n", str[i]);
    }

}


void test01(){

    //堆上分配内存
    char *p = malloc(sizeof(char) * 100);
    memset(p, 0, 100);
    strcpy(p, "hello world");
    printf("sizeof p = %d\n", sizeof(p)); // 8个字节
    printf("strlen of p: %d\n", strlen(p));
    printString(p);

#ifdef 0
//这里暂时没弄懂
    //栈上分配内存
    int arr[] = {1,2,3};
    //int *parr = {1,2,3};
    int *parr = malloc(sizeof(int) * 3);
    memcpy(parr, arr, sizeof(arr));
    printf("sizeof arr = %d\n", sizeof(arr)); // 4 * 3 = 12
    printf("sizeof parr = %d\n", sizeof(parr)); //指针的大小：8
    //那么他们的地址肯定不同：
    //1. 打印arr和arr的地址，我想arr应该指向的是数组的首地址，然后arr的地址也是首地址
    printf("arr = %ld\t\tvs\t&arr = %ld\n", arr, &arr);
    //2. 打印parr和parr的地址， 我想parr指向的地址就是{1,2,3}的首地址， 然后&parry的是变量parr的地址
    printf("parr = %ld\t\tvs\t&parr = %ld\n", parr, &parr);
    printf("*parr = %d\n", *parr);

    栈上分配内存
    数组名在左函数就会退化为指向数组首元素的指针
    double d[] = {1.1, 2.2, 3.3};
    printStringArray(d, 3);

#endif

    char *str[] = {
        "aaaa",
        "bbbb",
        "cccc",
        "dddd",
        "eeee"
    };
    int len = sizeof(str) / sizeof(str[0]); //数组可以获取到所占用的字节，但是用sizeof(指针)只会返回指针的大小
    printStringArray(str, len);
}


int main(){

    test01();

    return 0;
}