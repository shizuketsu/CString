#ifndef STR
#define STR

#include <stdlib.h>

typedef struct str {
    char* data;
    int length;
} str_t;

str_t* setStr(str_t* str, char* data);
void freeStr(str_t* str);
char* getStr(str_t* str);

str_t* createStr(int length, char* data)
{
    str_t* string = (str_t*)malloc(sizeof(str_t));
    if(string == NULL)
    {
        perror("Failed to allocate memory for str_t");
        return NULL;
    }

    string->data = (char*)malloc(sizeof(char) * length + 1);
    if(string->data == NULL)
    {
        perror("Failed to allocate memory for str_t->data");
        free(string);
        return NULL;
    }

    string->length = length;
    setStr(string, data);

    return string;
}

void freeStr(str_t* str)
{
    free(str->data);
    free(str);
}

str_t* setStr(str_t* str, char* data) // она, наверное, не должна возвращать строку
{
    if(str == NULL || data == NULL) return NULL;
    
    int i = 0;
    while(i < str->length)
    {
        if(data[i] == '\0') 
        {
            str->data[i] = '\0';
            break;
        }

        str->data[i] = data[i];
        i++;
    }

    str->data[str->length] = '\0';
    return str;
}

char* getStr(str_t* str)
{
    return str->data;
}

int getStrLength(str_t* str)
{
    if(str == NULL) return 0;

    int i = 0;
    while(i < str->length)
    {
        if(str->data[i] == '\0') return i;
        
        i++;
    }

    return i;
}

#endif