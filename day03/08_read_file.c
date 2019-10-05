/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-05 13:37:52
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int getFileLines(FILE *files){

    if(files == NULL)
        return -1;

    char buf[1024] = {0};

    int lines = 0;

    while(fgets(buf, 1024, files) != NULL){
        ++lines;
    }
    return lines;
}

//读取文件内容
void readFiles(FILE *files, int lines, char **contents){
    if(files == NULL)
        return;

    if(contents == NULL)
        return;

    if(lines < 0){
        return;
    }

    char buf[1024] = {0};
    int i = 0;
    while(fgets(buf, 1024, files) != NULL){

        int curLineLen = strlen(buf) + 1;
        contents[i] = malloc(sizeof(char) * curLineLen);
        strncpy(contents[i], buf, curLineLen);
        ++i;
        memset(buf, 0, 1024);
    }
}

void showFileContent(char **contents, int lines){

    for(int i = 0; i < lines; ++i){
        printf("%d行： %s", i, contents[i]);
    }
    printf("\n");
}

void freeSpaces(char **contents, int lines){

    for(int i = 0; i < lines; ++i){
        free(contents[i]);
        contents[i] = NULL;
    }
}

void test01(){

    //打开文件
    FILE *file = fopen("./test", "r");
    if(file == NULL){
        printf("打开文件失败\n");
        return;
    }
    
    //统计文件行数
    int lines = getFileLines(file);
    printf("lines = %d\n", lines);
    fseek(file, 0, SEEK_SET);

    //从得知的文件行数中场景空间

    char **pContents = malloc(sizeof(char *) * lines);
    
    readFiles(file, lines, pContents);

    //关闭文件
    fclose(file);

    showFileContent(pContents, lines);
    freeSpaces(pContents, lines);
    free(pContents);
    pContents = NULL;
    if(pContents == NULL){
        printf("good\n");
    }
}

int main(int argc, char *argv[]){

    test01();

    return 0;
}
