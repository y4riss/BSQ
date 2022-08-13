SRC = srcs/main.c \
		srcs/helpers/ft_strdup.c srcs/helpers/ft_strlen.c srcs/helpers/valid_map.c\
 		srcs/helpers/bsq_algorithm.c srcs/helpers/print_matrix.c srcs/helpers/ft_putstr.c\
 		srcs/helpers/create_matrix.c srcs/helpers/ft_read.c
TARGET = bsq
INCLUDES = includes
CFLAGS = -Wall -Wextra -Werror
all : 
	gcc $(CFLAGS) $(SRC) -o $(TARGET) -I $(INCLUDES)

clean : 
	@:	

fclean : clean
	rm -f $(TARGET)

.PHONY : all clean fclean
