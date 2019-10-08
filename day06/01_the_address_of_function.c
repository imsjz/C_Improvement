/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-07 21:04:17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(){
    printf("hello world\n");
}
int add(int a, int b){
    return a + b;
}

//1. 函数可以作为另一个函数的参数
void doLogic(int(*pFunc)(int, int)){
    int a = 10;
    int b = 20;
    int ret = pFunc(a,b);
    printf("ret = %d\n", ret);
}

//函数指针做函数参数(回调函数)
void printAllArray(void *arr, int eleSize, int len, void(*print)(void*)){
    char *start = (char *)arr;
    for(int i = 0; i < len; ++i){
        //printf("%d\n", start + eleSize*i);
        print(start + eleSize*i);
    }
}

void myPrint(void *data){
    int *p = (int*)data;
    printf("%d\n", *p);
}

void test01(){

    int arr[] = {1,2,3,5};
    printAllArray(arr, sizeof(int), 4, myPrint);
    printf("---------------------\n");
    for(int i = 0; i < 4; ++i){
        printf("%d\n", &arr[i]);
    }
}
/////////////////////////////////////////////////////////
struct  Person
{
    char name[64];
    int age;
};

void myPrintPerson(void *data){
    struct Person *person = (struct Person*)data;
    printf("name: %s, age: %d\n", person->name, person->age);
}

void test02(){

    struct Person persons[] = {
        {"aaa", 10},
        {"bbb", 20},
        {"ccc", 30},
        {"ddd", 40}
    };
    printAllArray(persons, sizeof(struct Person), 4, myPrintPerson);

}


int main(int argc, char *argv[]){

    printf("函数入口地址: %ld\n", func);
    doLogic(add);
    test01();
    test02();

    return 0;
}
