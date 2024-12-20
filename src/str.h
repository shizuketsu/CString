#ifndef STR
#define STR

#include <stdlib.h>
#include <wchar.h>
#include <stdio.h> // TODO: delete in production

typedef struct str {
    char* data;
    int length;
} str_t;

str_t* setStr(str_t* str, const char* data);
void freeStr(str_t* str);
char* getStr(str_t* str);
int getStrLength(str_t* str);
str_t* catStr(str_t* right, str_t* left);

str_t* createStr(int length, const char* data)
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

str_t* setStr(str_t* str, const char* data)
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

str_t* catStr(str_t* right, str_t* left)
{
    if(right == NULL || left == NULL || right->data == NULL || left->data == NULL) return NULL;

    int right_length = getStrLength(right);
    int left_length = getStrLength(left);
    int total_length = right_length + left_length;

    str_t* result = createStr(total_length, "");
    if(result == NULL) return NULL;

    int i = 0;

    for(int j = 0; j < right_length; j++) 
    {
        result->data[i] = right->data[j];
        i++;
    }

    for(int j = 0; j < left_length; j++) 
    {
        result->data[i] = left->data[j];
        i++;
    }

    result->data[result->length] = '\0';
    return result;
}

#endif