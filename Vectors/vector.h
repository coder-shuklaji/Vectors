#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdio.h>

#define CAP 64
typedef struct
{
    size_t size;
    size_t capacity;
} vecHead;

void *vecAlloc(size_t elemSize);
#define getHead(vec) ((vecHead *)(vec) - 1)
#define len(vec) (getHead((vec))->size)
#define push(vec, val)                         \
    do                                         \
    {                                          \
        (vec)[getHead((vec))->size++] = (val); \
    } while (0)

#define isEmpty(vec) (getHead((vec))->size == 0)
#define pop(vec)                                                        \
    do                                                                  \
    {                                                                   \
        if (isEmpty((vec)))                                             \
        {                                                               \
            char *msg = "\nNo Elements in the Array..\nAccess Denied!"; \
            fprintf(stderr, msg);                                       \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
        getHead((vec))->size--;                                         \
    } while (0)

#define peek(vec, defaultVal) (isEmpty((vec)) ? (perror("Empty Array."), (defaultVal)) : (vec)[getHead((vec))->size - 1])

#ifndef VECTOR_IMPLEMENTATION_

void *vecAlloc(size_t elemSize)
{
    void *vector = malloc(sizeof(vecHead) + (elemSize * CAP));
    vecHead *head = (vecHead *)vector;
    head->size = 0;
    head->capacity = CAP;
    return (char *)vector + sizeof(vecHead);
}

#endif // VECTOR_IMPLEMENTATION_

#endif // VECTOR_H_