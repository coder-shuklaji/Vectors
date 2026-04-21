#define VECTOR_IMPLEMETATION_
#include "vector.h"

int main()
{
    char **stringArr = (char **)vecAlloc(sizeof(char *));
    push(stringArr, "Hello!");
    push(stringArr, "Vectors");

    for (size_t i = 0; i < len(stringArr); i++)
    {
        printf("%s ", stringArr[i]);
    }

    char *s1 = pop(stringArr);
    char *s2 = pop(stringArr);
    char* s3 = pop(stringArr);
    printf("%s, %s", s1, s2);
    printf("%s", s3);
    printf("\n");
    return 0;
}