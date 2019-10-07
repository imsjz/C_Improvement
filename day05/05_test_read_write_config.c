/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-07 19:39:49
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ConfigFile.h"

void test01(){

    char **fileData = NULL; //这里有申请堆内存
    int lines = 0;

    //加载配置文件
    loadFile_ConfigFile("./configure.ini", &fileData, &lines);

    ConfigInfo *myinfo = NULL;
    //解析配置文件
    parseFile_ConfigFile(fileData, lines, &myinfo); //fileData在这里释放

    printf("lines = %d\n", lines);
    printf("ip: %s\n", getInfo_ConfigFile("ip", myinfo, lines));

    //释放配置信息内存
    destroyInfo_ConfigFile(myinfo);
}

int main(int argc, char *argv[]){

    test01();

    return 0;
}
