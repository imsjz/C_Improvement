/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 20:08:31
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//查找子串第一次出现的位置
const char *myFindStr(const char *str, const char *substr){

    const char *mystr = str;
    const char *mysub = substr;

    while(*mystr != '\0'){

        if(*mystr != *mysub){
            ++mystr;
            continue;
        }

        //临时指针变量，能走到这里，说明有一个相等了
        const char *temp_mystr = mystr;
        const char *temp_mysub = mysub;

        //开始比较
        while(*temp_mystr != '\0'){
            if(*temp_mystr != *temp_mysub){
                ++mystr;
                break;
            }
            ++temp_mystr;
            ++temp_mysub;
        }
        
        //说明匹配成功
        if(*temp_mysub == '\0'){
            return mystr;
        }
        //这个执行不到
        //++mystr;
    }
    return NULL;
}

void test(){

    char *str = "abcdefg";
    char *sub = "de";
    const char *pos = myFindStr(str, sub);
    printf("pos = %s\n", pos);
}

int main(int argc, char *argv[]){

    test();

    return 0;
}
