# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 12:38:18 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/07/20 13:08:59 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### ARGUMENTS

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = ./srcs
INCDIR = ./include
LIBFTDIR = ./Libft
LIBFT = $(LIBFTDIR)/libft.a

## SOURCES
SRC = $(wildcard $(SRCDIR)/*.c)

OBJ = $(SRC:.c=.o)

################################################################################
### RULES

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCDIR) -o $(NAME) $(OBJ) -L$(LIBFTDIR) -lft

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR)/includes -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
