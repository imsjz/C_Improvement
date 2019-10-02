/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-09-30 15:06:18
 */
#include <stdio.h>
#include <stdlib.h>

// #pragma pack(1)

//1.sizeof返回的是变量实际所占用空间的大小,单位:字节
struct Person{
    char a; //1个字节
    int b; //4个字节
};

void test01(){
    printf("int size: %d\n", sizeof(int)); //int的大小是4个字节
    double b = 3.14;
    printf("b size: %d\n", sizeof b); //double的大小是8个字节

    printf("Person size: %d\n", sizeof(struct Person)); //8个字节
}

//2.sizeof返回的是unsigned int
void test02(){
    unsigned int a = 10;
    if(a - 20 > 0){ //会变成unsigned类型
        printf("大于0\n");
    }
    else{
        printf("小于0\n");
    }
}

//3.sizeof计算数组

//弄一个封装试试
//数组作为函数参数会退化为指向数组首元素的指针
int caculateArraySize(int arr[]){
    return sizeof(arr);
}

void test03(){

    int arr[] = {1, 2,3,4,5,6,7};
    printf("sizeof arr: %d\n", sizeof(arr)); //28
    printf("sizeof arr: %d\n", caculateArraySize(arr)); //8
}



int main(){
    test01();
    test02();
    test03();

    return 0;
}