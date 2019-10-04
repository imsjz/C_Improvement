/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 14:48:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test(){

    //1. 格式化字符串
    char buf[1024] = {0};
    sprintf(buf, "hello %s!", "sanjay");
    printf("buf = %s\n", buf);

    //2. 拼接字符串
    char *s1 = "hello";
    char *s2 = "world";
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%s %s", s1, s2);
    printf("buf = %s\n", buf);

    //3. 数字转成字符串格式
    int number = 666;
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "%d",number);
    printf("buf = %s\n", buf);

    //4. 格式化输出
    memset(buf, 0, sizeof(buf));
    //八进制o，十六进制x
    sprintf(buf, "666的八进制:0%o\t, 十六进制:0x%x\n",number, number);
    printf("buf = %s\n", buf);
    //左右对齐
    printf("右对齐：%8d\n", number);
    printf("左对齐:%-8d\n", number);

    //5.给数组赋值
    char **p = malloc(sizeof(char*) * 5);
    for(int i = 0; i < 5; ++i){
        p[i] = malloc(sizeof(char) * 64);
        memset(p[i], 0, 64);
        sprintf(p[i], "name_%d", i+1);
    }
    //打印
    for(int i = 0; i < 5; ++i){
        printf("%s\n", p[i]);
    }
    //释放
    for(int i = 0; i < 5; ++i){
        if(p[i] != NULL){
            free(p[i]);
            p[i] = NULL;
        }
    }
    if(p != NULL){
        free(p);
        p = NULL;
    }
}

int main(int argc, char *argv[]){

    test();

    return 0;
}
