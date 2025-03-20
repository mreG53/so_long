NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

SRC = src/main.c src/map.c src/get_next_line.c \
	src/get_next_line_utils.c src/map_validate.c \
	src/map_elements.c src/ft_printf.c src/ft_printf_u.c \
	src/hooks.c src/load_images.c src/render.c \
	src/game_utils.c src/move.c src/ft_itoa.c \
	src/inits.c src/set_players.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(MLX_INC)

clean:
	@rm -f $(OBJ)
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@make clean -C $(MLX_DIR)

re: fclean all