LIBFT_PATH  = ./libs/libft
MLX_PATH  = ./libs/mlx_linux
PROJ_PATH   = ./src
OBJ_DIR     = obj

NAME        = fdf
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(PROJ_PATH)
RM          = rm -rf

LIBFT       = $(LIBFT_PATH)/libft.a
PROJ_LIB    = $(PROJ_PATH)/fdf.a
MLX         = $(MLX_PATH)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRC         = main.c
OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN       = \033[32m
RESET       = \033[0m

all: $(OBJ_DIR) $(MLX) $(LIBFT) $(PROJ_LIB) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(PROJ_LIB) $(LIBFT) $(MLX_FLAGS) -Wl,--gc-sections -o $(NAME)
	@echo "$(GREEN)Final executable $(NAME) ready!$(RESET)"

$(MLX):
	@echo "Compiling MiniLibX..."
	@$(MAKE) -C $(MLX_PATH) > /dev/null 2>&1

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory

$(PROJ_LIB):
	@$(MAKE) -C $(PROJ_PATH) --no-print-directory

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@$(MAKE) -C $(PROJ_PATH) clean --no-print-directory
	@$(MAKE) -C $(MLX_PATH) clean > /dev/null 2>&1
	@$(RM) *.o main.o fdf.o map_reader.o # Limpeza extra de ficheiros órfãos

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@$(MAKE) -C $(PROJ_PATH) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(PROJ_LIB)