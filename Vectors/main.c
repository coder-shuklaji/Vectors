#define VECTOR_IMPLEMETATION_
#include "vector.h"

int main()
{
    int *nums = (int *)vecAlloc(sizeof(int));
    for (int i = 0; i <= 25; i++)
    {
        push(nums, i * i);
    }

    for (size_t i = 0; i < len(nums); i++)
    {
        printf("%d ", nums[i]);
    }

    pop(nums);
    pop(nums);
    int last = peek(nums, 0);
    printf("\n%d", last);

    printf("\n");
    return 0;
}

//(getHead((vec))->size > 0 ? (vec)[(getHead((vec))->size) - 1] : (fprintf(stderr, "\nArray is Empty.."), exit(EXIT_FAILURE), 0))
