# Vectors - Dynamic Array Implementation in C

A simple yet powerful implementation of dynamic arrays (vectors) in C, inspired by concepts from [tsoding](https://github.com/tsoding).

## Overview

This project provides a lightweight, macro-based vector implementation that allows you to work with dynamic arrays in C without the complexity of manual memory management for common operations.

## Features

- **Dynamic Memory Management**: Automatically grows when capacity is exceeded
- **Type-Safe Operations**: Works with any data type (primitives and structs)
- **Macro-Based API**: Clean, intuitive interface using C macros
- **Zero Dependencies**: Pure C, no external libraries required

## Core Operations

### `vecAlloc(elemSize)` - Allocate a new vector

```c
Student *students = vecAlloc(sizeof(Student));
```

### `push(vec, val)` - Add element to vector

```c
push(students, ((Student){1, "Aman"}));
push(students, ((Student){2, "Sara"}));
```

### `pop(vec)` - Remove last element

```c
pop(students);
```

### `peek(vec, defaultVal)` - Get last element without removing

```c
Student last = peek(students, ((Student){0, "None"}));
```

### `len(vec)` - Get vector size

```c
printf("Size: %zu\n", len(students));
```

### `isEmpty(vec)` - Check if vector is empty

```c
if (isEmpty(students)) {
    printf("Vector is empty\n");
}
```

## Example Usage

```c
#include "vector.h"

typedef struct {
    int id;
    char *name;
} Student;

int main() {
    Student *students = vecAlloc(sizeof(Student));

    push(students, ((Student){1, "Aman"}));
    push(students, ((Student){2, "Sara"}));

    printf("Vector size: %zu\n", len(students));
    printf("Last student: %s\n", peek(students, ((Student){0, "None"})).name);

    pop(students);

    return 0;
}
```

## Implementation Details

- **Header-Only Magic**: Uses `#define VECTOR_IMPLEMENTATION_` to include implementation
- **Memory Layout**: Stores metadata (size, capacity) before actual data
- **Growth Strategy**: Capacity grows by 1.5x when full
- **Flexible Allocation**: Initial capacity of 64 elements per type

## Files

- `vector.h` - Main header with vector interface and implementation
- `main.c` - Example usage with Student struct
- `MakeFile` - Build configuration

## Inspiration

This implementation is inspired by the work and tutorials at [tsoding](https://github.com/tsoding), which provides excellent resources for learning low-level programming concepts in C.

## Future Enhancements

We have exciting plans to extend this vector library with multi-dimensional support:

### Planned Features

- **2D Vectors (Matrices)**: Dynamic 2D array implementation with automatic resizing and flexible dimensions
  - Support for row-major and column-major layouts
  - Efficient matrix operations
- **3D Vectors (Tensors)**: Three-dimensional dynamic array support
  - Ideal for scientific computing and graphics applications
  - Flexible reshaping and slicing operations

- **nD Vectors (General Tensors)**: Generalized n-dimensional array support
  - Arbitrary dimension support using dimension descriptors
  - Automatic stride calculation for efficient memory access
  - Broadcasting operations across dimensions

### Implementation Roadmap

1. **Phase 1**: Stable 1D vector library (current)
2. **Phase 2**: 2D vector/matrix implementation
3. **Phase 3**: 3D tensor support
4. **Phase 4**: General nD tensor framework with shape manipulation

These enhancements will maintain the same clean macro-based API philosophy while adding powerful multi-dimensional capabilities.

## License

See LICENSE file for details.
