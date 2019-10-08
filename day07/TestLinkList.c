/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-08 14:22:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"


void test01(){

    //100, 200, 300, 400
    struct LinkNode *header = Init_LinkList();
    Foeach_LinkList(header);
    //插入数据
    InsertByValue_LinkList(header, 300, 999);
    printf("--------------------\n");
    // Foeach_LinkList(header);
    // //清空
    // Empty_LinkList(header);
    // Foeach_LinkList(header);

    // RemoveByValue_LinkList(header, 999);

    //逆序
    Reverse_LinkList(header);
    Foeach_LinkList(header);
}

int main(int argc, char *argv[]){

    test01();

    return 0;
}
