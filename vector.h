#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define CAP 64
typedef struct
{
    size_t size;
    size_t capacity;
} vecHead;

void *vecAlloc(size_t elemSize);
#define len(vec) ((vecHead *)(vec) - 1)->size
#define push(vec, val)                                 \
    do                                                 \
    {                                                  \
        (vec)[((vecHead *)(vec) - 1)->size++] = (val); \
    } while (0)

#define pop(vec) ((vec)[--((vecHead *)(vec) - 1)->size])

#endif // Vector

#ifndef VECTOR_IMPLEMENTATION_

void *vecAlloc(size_t elemSize)
{
    void *vector = malloc(sizeof(vecHead) + (elemSize * CAP));
    vecHead *head = (vecHead *)vector;
    head->size = 0;
    head->capacity = CAP;
    return (char *)vector + sizeof(vecHead);
}
#endif // End of Vector File...