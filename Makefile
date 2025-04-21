SRCS	=			draw.c init.c input_controls.c julia.c main.c mandelbrot.c \
					fract_utils.c utils.c
OBJS	=			$(SRCS:.c=.o)
CC		=			cc
RM		=			rm -f
CFLAGS	=			-Wall -Wextra -Werror
NAME	=			fractol

MLX_PATH = minilibx
MLX_NAME = libmlx.a
MLX_LIB = $(MLX_PATH)/$(MLX_NAME)

all:				$(MLX_LIB) $(NAME)

$(MLX_LIB):
					make -sC $(MLX_PATH)

$(NAME):			$(OBJS) $(MLX_LIB)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
clean:
					$(RM) $(OBJS)
					make clean -C $(MLX_PATH)

fclean:	clean
					$(RM) $(NAME)
					
re:		fclean all

.PHONY:	all clean fclean re