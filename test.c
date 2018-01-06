#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(void)
{
	ft_printf("%+10.5i\n", -12);
	printf("%+10.5i\n", -12);
    return (0);
}
