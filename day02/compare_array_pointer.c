/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-10-04 12:55:41
 */
#include <stdio.h>


int main(){

    char a[9] = "adfkasj";
    char c = a[0];
    printf("c = %c\n", c);

    char a_char = *(char*)a;
    printf("a_char = %c\n", a_char);

    char *p = "adfkasj";
    c = *p;
    printf("c = %c\n", c);

    c = p[0];
    printf("c = %c\n", c);

    c = *a;

    //float *pf = 3.141;


    return 0;
}