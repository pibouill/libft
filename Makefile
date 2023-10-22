# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 10:56:08 by pibouill          #+#    #+#              #
#    Updated: 2023/10/22 15:26:10 by pibouill         ###   ########.fr        #
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

SRCS			= 	ft_isalnum\
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
					ft_memset\
					ft_strdup\
					ft_substr\
					ft_strjoin\
					ft_strtrim\
					ft_putchar_fd\
					ft_putstr_fd\
					ft_putendl_fd\
					ft_putnbr_fd\
					ft_itoa\
					ft_strmapi\
					ft_striteri\
					ft_split

BONUS_SRCS		=	ft_lstnew\
					ft_lstadd_front\
					ft_lstsize\
					ft_lstlast\
					ft_lstadd_back\
					ft_lstdelone\
					ft_lstclear\
					ft_lstiter\
					ft_lstmap

SRC				= $(addsuffix .c, $(SRCS))
OBJ 			= $(addsuffix .o, $(SRCS))
BONUS_SRC		= $(addsuffix .c, $(BONUS_SRCS))
BONUS_OBJ 		= $(addsuffix .o, $(BONUS_SRCS))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled $(END_COLOR)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I $(INC) $< -o $@
	@echo "$(BLUE)Compiling... $< $(END_COLOR)"

clean:
	@rm -rf $(OBJ) $(BONUS_OBJ)
	@echo "$(YELLOW)$(NAME) object files cleaned.$(END_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) file cleaned.$(END_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned all and rebuilt $(NAME)$(END_COLOR)"

bonus: $(OBJ) $(BONUS_OBJ)
	@$(AR) $(NAME) $(OBJ) $(BONUS_OBJ)
	@echo "$(GREEN)$(NAME) compiled $(END_COLOR)"

# **************************************************************************** #
# PHONY

.PHONY: all clean fclean re bonus
