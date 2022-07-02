#include "stdio.h"
typedef unsigned char   uint8_t;
void memprint(void* ptr,int len){
    int i = 0;
    printf("%p\n",ptr);
    for(;i<len;i++){
        if(i%8 == 0){
            printf(" ");
        }
        if(i%16 == 0){
            printf("\n");
        }
        printf("%02x",*((uint8_t *)ptr + i));
    }
}