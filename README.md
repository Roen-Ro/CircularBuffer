# CircularBuffer

## Difinition

 The difinition of [circular buffer](https://en.wikipedia.org/wiki/Circular_buffer) from Wikipedia:

A circular buffer, circular queue, cyclic buffer or ring buffer is a data structure that uses a single, fixed-size buffer as if it were connected end-to-end. This structure lends itself easily to buffering data streams.

A circular buffer first starts empty and of some predefined length. For example, this is a 7-element buffer:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Circular_buffer_-_empty.svg/500px-Circular_buffer_-_empty.svg.png)

Assume that a 1 is written into the middle of the buffer (exact starting location does not matter in a circular buffer):

![](https://upload.wikimedia.org/wikipedia/commons/thumb/8/89/Circular_buffer_-_XX1XXXX.svg/500px-Circular_buffer_-_XX1XXXX.svg.png)

Then assume that two more elements are added — 2 & 3 — which get appended after the 1:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d7/Circular_buffer_-_XX123XX.svg/500px-Circular_buffer_-_XX123XX.svg.png)

If two elements are then removed from the buffer, the oldest values inside the buffer are removed. The two elements removed, in this case, are 1 & 2, leaving the buffer with just a 3:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/1/11/Circular_buffer_-_XXXX3XX.svg/500px-Circular_buffer_-_XXXX3XX.svg.png)

If the buffer has 7 elements then it is completely full:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/6/67/Circular_buffer_-_6789345.svg/500px-Circular_buffer_-_6789345.svg.png)

A consequence of the circular buffer is that when it is full and a subsequent write is performed, then it starts overwriting the oldest data. In this case, two more elements — A & B — are added and they overwrite the 3 & 4:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/b/ba/Circular_buffer_-_6789AB5.svg/500px-Circular_buffer_-_6789AB5.svg.png)

Alternatively, the routines that manage the buffer could prevent overwriting the data and return an error or raise an exception. Whether or not data is overwritten is up to the semantics of the buffer routines or the application using the circular buffer.

Finally, if two elements are now removed then what would be returned is not 3 & 4 but 5 & 6 because A & B overwrote the 3 & the 4 yielding the buffer with:

![](https://upload.wikimedia.org/wikipedia/commons/thumb/4/43/Circular_buffer_-_X789ABX.svg/500px-Circular_buffer_-_X789ABX.svg.png)

## Interfaces
``` C
typedef struct s_circularBuffer* CircularBuffer;

// Construct CircularBuffer with ‘size' in byte. You must call CircularBufferFree() in balance for destruction.
extern CircularBuffer CircularBufferCreate(size_t size);

// Destruct CircularBuffer 
extern void CircularBufferFree(CircularBuffer cBuf);

// Reset the CircularBuffer
extern void CircularBufferReset(CircularBuffer cBuf);

// get the buffer capacity
extern size_t CircularBufferGetCapacity(CircularBuffer cBuf);

//get occupied data size of CircularBuffer
extern size_t CircularBufferGetDataSize(CircularBuffer cBuf);

// Push data to the tail of a circular buffer from 'src' with 'length' size in byte.
extern void CircularBufferPush(CircularBuffer cBuf,void *src, size_t length);

// Pop data from a circular buffer to 'dataOut'  with wished 'length' size in byte,return the actual data size in byte popped out,which is less or equal to the input 'length parameter.
extern size_t CircularBufferPop(CircularBuffer cBuf, size_t length, void *dataOut);

// Read data from a circular buffer to 'dataOut'  with wished 'length' size in byte,return the actual data size in byte popped out,which is less or equal to the input 'length parameter.
extern size_t CircularBufferRead(CircularBuffer cBuf, size_t length, void *dataOut);

//for test purpose, print the circular buffer's data content by printf(...); the 'hex' parameters indicates that if the data should be printed in asscii string or hex data format.
extern void CircularBufferPrint(CircularBuffer cBuf, bool hex);

```


## Author

Roen(罗亮富), zxllf23@163.com

## Licenses

All source code is licensed under the MIT License
