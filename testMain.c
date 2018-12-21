//
//  test.c
//  LAGDebugDemo
//
//  Created by 罗亮富 on 2018/9/27.
//  Copyright © 2018年 Roen Ro. All rights reserved.
//


#include "CircularBuffer.h"
#include <string.h>

int main(int argc, char * argv[]) {
    
    CircularBuffer cb = CircularBufferCreate(8);
    char *a = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char b[128];
    int len = 0,offset = 0, outLen = 0;
    
    //push
    printf("\n=====================================\n");
    len = 3;
    printf("++push=> %d bytes chars:(%c - %c)\n",len,*(a+offset),*(a+offset+len-1));
    CircularBufferPush(cb, a+offset, len );
    offset += len;
    CircularBufferPrint(cb,false);
    
    //push
    printf("\n=====================================\n");
    len = 7;
    printf("++push=> %d bytes chars:(%c - %c)\n",len,*(a+offset),*(a+offset+len-1));
    CircularBufferPush(cb, a+offset, len );
    offset += len;
    CircularBufferPrint(cb,false);
    
    //pop
    printf("\n=====================================\n");
    len = 3;
    memset(b, '\0', 128);
    outLen = (int)CircularBufferPop(cb, len, b);
    printf("--pop=> %d expect %d data:%s\n",outLen,len,b);
    CircularBufferPrint(cb,false);
    
    
    //read
    printf("\n=====================================\n");
    len = 2;
    memset(b, '\0', 128);
    outLen = (int)CircularBufferRead(cb, len, b);
    printf("||Read=> %d expect %d data:%s\n",outLen,len,b);
    CircularBufferPrint(cb,false);
    
    
    //push
    printf("\n=====================================\n");
    len = 10;
    printf("++push=> %d bytes chars:(%c - %c)\n",len,*(a+offset),*(a+offset+len-1));
    CircularBufferPush(cb, a+offset, len );
    offset += len;
    CircularBufferPrint(cb,false);
    
    //pop
    printf("\n=====================================\n");
    len = 3;
    memset(b, '\0', 128);
    outLen = (int)CircularBufferPop(cb, len, b);
    printf("--pop=> %d expect %d data:%s\n",outLen,len,b);
    CircularBufferPrint(cb,false);
    
    //pop
    printf("\n============R-R====================\n");
    len = 30;
    memset(b, '\0', 128);
    outLen = (int)CircularBufferPop(cb, len, b);
    printf("--pop=> %d expect %d data:%s\n",outLen,len,b);
    CircularBufferPrint(cb,false);
    
  //  printf("\n============RESET====================\n");
//    CircularBufferReset(cb);
//    CircularBufferPrint(cb,false);
    
    //push
    printf("\n=====================================\n");
    len = 5;
    printf("++push=> %d bytes chars:(%c - %c)\n",len,*(a+offset),*(a+offset+len-1));
    CircularBufferPush(cb, a+offset, len );
    offset += len;
    CircularBufferPrint(cb,false);
    

    
    //pop
    printf("\n=====================================\n");
    len = 2;
    memset(b, '\0', 128);
    outLen = (int)CircularBufferPop(cb, len, b);
    printf("--pop=> %d expect %d data:%s\n",outLen,len,b);
    CircularBufferPrint(cb,false);
    
    //push
    printf("\n=====================================\n");
    len = 10;
    printf("++push=> %d bytes chars:(%c - %c)\n",len,*(a+offset),*(a+offset+len-1));
    CircularBufferPush(cb, a+offset, len );
    offset += len;
    CircularBufferPrint(cb,false);
    
    
    //pop
    printf("\n=====================================\n");
    len = 6;
    memset(b, '\0', 128);
    outLen = (int)CircularBufferPop(cb, len, b);
    printf("--pop=> %d expect %d data:%s\n",outLen,len,b);
    CircularBufferPrint(cb,false);
    
    //push
    printf("\n=====================================\n");
    len = 4;
    printf("++push=> %d bytes chars:(%c - %c)\n",len,*(a+offset),*(a+offset+len-1));
    CircularBufferPush(cb, a+offset, len );
    offset += len;
    CircularBufferPrint(cb,false);
}

