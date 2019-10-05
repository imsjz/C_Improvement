/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-05 14:21:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test01(){


    int arr[] = {1,2,3,4}; //数组大小 16 = 4 * 4

    //在两种情况下，数组名不是指向首元素的指针，其他情况都是
    //1. sizeof
    //2. 对数组名取地址
    //以上两种情况，数组名是数组类型
    printf("sizeof arr:%ld\n", sizeof(arr));

    printf("&arr addr:%ld\n", &arr); //&arr addr:140731153318720
                                    //&arr + 1 addr: 140731153318736    刚好加了16个字节
    printf("&arr + 1 addr: %ld\n", &arr + 1);


    //数组名是一个常量指针
    //arr = NULL；

    //数组下标能否为负数
    int *p = arr;
    p += 3;
    printf("p[-1] = %d\n", p[-1]);


    ////////////////////////////////////////////////////////////////////////////

}

///////////如何定义一个可以指向数组的指针///////////////
void test02(){

    int arr[] = {12,234, 5432,5342,53};

    //1. 先定义数组类型，再定义数组指针类型
    typedef int ARRAY_TYPE[5];
    ARRAY_TYPE myarrar;  //int myarray[5];
    for(int i = 0; i < 5; ++i){
        myarrar[i] = 100 +i;
    }
    for(int i = 0; i < 5; ++i){
        printf("%d\n", myarrar[i]);
    }
}

int main(int argc, char *argv[]){

    // test01();

    test02();
    return 0;
}
