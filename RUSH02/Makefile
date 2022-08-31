# comentarios
TARGET = rush-02
OBJS = compare_with_array.c main.c math_functions.c read_number2.c reader.c control_error.c ft_parser_dict.c
CFLAGS = -Wall -Wextra -Werror

$(TARGET): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

.PHONY: fclean
fclean:
	rm -f *.o $(TARGET)
