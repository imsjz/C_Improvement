/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-07 18:47:45
 */
//防止头文件重复包含
#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef struct _ConfigInfo{
    char key[64];
    char value[128];
}ConfigInfo;


//目的为了在c++中能够使用c写的函数
#ifdef __cplusplus
    extern "C"{ 
#endif

//思路: 先用char**格式存储配置文件的信息,然后用解析配置文件函数把存在char**里面的内容存到结构体中

//获得文件有效行数
int getLines_ConfigFile(FILE *file);
//加载配置文件
void loadFile_ConfigFile(const char *filePath, char ***fileData, int *lines);
//解析配置文件
void parseFile_ConfigFile(char **fileData, int lines, ConfigInfo **info);
//获得指定配置信息
char *getInfo_ConfigFile(const char *key, ConfigInfo *info, int lines);
//释放配置文件信息
void destroyInfo_ConfigFile(ConfigInfo *info);
//判断当前行是否有效
int isValid_ConfigFile(const char *buf);


#ifdef __cplusplus
    }
#endif