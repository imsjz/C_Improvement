/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-02 11:45:15
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1.堆的内存成员手动申请,手动释放
int *getSpace(){
    int *p = malloc(sizeof(int) * 5);
    if(p == NULL){
        return NULL;
    }

    //只要是连续的内存空间,都能使用下标的方式进行访问
    for(int i = 0; i < 5; ++i){
        p[i] = 100 + i;
    }

    return p;
}

void test01(){
    int *ret = getSpace();
    for(int i = 0; i < 5; ++i){
        printf("%d ", ret[i]);
    }
    //用完堆内存,一定要释放
    free(ret);
    ret = NULL;
}

void allocateSpace(char *p){
    p = malloc(100);
    memset(p, 0, 100);
    strcpy(p, "hello world");
}

void test02(){
    char *p = NULL;
    allocateSpace(p);
    printf("p = %s\n", p);
}

//传入地址的地址
void allocateSpace02(char **p){
    char *tmp = malloc(100);
    memset(tmp, 0, 100);
    strcpy(tmp, "hello world");

    *p = tmp;
}

void test03(){
    char *p = NULL;
    allocateSpace02(&p);
    printf("p = %s\n", p);
}



int main(){
    // test01();
    // test02();
    test03();

    return 0;
}