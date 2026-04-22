#include "vector.h"
#define VECTOR_IMPLEMENTATION_

typedef struct
{
    int id;
    char *name;
} Student;

int main()
{
    Student *students = vecAlloc(sizeof(Student));
    push(students, ((Student){1, "Aman"}));
    push(students, ((Student){2, "Sara"}));
    printf("Size: %d\n", len(students));
    printf("Last: %s\n", peek(students, ((Student){0, "None"})).name);
    return 0;
}
