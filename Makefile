exe : ft_printf.c ft_printf.h hex_oct.c libft/*.c libft/libft.h
		make -C libft/
		gcc ft_printf.c hex_oct.c -I ft_printf.h -I libft/libft.h libft/libft.a -o exe

