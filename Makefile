# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:56:08 by pibouill          #+#    #+#              #
#    Updated: 2025/04/25 08:45:45 by pibouill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
FT				= libft
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM 				= rm -rf
AR 				= ar rc
SRC_DIR			= src
INC_DIR			= inc
OBJ_DIR			= obj
STATIC_ANALYZER	:=	scan-build --use-cc=clang -enable-checker alpha.core
CLANG_TIDY		:=	clang-tidy --checks=clang-analyzer*,portability.* --warnings-as-errors=* --header-filter=.*

# **************************************************************************** #
# COLORS

RED				:=	[38;5;9m
GREEN			:=	[38;5;10m
BLUE			:= 	[38;5;14m
YELLOW			:=	[38;5;226m
RESET			:=	[38;5;7m
PREFIX			=	[$(GREEN)$(FT)$(RESET)]\t\t\t\t\t

#GREEN			= \033[0;92m
#YELLOW			= \033[0;93m
#BLUE			= \033[0;94m
#END_COLOR		= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES		=		ft_atoi\
						ft_atoi_base\
						ft_atol\
						ft_bzero\
						ft_calloc\
						ft_digitcount\
						ft_intlen\
						ft_isalnum\
						ft_isalpha\
						ft_isascii\
						ft_isdigit\
						ft_isprint\
						ft_itoa\
						ft_lstadd_back\
						ft_lstadd_front\
						ft_lstclear\
						ft_lstdelone\
						ft_lstiter\
						ft_lstlast\
						ft_lstmap\
						ft_lstnew\
						ft_lstsize\
						ft_memchr\
						ft_memcmp\
						ft_memcpy\
						ft_memmove\
						ft_memset\
						ft_print_bits\
						ft_printf\
						ft_putchar\
						ft_putchar_fd\
						ft_putendl_fd\
						ft_putnbr\
						ft_putnbr_fd\
						ft_putstr\
						ft_putstr_fd\
						ft_split\
						ft_str_arr_len\
						ft_strchr\
						ft_strdup\
						ft_striteri\
						ft_strjoin\
						ft_strlcat\
						ft_strlcpy\
						ft_strlen\
						ft_strmapi\
						ft_strncmp\
						ft_strnstr\
						ft_strrchr\
						ft_strtrim\
						ft_substr\
						ft_tolower\
						ft_toupper\
						get_next_line\
						ft_printf_utils\
						ft_wordcount\
						ft_printf_fd\
						ft_printf_fd_utils\
						ft_strndup\
						ft_puts\
						ft_realloc

SRC					= $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ 				= $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# **************************************************************************** #
# RULES

all: $(NAME)

$(NAME): $(OBJ)
	+@$(AR) $(NAME) $(OBJ)
	+@echo "$(PREFIX)$(NAME) compiled."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	+@$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@

$(OBJ_DIR):
	+@mkdir $(OBJ_DIR)
	+@echo "$(PREFIX)Created $(OBJ_DIR)/ directory at libft/"

clean:
	+@$(RM) $(OBJ_DIR)
	+@echo "$(PREFIX)libft obj/ cleaned."

fclean: clean
	+@$(RM) $(NAME)
	+@echo "$(PREFIX)$(NAME).a cleaned."

re: fclean all
	+@echo "$(PREFIX)Cleaned all and rebuilt $(NAME)"

analyze: fclean
	$(STATIC_ANALYZER) make
	$(CLAING_TIDY) $(SRC) -- -Iinc -Ilibft/inc

# static code analysis
scan: fclean
	$(STATIC_ANALYZER) make

# code quality check
tidy: fclean
	$(CLANG_TIDY) $(SRC) -- -Iinc -Ilibft/inc

# **************************************************************************** #

.PHONY: all clean fclean re
