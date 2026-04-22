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

// ---------------- Helper Memory Allocation Functions ----------------
void *vecAlloc(size_t elemSize);
void *vecReAlloc(void *vec, size_t elemSize);

// ---------------- Some Basic Helper Macros for PUSH, POP, PEEK operations ----------------
#define getHead(vec) ((vecHead *)(vec) - 1)
#define isFUll(vec) ((getHead((vec))->size == getHead((vec))->capacity))
#define isEmpty(vec) (getHead((vec))->size == 0)
#define len(vec) (getHead((vec))->size)

// ---------------- PUSH MACRO ----------------
#define push(vec, val)                                             \
    do                                                             \
    {                                                              \
        if (isFUll((vec)))                                         \
        {                                                          \
            void *_new_vec = vecReAlloc((vec), sizeof(*(vec)));    \
            if (!_new_vec)                                         \
            {                                                      \
                char *msg = "Buy yourself a New PC with Memory.."; \
                fprintf(stderr, "%s", msg);                        \
                exit(EXIT_FAILURE);                                \
            }                                                      \
            (vec) = _new_vec;                                      \
        }                                                          \
        (vec)[getHead((vec))->size++] = (val);                     \
    } while (0)

// ---------------- POP MACRO ----------------
#define pop(vec)                                                        \
    do                                                                  \
    {                                                                   \
        if (isEmpty((vec)))                                             \
        {                                                               \
            char *msg = "\nNo Elements in the Array..\nAccess Denied!"; \
            fprintf(stderr, "%s", msg);                                 \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
        getHead((vec))->size--;                                         \
    } while (0)

// ---------------- PEEK MACRO ----------------
// first param : vector ptr; second param : should be type of vec
// e.g. if typeOf(vec) == struct {...} call peek(vec, {...})
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

void *vecReAlloc(void *vec, size_t elemSize)
{
    size_t newCapacity = (getHead(vec)->capacity) * 2;
    vecHead *temp = realloc(getHead(vec), sizeof(vecHead) + (elemSize * newCapacity));
    if (!temp)
    {
        perror("Buy More RAM! You are Full..");
        return NULL;
    }
    temp->capacity = newCapacity;
    return (char *)temp + sizeof(vecHead);
}

#endif // VECTOR_IMPLEMENTATION_

#endif // VECTOR_H_