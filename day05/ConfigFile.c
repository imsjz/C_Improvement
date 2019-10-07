/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-07 19:06:39
 */
#include "ConfigFile.h"
#include <string.h>
#include <stdlib.h>

//获得文件有效行数
int getLines_ConfigFile(FILE *file){

    char buf[1024] = {0};
    int lines = 0;
    while(fgets(buf, 1024, file) != NULL){
        if(!isValid_ConfigFile(buf))
            continue;
        memset(buf, 0, 1024);
        ++lines;
    }

    //把文件指针重置回文件的开头
    fseek(file, 0, SEEK_SET);

    return lines;

}
//加载配置文件
void loadFile_ConfigFile(const char *filePath, char ***fileData, int *line){
    FILE *file = fopen(filePath, "r");
    if(file == NULL){
        printf("Open file err\n");
        return;
    }

    int lines = getLines_ConfigFile(file); //获取文件行函数

    char **temp = malloc(sizeof(char *) * lines); //这里创建一个存储每行的temp

    char buf[1024] = {0};
    int index = 0;
    
    while(fgets(buf, 1024, file) != NULL){
        //如果返回false
        if(!isValid_ConfigFile(buf)){
            continue;
        }
        temp[index] = malloc(sizeof(char) * (strlen(buf) + 1));
        strcpy(temp[index], buf);
        index++;
        //清空buf
        memset(buf, 0, 1024);
    }

    *fileData = temp;
    *line = lines;

    fclose(file);
}
//解析配置文件
void parseFile_ConfigFile(char **fileData, int lines, ConfigInfo **info){

    ConfigInfo *myinfo = malloc(sizeof(ConfigInfo) * lines); //想要返回指针类型的数组要用二级指针了
    memset(myinfo, 0, sizeof(ConfigInfo) * lines);
    for(int i = 0; i < lines; ++i){

        char *pos = strchr(fileData[i], ':');

        strncpy(myinfo[i].key, fileData[i], pos - fileData[i]);
        strncpy(myinfo[i].value, pos+1, strlen(pos + 1) - 1);

        printf("kye:%s value: %s\n", myinfo[i].key, myinfo[i].value);
    }
    //释放文件信息
    for(int i = 0; i < lines; ++i){
        if(fileData[i] != NULL){
            free(fileData[i]);
        }
    }

    *info = myinfo;
}
//获得指定配置信息
char *getInfo_ConfigFile(const char *key, ConfigInfo *info, int lines){
    for(int i = 0; i < lines; ++i){
        if(strcmp(key, info[i].key) == 0){
            return info[i].value;
        }
    }
    return NULL;
}
//释放配置文件信息
void destroyInfo_ConfigFile(ConfigInfo *info){
    if(info == NULL){
        return;
    }
    free(info);
}
//判断当前行是否有效
int isValid_ConfigFile(const char *buf){
    if(buf[0] == '#' || buf[0] == '\n' || strchr(buf, ':') == NULL)
        return 0;
    return 1;
}