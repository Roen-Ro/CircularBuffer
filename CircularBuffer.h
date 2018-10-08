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

} CircularBuffer;



// Construct CircularBuffer with ‘size' in byte. You must call CircularBufferFree() in balance for destruction.
extern CircularBuffer CircularBufferCreate(size_t size);

// Destruct CircularBuffer 
extern void CircularBufferFree(CircularBuffer *cBuf);

// Reset the CircularBuffer
extern void CircularBufferReset(CircularBuffer *cBuf);


// Push data to the tail of a circular buffer from 'src' with 'length' size in byte.
extern void CircularBufferPush(CircularBuffer *cBuf,void *src, size_t length);

// Pop data from a circular buffer to 'dataOut'  with wished 'length' size in byte,return the actual data size in byte popped out,which is less or equal to the input 'length parameter.
extern size_t CircularBufferPop(CircularBuffer *cBuf, size_t length, void *dataOut);

// Read data from a circular buffer to 'dataOut'  with wished 'length' size in byte,return the actual data size in byte popped out,which is less or equal to the input 'length parameter.
extern size_t CircularBufferRead(CircularBuffer *cBuf, size_t length, void *dataOut);


// for test log
extern void logCircularBuffer(CircularBuffer cBuf);

#endif
