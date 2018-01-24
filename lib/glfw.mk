# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    glfw.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 17:36:33 by pbondoer          #+#    #+#              #
#    Updated: 2018/01/24 17:41:10 by pbondoer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Base variables for glfw
# Use with 'include /path/to/glfw.mk'
# Make sure to define L_GLFW with path to glfw first

L_GLFW		?= ./glfw

GLFW_NAME	:= libft.a

GLFW_LNK	:= -L $(L_GLFW)/src -l glfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
GLFW_INC	:= -I $(L_GLFW)/include
GLFW_LIB	:= $(L_FT)/$(FT_NAME)

# Global variables for compilation
ifndef LIB_LNK
LIB_LNK		:=
LIB_INC		:=
endif

LIB_LNK		+= $(GLFW_LNK)
LIB_INC		+= $(GLFW_INC)
