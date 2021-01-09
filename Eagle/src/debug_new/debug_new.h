#ifdef MEM_LEAK // TODO this will be its own thing on other branch
#include <stdio.h>

// void* operator new(size_t size)
// void* operator new(size_t size, const char* file, int line)
// {
//     // printf("Allocating %i bytes in file: %s at line: %i\n", size, file, line);
//     printf("Allocating %i bytes in file: %s at line: %i\n", size, __FILE__, __LINE__);
//     // printf(file);
//     return malloc(size);
// }

// TODO figure out how to ignore this damn annoying error bu not really
void* operator new(size_t size)
{
    printf("Allocating %i bytes\n", size);

    return malloc(size);
}

void operator delete(void* ptr)
{
    printf("Freeing pointer\n");

    free(ptr);
}


// #define DEBUG_NEW new(__FILE__, __LINE__)
// #define new DEBUG_NEW

#define DEBUG_DELETE operator delete
#define delete DEBUG_DELETE

// #define DEBUG_DELETE delete(__FILE__, __LINE__)
// #define delete DEBUG_DELETE

#endif