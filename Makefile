# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:56:08 by pibouill          #+#    #+#              #
#    Updated: 2023/10/19 11:51:18 by pibouill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM 			= rm
INC			= libft.h
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
				ft_isprint\
				ft_memset\
				ft_strchr\
				ft_strlen\
				ft_strrchr\
				ft_tolower\
				ft_toupper\
				ft_memset\
				ft_strchr\
				ft_strlcat\
				ft_strlcpy\
				ft_strncmp\
				ft_strnstr\
				ft_atoi\
				ft_calloc\
				ft_bzero\
				ft_memchr\
				ft_memcmp\
				ft_memcpy\
				ft_memmove\
				ft_strdup\
				ft_substr\
				ft_strjoin\
				ft_strtrim\

SRC				= $(addsuffix .c, $(SRCS))
OBJ 			= $(addsuffix .o, $(SRCS))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled. $(DEF_COLOR)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I $(INC) $< -o $@
	@echo "$(BLUE)Compiling... $< $(END_COLOR)"

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
