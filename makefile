NAME = so_long

SRCDIR = src
INCDIR = include
MLXDIR = MLX42/MLX42
LIBFTDIR = ./libft

SRCS = $(SRCDIR)/game.c hooks.c loop.c path.c player.c render.c cleanup.c \
       $(SRCDIR)/map.c \
       $(SRCDIR)/map_check.c \
       $(SRCDIR)/utils.c
OBJS = $(SRCS:.c=.o)
INCLUDE = -I$(INCDIR) -I$(MLXDIR)/include -I$(LIBFTDIR)
LIBFT = $(LIBFTDIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_LIB = $(MLXDIR)/libmlx42.a -ldl -lglfw -lm

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)
$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re