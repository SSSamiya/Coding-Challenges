/*
String functions
*/
#include<stdbool.h>

int StringLength(char string[])
{
    int length = 0 , i;

    for(i = 0; string[i] != '\0'; i++ );
    return i;    
}

bool Substring(char *string , char search[]) 
{
    char *p, *q;
    int i;
    p = string;
    q = search;

    // for(i = 0; string[i] != '\0'; i++ )
    while(*p != '\0')
    {
        if(*p == *q)
        {
            p++;
            q++;
            if(*q == '\0')
            {
                return true;
            }
        }
        else
        {
            p++;
            q = search;
        }
    }
    return false;
}