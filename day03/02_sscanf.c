/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 18:42:45
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//%*s或%*d   跳过数据
void test01(){

#if 0
    char *str = "1234abcd";
    char buf[1024] = {0};

    sscanf(str, "%*d%s", buf);
    printf("buf:%s\n", buf);
#else

    //忽略字符串到空格或者\t
    char *str = "abcd 1234";
    char buf[1024] = {0};

    sscanf(str, "%*s%s", buf);
    printf("buf:%s\n", buf);

#endif
}

void test02(){

    //%[width]s 读指定宽度的数据
    char *str = "1234abcd";
    char buf[1024] = {0};

    sscanf(str, "%5s", buf);
    printf("buf:%s\n", buf);

}


void test03(){

    //%[a-z] 匹配a到z中任意字符（尽可能多地匹配）
    char *str = "1234abcd";
    char buf[1024] = {0};

    sscanf(str, "%*d%[a-z]", buf);
    printf("buf:%s\n", buf);

}

void test04(){

    //%[aBC] 匹配a、B、C中一员，贪婪性
    char *str = "1234abcd";
    char buf[1024] = {0};

    sscanf(str, "%[21a]", buf);
    printf("buf:%s\n", buf);

}

void test05(){

    //%[^a] 匹配非a的任意字符，贪婪性
    char *str = "1234abcd";
    char buf[1024] = {0};

    sscanf(str, "%[^a]", buf);
    printf("buf:%s\n", buf);

}

void test06(){

    //%[^a-z] 读取除a-z以外的所有字符
    char *str = "abcd1234";
    char buf[1024] = {0};

    sscanf(str, "%[^0-9]", buf);
    printf("buf:%s\n", buf);

}

void test07(){

    //提取ip
    char *ip = "127.0.0.1";
    int num1 = 0, num2 = 0, num3 = 0, num4;
    sscanf(ip, "%d.%d.%d.%d", &num1, &num2, &num3, &num4);

    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
}

int main(int argc, char *argv[]){

    //test01();
    test07();

    return 0;
}
