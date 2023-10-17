# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:56:08 by pibouill          #+#    #+#              #
#    Updated: 2023/10/17 11:14:51 by pibouill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
DIRS		= libft
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= rm
AR 			= ar rc
# **************************************************************************** #
# COLORS

GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
END_COLOR	= \033[0;39m

# **************************************************************************** #
# SOURCES

SRCS 		= 	ft_isalnum\
				ft_isalpha\
				ft_isascii\
				ft_isdigit\

SRC				= $(addsuffix .c, $(SRCS))
OBJ 			= $(addsuffix .o, $(SRCS))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled. $(DEF_COLOR)"

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(BIN_DIR)
	@$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@
	@echo "$(BLUE)Compiling... $(notdir $<) in $(DIRS) $(END_COLOR)"

clean:
	@rm -rf $(OBJ)
	@echo "$(YELLOW)$(NAME) object files cleaned.$(END_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) .a file cleaned.$(END_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME)$(END_COLOR)"

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re
