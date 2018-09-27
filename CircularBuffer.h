//
//  CircularBuffer.h
//
//  Created by 罗亮富(Roen)zxllf23@163.com on 14-1-14.
//  Copyright (c) 2014年 All rights reserved.
//

#ifndef YYDJ_Roen_CircularBuffer_h
#define YYDJ_Roen_CircularBuffer_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 A circular buffer(circular queue, cyclic buffer or ring buffer), is a data structure that uses a single, fixed-size buffer as if it were connected end-to-end. This structure lends itself easily to buffering data streams. visit https://en.wikipedia.org/wiki/Circular_buffer to see more information.
 */


typedef struct {
    size_t size; //bytes size
    size_t bytesAvailable; //bytes data available in cirle buffer
    size_t tailOffset; //head offset, the oldest byte position offset
    size_t headOffset; //tail offset, the lastest byte position offset
    void *buffer;
}CircularBuffer;



/*************************************************
 Function: CircularBufferCreate.
 Description: create a circular buffer You must call CircularBufferFree() in balance to free the buffer memory created by CircularBufferCreate().
 Input: size, the size in bytes for the circular buffer.
 Return: the newly created circular buffer.
 *************************************************/
extern CircularBuffer CircularBufferCreate(size_t size);

/*************************************************
 Function: CircularBufferFree.
 Description: to free memory for CircularBuffer structure
 *************************************************/
extern void CircularBufferFree(CircularBuffer *cBuf);

/*************************************************
 Function: CircularBufferReset.
 Description: reset the CircularBuffer
 *************************************************/
extern void CircularBufferReset(CircularBuffer *cBuf);

/*************************************************
 Function: circularBufferPush.
 Description: push data to the tail of a circular buffer
 Input: cBuf,the circular buffer where data to be pushed; src, the data source buffer to be push from; length, the data length for push.
 Output: none.
 Return: none.
 Disscusion: incase of overflow, the earlier written data in buffer will be covered by newly added data.
 *************************************************/
extern void circularBufferPush(CircularBuffer *cBuf,void *src, size_t length);


/*************************************************
 Function: CircularBufferPop.
 Description: pop data from a circular buffer.
 Input: cBuf,the circular buffer where data to be popped from; length, the length of data in byte wish to be popped out
 Output: dataOut, the output buffer to hold the popped data.
 Return: the actual data length popped out in bytes, it is less or equal to the input length parameter.
 *************************************************/
extern size_t CircularBufferPop(CircularBuffer *cBuf, size_t length, void *dataOut);

/*************************************************
 Function: CircularBufferRead.
 Description: read data from a circular buffer. this function only read
 Input: cBuf,the circular buffer where data to be read from; length, the length of data in byte wish to be read out
 Output: dataOut, the output buffer to hold the read data.
 Return: the actual data length read out in bytes, it is less or equal to the input length parameter.
 *************************************************/
extern size_t CircularBufferRead(CircularBuffer *cBuf, size_t length, void *dataOut);


// for test log
extern void logCircularBuffer(CircularBuffer cBuf);

#endif
