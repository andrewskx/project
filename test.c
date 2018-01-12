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
	ft_printf("%#.0x\n", 0);
	printf("%#.0x\n", 0);
	ft_printf("%#.6o\n", 123456);
	printf("%#.6o\n", 123456);
	ft_printf("%c\n", (void*)0);
	printf("%c\n", 0);
	return (0);
}
