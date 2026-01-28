NAME    = libft.a
OBJ_DIR = obj
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -ffunction-sections -fdata-sections
RM      = rm -rf

SRCS    = $(shell find . -name "*.c" | sed 's|^\./||')
OBJS    = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

TOTAL   = $(words $(SRCS))
CURR    = 0

define progress
    $(eval CURR=$(shell echo $$(($(CURR) + 1))))
    @printf "\r\033[32mLibft [%-$(TOTAL)s] %d/%d\033[0m" $$(printf "%$(CURR)s" | tr ' ' '#') $(CURR) $(TOTAL)
endef

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\nLibft archive created."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(sort $(dir $(OBJS)))

$(OBJ_DIR)/%.o: %.c
	@$(progress)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re