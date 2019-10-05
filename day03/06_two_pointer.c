/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-05 13:02:35
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocateSpace(int **temp){

    int *arr = malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; ++i){
        arr[i] = i + 1;
    }
    
    *temp = arr;
}

void freeSpace(void *p){
    if(p == NULL){
        return;
    }
    free(p);
    p = NULL;
}

void printArray(const int *arr, int len){

    for(int i = 0; i < len; ++i){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void test01(){

    int *p = NULL;
    //调用函数分配空间
    allocateSpace(&p);
    printArray(p, 10);
    freeSpace(p);
    p = NULL;
}

int main(int argc, char *argv[]){

    test01();

    return 0;
}
