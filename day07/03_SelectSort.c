/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-08 19:45:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SelectSort(void *ptr, int ele_size, int ele_num, int(*compare)(void*, void*)){
    char *temp = malloc(ele_size); //用于临时保存元素

    for(int i = 0; i < ele_num; ++i){
        int minOrMax_index = i;
        for(int j = i + 1; j < ele_num; ++j){
            char *pMinOrMax = (char*)ptr + ele_size * minOrMax_index;
            char *pJ = (char*)ptr + ele_size * j;
            if(compare(pJ, pMinOrMax)){
                minOrMax_index = j;
            }
        }

        if(minOrMax_index != i){
            char *pMinOrMax = (char*)ptr + ele_size * minOrMax_index;
            char *pI = (char*)ptr + ele_size * i;

            memcpy(temp, pI, ele_size);
            memcpy(pI, pMinOrMax, ele_size);
            memcpy(pMinOrMax, temp, ele_size);
        }
    }
    if(temp != NULL){
        free(temp);
    }
}

int compare(void *d1, void *d2){
    int *p1 = (int*)d1;
    int *p2 = (int*)d2;

    return *p1 > *p2;
}



void test(){

    int arr[] = {7, 4, 9, 2, 1};
    SelectSort(arr, sizeof(int), sizeof(arr) / sizeof(arr[0]), compare);
    for(int i = 0; i < 5; ++i){
        printf("%d\t", arr[i]);
    }
    printf("\n");


}

int main(int argc, char *argv[]){

    test();

    return 0;
}
