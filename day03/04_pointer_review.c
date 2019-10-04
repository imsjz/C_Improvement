/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 21:25:43
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    char *p = malloc(64);

     ++p;
     if(p != NULL){
         free(p);
         p = NULL;
     }

    return 0;
}
