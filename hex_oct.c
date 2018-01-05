#include "ft_printf.h"

char    *ft_capitalize(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
       i++;
    }
   return (str);
}

char    *reverse_string(char *str)
{
    char    temp;
    int     len;
    int     stop;
    int     i;
    int     k;

    len = ft_strlen(str) - 1;
    stop = len / 2;
    i = 0;
    k = len;
    while (i <= stop)
    {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
        i++;
        k--;
    }
    return (ft_strdup(str));
}

char    *ft_hex(uint64_t num, char x)
{
    char    buff[65];
    int     i;
    int     rest;

    i = 0;
    while (num)
    {
        rest = num % 16;
        if (!rest)
            buff[i] = '0';
        if (rest > 0 && rest < 10)
            buff[i] = '0' + rest;
        if (rest > 9)
            buff[i] = 'a' + (rest - 10);
        num /= 16;
        i++;
    }
    buff[i] = '\0';
    if (x == 'x')
        return (reverse_string(buff));
    return (ft_capitalize(reverse_string(buff)));
}

char    *ft_oct(uint64_t num)
{
    char    buff[65];
    int     i;
    int     rest;

    i = 0;
    while (num)
    {
        rest = num % 8;
        if (!rest)
            buff[i] = '0';
        if (rest > 0)
            buff[i] = '0' + rest;
        num /= 8;
        i++;
    }
    buff[i]= '\0';
    return (reverse_string(buff));
}
