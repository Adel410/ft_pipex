# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 16:48:37 by ahadj-ar          #+#    #+#              #
#    Updated: 2024/05/27 14:21:03 by ahadj-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
## ARGUMENTS


NAME = libft.a


SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes


LIBFT_DIR = $(SRC_DIR)/libft
PRINTF_DIR = $(SRC_DIR)/ft_printf


SRC_LIBFT = $(wildcard $(LIBFT_DIR)/*.c)
SRC_PRINTF = $(wildcard $(PRINTF_DIR)/*.c)


OBJ = $(SRC_LIBFT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
      $(SRC_PRINTF:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

