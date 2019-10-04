/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 14:05:55
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString01(char *buf, const char *source){
    int len = strlen(source);
    for(int i = 0; i < len; ++i){
        buf[i] = source[i];
    }
    buf[len] = '\0';
}


void copyString02(char *buf, const char *source){
    while(*source){
        *buf = *source;
        ++buf;
        ++source;
    }
    *buf = '\0';
}

void copyString03(char *buf, const char *source){
    while(*buf++ = *source++);
    *buf = '\0';
}

//1. 字符串拷贝
void test02(){

    char *source = "hello world";
    char buf[1024] = {0};
    //copyString01(buf, source);
    //copyString02(buf, source);
    copyString03(buf, source);
    printf("buf = %s\n", buf);
}

void reverseString(char *str){
    if(str == NULL){
        return;
    }
    int len = strlen(str);

#if 0
    int start = 0;
    int end = len - 1;
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        ++start;
        --end;
    }
#else
    char *pStart = str;
    char *pEnd = str + len -1;

    while(pStart < pEnd){
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;

        ++pStart;
        --pEnd;
    }

#endif
}

 //2. 字符串反转
void test03(){

    char p[] = "hello world";
    reverseString(p);
    printf("p = %s\n", p);
    
}

int main(int argc, char *argv[]){
 
    //test02();
    test03();
    return 0;
}



