/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-08 13:38:03
 */
#include "LinkList.h"
//#include <stdio.h>


//初始化链表
struct LinkNode *Init_LinkList(){
    struct LinkNode *header = malloc(sizeof(struct LinkNode));
    header->data = -1;
    header->next = NULL;

    //维护一个尾部指针
    struct LinkNode *pRear = header;
    

    int val = -1;
    while(1){
        printf("输入插入的数据:\n");
        scanf("%d", &val);
        if(val == -1)
            break;
        struct LinkNode *temp = malloc(sizeof(struct LinkNode));
        temp->data = val;
        temp->next = NULL;

        pRear->next = temp;
        pRear = temp;
    }
    return header;
}
//在值为oldval的后面插入一个新的数据newval
void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval){

    if(header == NULL){
        return;
    }

    struct LinkNode *pPre = header;
    struct LinkNode *pCurrent = header->next;

    while(pCurrent != NULL){
        if(pCurrent->data == oldval){
            break;
        }
        pPre = pCurrent;
        pCurrent = pCurrent->next;
    }
    //如果pCurrent为空,说明链表中不存在oldval这个值
    // if(pCurrent == NULL){
    //     return;
    // }
    //上面的注释掉,表示如果不存在这个数据则在后面插入
    struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
    newnode->data = newval;
    newnode->next = pCurrent;

    pPre->next = newnode;
}

//删除值为val的节点
void RemoveByValue_LinkList(struct LinkNode *header, int delval){
    if(header == NULL){
        return;
    }
    struct LinkNode *pPre = header;
    struct LinkNode *pCurrent = header->next;
    while(pCurrent != NULL){
        if(pCurrent->data == delval)
            break;
        pPre = pCurrent;
        pCurrent = pCurrent->next;
    }
    if(pCurrent == NULL){
        return;
    }
    pPre->next = pCurrent->next;
    free(pCurrent);
}


//遍历
void Foeach_LinkList(struct LinkNode *header){
    if(header == NULL){
        return;
    }

    //辅助指针变量
    struct LinkNode *pCurrent = header->next;
    while(pCurrent != NULL){
        printf("%d\t", pCurrent->data);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}

//销毁
void Destroy_LinkList(struct LinkNode *header){
    if(header == NULL){
        return;
    }
    struct LinkNode *pCurrent = header;
    while(pCurrent != NULL){
        struct LinkNode *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
}

//清空
void Empty_LinkList(struct LinkNode *header){
    if(header == NULL){
        return;
    }
    struct LinkNode *pCurrent = header->next;
    while(pCurrent != NULL){
        //先保存下当前结点的下一个结点地址
        struct LinkNode *pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }
    header->next = NULL;
}