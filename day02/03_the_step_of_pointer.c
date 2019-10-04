/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-03 13:19:41
 */
#include <stdio.h>
#include <string.h>
#include <stddef.h>


void test(){

    char *p = NULL;
    printf("%d\n", p); //0
    printf("%d\n", p + 1); //1

    int *p2 = NULL;
    printf("%d\n", p2 ); //0
    printf("%d\n", p2 + 1); //4

    printf("--------------------\n");

    char buf[1024] = {0};
    // char a = 'a';

    // memcpy(buf, &a, sizeof(char));
    // printf("buf = %c\n", buf[0]);

    //也可以用int
    int a = 100;
    memcpy(buf+1, &a, sizeof(int));
    char *p3 = buf;
    printf("*(int *)(p3+1) = %d\n", *(int*)(p3+1));
}

//创一个结构体
struct Person{
    int a;
    char b;
    char buf[64];
    int d;
};

void test01(){

    struct Person p = {10, 'a', "hello world", 100};
    printf("offset of b: %d\n", offsetof(struct Person, b)); //4个字节

    printf("d = %d\n", *(int *)((char *)&p + offsetof(struct Person, d)));


}

int main(){

    test();
    test01();


    return 0;
}