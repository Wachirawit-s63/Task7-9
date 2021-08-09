#include <stdio.h>
#include <stdint.h>
#include <string.h>

char *to_hex(int64_t value)
{
    char HEX_DIGITS[] = "0123456789abcdef";
    static char s[20] = "";
    int64_t one = 1;
    if (value < 0)
    {
        value += (one << 32);
    }
    while(1)
    {
        char d[] = "";
        d[0] = HEX_DIGITS[ value & 0xf ];
        strcat(s,d);
        value >>= 4 ;
        if (value == 0)
        {
            break;
        }
    }
    int len_g, g;
    char rev[20] = ""; //reverse
    int i =0;
    len_g = strlen(s);
    for(g = len_g - 1; g >= 0; g--) 
    {
        rev[i]=s[g];
        i++;
    }
    strcpy(s,rev);    
    char hex[] = "0x";
    strcat(hex,s);
    strcpy(s,hex);
    return s;
}

int main()
{
    char *frist = to_hex(33);
    printf("%s\n",frist);
    char *second = to_hex(-1);
    printf("%s\n",second);
    return 0;
}