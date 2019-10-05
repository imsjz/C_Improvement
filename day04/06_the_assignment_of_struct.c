/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-05 15:34:24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
    char name[64];
    int age;
}person;

void test01(){
    person person1 = {"aaa", 20};
    person person2 = {"bbb", 30};

    person1 = person2;

    printf("Name:%s, Age:%d\n", person1.name, person1.age);
    printf("Name:%s, Age:%d\n", person2.name, person2.age);

}

typedef struct Teacher{
    char *name;
    int age;
}teacher;

void test02(){

    teacher teacher1;
    teacher1.name = malloc(sizeof(teacher) * 64);
    memset(teacher1.name, 0, 64);
    strcpy(teacher1.name, "aaaaaaaaaaaa");
    teacher1.age = 20;

    teacher teacher2;
    teacher2.name = malloc(sizeof(teacher) * 128);
    memset(teacher2.name, 0, 128);
    strcpy(teacher2.name, "bbbbbbbbbbbbbbb");
    teacher2.age = 30; 

    //不使用默认的结构体赋值行为
    //teacher1 = teacher2;
    //如果结构体内部有指针指向堆内存，那么就不能使用编译器默认的赋值行为，应该手动控制赋值过程
    if(teacher1.name != NULL){
        free(teacher1.name);
        teacher1.name = NULL;
    }
    teacher1.name = malloc(strlen(teacher2.name) + 1);
    strcpy(teacher1.name, teacher2.name);
    teacher2.age = teacher2.age;


    printf("Name:%s, Age:%d\n", teacher1.name, teacher1.age);
    printf("Name:%s, Age:%d\n", teacher2.name, teacher2.age);

    //释放内存
    if(teacher1.name != NULL){
        free(teacher1.name);
        teacher1.name = NULL;
    }
    if(teacher2.name != NULL){
        free(teacher2.name);
        teacher2.name = NULL;
    }

}

int main(int argc, char *argv[]){
    test01();
    test02();

    return 0;
}
