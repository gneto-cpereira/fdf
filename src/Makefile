NAME    = fdf.a
OBJ_DIR = obj
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.. -I../libft -I../mlx_linux
RM      = rm -rf

# Encontrar fontes
SRCS    = fdf.c map_reader.c $(wildcard window_functions/*.c)
# Mapear objetos para a pasta obj/ mantendo a estrutura
OBJS    = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Progress Bar
TOTAL   = $(words $(SRCS))
CURR    = 0

define progress
    $(eval CURR=$(shell echo $$(($(CURR) + 1))))
    @printf "\r\033[32mFdF   [%-$(TOTAL)s] %d/%d\033[0m" $$(printf "%$(CURR)s" | tr ' ' '#') $(CURR) $(TOTAL)
endef

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo ""

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/window_functions

$(OBJ_DIR)/%.o: %.c
	@$(progress)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

.PHONY: all clean fclean