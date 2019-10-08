/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-08 09:59:46
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}linkNode;

void test01(){

    linkNode node1 = {10, NULL};
    linkNode node2 = {20, NULL};
    linkNode node3 = {30, NULL};
    linkNode node4 = {40, NULL};
    linkNode node5 = {50, NULL};
    linkNode node6 = {60, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    //如何遍历链表
    //先定义一个辅助指针变量
    linkNode *pCurrent = &node1;
    while(pCurrent != NULL){
        printf("%d\t", pCurrent->data);

        pCurrent = pCurrent->next;
    }
}

int main(int argc, char *argv[]){

    test01();

    return 0;
}
