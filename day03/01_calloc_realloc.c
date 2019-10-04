/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 18:08:38
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.calloc
void test01(){
    int *p = calloc(10, sizeof(int));
    for(int i = 0; i < 10; ++i){
        p[i] = i + 1;
    }

    for(int i = 0; i < 10; ++i){
        printf("%d\t", p[i]);
    }
    printf("\n");

    if(p != NULL){
        free(p);
        p = NULL;
    }
}

//realloc
void test02(){
    int *p = malloc(10 * sizeof(int));
    for(int i = 0; i < 10; ++i){
        p[i] = i + 1;
    }

    for(int i = 0; i < 10; ++i){
        printf("%d\t", p[i]);
    }
    printf("\n");
    printf("%ld\n", p);
    p = realloc(p, sizeof(int) * 20);
    printf("%ld\n", p);

    for(int i = 0; i < 15; ++i){
        printf("%d\t", p[i]);
    }
    printf("\n");

    if(p != NULL){
        free(p);
        p = NULL;
    }


}

int main(int argc, char *argv[]){

    test02();

    return 0;
}
