exe : ft_printf.c ft_printf.h hex_oct.c libft/*.c libft/libft.h
		make -C libft/
		gcc  ft_printf.c test.c conversion_manage.c compose.c   print_format.c char_wchar.c width_precision_len_conv.c  hex_oct.c -I ft_printf.h -I libft/libft.h libft/libft.a -o exe
re :
	make -C libft/
	gcc  char_wchar.c test.c  print_format.c conversion_manage.c  compose.c  width_precision_len_conv.c  hex_oct.c  ft_printf.c -I ft_printf.h -I libft/libft.h libft/libft.a -o exe
