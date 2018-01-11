CC=gcc
FLAGS=-Wall -Werror -Wextra
HEADERS=libft/libft.h ft_printf.h
OBJ=*.o
SOURCES=*.c
STATIC=libft/libft.a
TARGET=libftprintf.a

all:	$(TARGET)

$(TARGET):	$(OBJ)
	ar rc $(TARGET) $(OBJ) libft/*.o
	ranlib $(TARGET)

$(OBJ): 
	$(CC) $(SOURCES) -c -I $(HEADERS) $(STATIC)

$(STATIC): 
	make -C libft/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

