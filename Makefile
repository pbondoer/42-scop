# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 21:02:30 by pbondoer          #+#    #+#              #
#    Updated: 2018/01/24 18:10:28 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= scop

# directories
SRC_DIR	:= ./src
LIB_DIR	:= ./lib
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj

# src / obj files
SRC		:=	test.c

OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# compiler
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -O3 -march=native -pipe

# libraries
L_GLFW	:= $(LIB_DIR)/glfw
L_FT	:= $(LIB_DIR)/libft
L_PRINTF:= $(LIB_DIR)/printf

# include $(L_FT)/libft.mk
include $(LIB_DIR)/glfw.mk
include $(L_FT)/libft.mk
include $(L_PRINTF)/libprintf.mk

# rules
all:
	cd $(L_GLFW) && cmake .
	@$(MAKE) -C $(L_GLFW) glfw --no-print-directory
	@$(MAKE) -C $(L_FT) --no-print-directory
	@$(MAKE) -C $(L_PRINTF) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory
	@echo "[scop] 🎉"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) $(LIB_INC) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) $(LIB_LNK) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relibs:
	@$(MAKE) -C $(L_GLFW) clean --no-print-directory
	@$(MAKE) -C $(L_GLFW) glfw --no-print-directory
	@$(MAKE) -C $(L_FT) re --no-print-directory
	@$(MAKE) -C $(L_PRINTF) re --no-print-directory
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

cleanlibs:
	@$(MAKE) -C $(L_GLFW) clean --no-print-directory
	@$(MAKE) -C $(L_FT) fclean --no-print-directory
	@$(MAKE) -C $(L_PRINTF) fclean --no-print-directory

# special rules
.PHONY: all clean fclean re relibs
.PRECIOUS: auteur
