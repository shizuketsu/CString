#include <stdio.h>
#include "str.h"

int main(void)
{
    printf("Include str.h\n");
    str_t* str = createStr(20, "Hello, world");
    printf("%s\n", getStr(str));
    return 0;
}