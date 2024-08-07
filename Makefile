# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 12:38:18 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/08/06 16:57:14 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### ARGUMENTS

NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCDIR = ./include
LIBFTDIR = ./Libft
LIBFT = $(LIBFTDIR)/libft.a

## SOURCES
SRC = 	./srcs/ft_error.c \
		./srcs/ft_exec.c \
		./srcs/ft_init.c \
		./srcs/ft_parsing.c \
		./srcs/ft_pipex.c \
		./srcs/ft_access.c \
		./srcs/main.c

SRCBONUS = 	./srcsbonus/ft_error_bonus.c \
			./srcsbonus/ft_init_bonus.c \
			./srcsbonus/ft_parsing_bonus.c \
			./srcsbonus/ft_pipex_bonus.c \
			./srcsbonus/ft_access_bonus.c \
			./srcsbonus/ft_heredoc.c \
			./srcsbonus/get_next_line.c \
			./srcsbonus/main_bonus.c

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

################################################################################
### RULES

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft

$(NAME_BONUS): $(OBJBONUS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $(NAME_BONUS) $(OBJBONUS) -L$(LIBFTDIR) -lft

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR)/includes -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJBONUS)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all bonus clean fclean re
