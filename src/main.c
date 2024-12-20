#include <stdio.h>
#include "str.h"

int main(void)
{
    printf("Include str.h\n");
    str_t* str = createStr(20, "aboba");
    str_t* str2 = createStr(20, "aboba");
    printf("%s\n", catStr(str, str2)->data);
    return 0;
}