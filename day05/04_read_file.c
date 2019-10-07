/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-07 18:21:07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test01(){

    FILE *f = fopen("./test.txt", "r");
    if(f == NULL){
        printf("open file failed\n");
        return;
    }
    char ch;
#if 0
    while(!feof(f)){
        ch = fgetc(f);
        if(feof(f)){
            break;
        }
        printf("%c", ch);
    }

#else
    //这样子更好
    while((ch = fgetc(f)) != EOF){
        printf("%c", ch);
    }

#endif

    //close file
    fclose(f);
}

int main(int argc, char *argv[]){

    test01();
    //printf("%c", EOF);

    return 0;
}
