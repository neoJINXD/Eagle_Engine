#ifdef MEM_LEAK
#include <stdio.h>

void* operator new(size_t size, const char* file, int line)
{
    printf("Allocating %i bytes in file: %s at line: %i\n\n", size, file, line);
    // printf(file);
    return malloc(size);
}
#define DEBUG_NEW new(__FILE__, __LINE__)
#define new DEBUG_NEW
#endif