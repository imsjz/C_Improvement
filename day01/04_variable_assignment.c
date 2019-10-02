/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-09-30 15:06:18
 */
#include <stdio.h>
#include <stdlib.h>

// #pragma pack(1)


struct Person{
    char a; //1个字节 linux结构体中默认对齐字节大小为4个字节
    int b; //4个字节 偏移
    char c; //不偏移
    int d;
};

void test01(){
     struct Person p = {'a', 100, 'b', 200};
     printf("p.d: %d\n", p.d);

     p.d = 1000;

     (&p)->b = 2000;

     printf("p.d = %d\n", p.d);
     printf("p.b = %d\n", p.b);

     double *pp = NULL;
     printf("pp:%d\n", pp);
     printf("pp+1 = %d\n", pp+1); //int -- >4   double --> 8

     //通过指针找d的首地址
     printf("===============\n");
     printf("%d\n", (char *)&p + 12);
     printf("&(p.d):%d\n", &(p.d));

     int tmp = *(int *)((char *)&p+12);
     printf("tmp:%d\n", tmp);
}




int main(){
    test01();

    return 0;
}