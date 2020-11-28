/*
Program for strstr implementation
*/
#include<stdio.h>
#include<string.h>
#include "string.c"
void test(char str[]);
void test2(char str[]);
int main()
{
    char str[]="abcyoxyouabc";
    // char *str = "strasdg";
    /*printf("String Length is %d",StringLength(str));
    printf("String Length is %d",StringLength("str"));
    printf("String Length is %d",StringLength(""));*/
    
    if(Substring(str , "mi"))
        printf("Substring Found\n");
    else
    {
        printf("Not Found\n");
    }
    // test(str);

    // test2(str);

    // printf("%p\n", &str);
    // printf("%p\n", str);
    // // printf("%p\n", &str[0]);
    // // printf("%p\n", &str[1]);
    // // printf("%p\n", &str[2]);
    return 0;
}


void test2(char str[]){
    printf("%p\n", &str);
    printf("%p\n", str);
}


void test(char *str){
    printf("%p\n", &str);
    printf("%p\n", str);
}