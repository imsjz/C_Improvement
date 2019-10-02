/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-09-30 14:23:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#if 0
struct Person{
    char name[64];
    int age;
};

typedef struct Person myPerson;

#endif

//上面两条语句等价于下面
typedef struct Person{
    char name[64];
    int age;
}myPerson;

void test01(){
    myPerson p;
}

typedef char* PCHAR;

void test02(){
    // char *p1, p2;
    PCHAR p1, p2;

    cout << typeid(p1).name() << endl;
    cout << typeid(p2).name() << endl;

}

//有利于程序的移植性
typedef long long mytype_t;

void test03(){
    mytype_t a;
}

int main(){

    test02();

    return 0;
}