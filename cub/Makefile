CC = cc
NAME = cub3D
CFLAGS = -Wall -Wextra -Werror -I./includes/ -I./minilibx-linux -O2 -march=native -g3 -fno-builtin -ffast-math -funroll-loops
LDFLAGS = -lreadline
OBJ_DIR = obj

SRC =	./src/cub3d.c \
		./src/parsing/parsing.c \
		./src/parsing/utils.c \
		./src/parsing/checker.c \
		./src/parsing/checker_bis.c \
		./src/parsing/parse_map.c \
		./src/parsing/parse_map_utils.c \
		./src/parsing/parse_map_helpers.c \
		./src/exec/ft_raycasting.c \
		./src/exec/ft_raycasting_utils.c \
		./src/exec/ft_raycasting_draw.c \
		./src/exec/ft_raycast_core.c \
		./src/exec/ft_raycast_main.c \
		./src/exec/ft_mlx.c \
		./src/exec/ft_mlx_utils.c \
		./src/exec/ft_ssaa.c \
		./src/exec/render_utils.c \
		./src/exec/key_handling.c \
		./src/exec/map_utils.c \
		./src/exec/utils_raycasting.c \
		./src/exec/coords_utils.c \
		./src/exec/map_checks.c \
		./src/exec/check_utils.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DIRS = $(sort $(dir $(OBJ)))

MAKE = make -C

all: $(NAME)


$(NAME): $(OBJ)
	@echo "$(BLUE)Compiling $(NAME)...$(RESET)"
	@$(MAKE) all_libft --no-print-directory
	@make -C ./minilibx-linux > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(OBJ) ./all_libft/libft/libft.a -I/usr/include  -L./minilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"

$(OBJ_DIR)/%.o: %.c | $(DIRS) $(BONUS_DIRS)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIRS) $(BONUS_DIRS):
	@mkdir -p $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) all_libft clean --no-print-directory
	@$(MAKE) ./minilibx-linux clean > /dev/null 2>&1 --no-print-directory

fclean: clean
	@echo "$(RED)Cleaning executables...$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) all_libft fclean --no-print-directory
	@$(MAKE) ./minilibx-linux clean > /dev/null 2>&1 --no-print-directory

re: fclean all

.PHONY: all bonus clean fclean re $(DIRS) $(BONUS_DIRS) rc 
rc:
	@make re --no-print-directory && make clean --no-print-directory


RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m
BOLD   = \033[1m

