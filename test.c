#include "ft_printf.h"
void    ft_test(char *str, int nbr)
{
	int ret1;
	int ret2;

	ret1 = ft_printf(str, nbr);
	ret2 = printf(str, nbr);
	printf("return1 -> |%d|, return2 -> |%d|\n\n", ret1, ret2);
}
int	main()
{
	printf("%hhld", 128);
	return (0);
}
