#include <stdio.h>
#include "str.h"

int main(void)
{
    printf("Include str.h\n");
    str_t* str = createStr(20, "aboba123");
    str_t* str2 = createStr(20, "aboba");
    copyStr(str, str2);
    printf("%s\n", str2->data);
    return 0;
}