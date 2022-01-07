CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

SRC = srcs/main.c\
	srcs/erreurs.c\
	srcs/so_long_utils.c\
	srcs/get_next_line.c\
	srcs/get_next_line_utils.c\
	srcs/ft_split.c\
	srcs/render.c\
	srcs/keysym.c\
	srcs/ft_maperror.c\
	srcs/ft_split_utils.c

SRC_BONUS = bonus/b_main.c\
	bonus/b_erreurs.c\
	bonus/b_so_long_utils.c\
	bonus/b_get_next_line.c\
	bonus/b_get_next_line_utils.c\
	bonus/b_split.c\
	bonus/b_render.c\
	bonus/b_keysym.c\
	bonus/b_maperror.c\
	bonus/b_split_utils.c\
	bonus/b_bonus.c\
	bonus/ft_itoa.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $(OBJ) -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

.c.o:
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o $@

bonus: ${OBJ_BONUS}
	$(CC) $(OBJ_BONUS) -Lmlx_linux -L/usr/lib -Imlx_linux -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f ${OBJ} ${OBJ_BONUS}

fclean:	clean
	rm -f ${NAME}

re: fclean all
