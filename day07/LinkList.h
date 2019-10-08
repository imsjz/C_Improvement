/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-08 13:28:17
 */
#pragma once

#include <stdlib.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C"{
#endif

//定义节点数据类型
struct LinkNode{
    int data;
    struct LinkNode *next;
};

//初始化链表
struct LinkNode *Init_LinkList();
//在值为oldval的位置插入一个新的数据newval
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval);

//删除值为val的节点
void RemoveByValue_LinkList(struct LinkNode *header, int delval);


//遍历
void Foeach_LinkList(struct LinkNode *header);

//销毁
void Destroy_LinkList(struct LinkNode *header);

//清空
void Empty_LinkList(struct LinkNode *header);

void Reverse_LinkList(struct LinkNode *header);


#ifdef __cplusplus
}
#endif