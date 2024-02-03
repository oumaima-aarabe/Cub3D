# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 22:41:52 by ichaiq            #+#    #+#              #
#    Updated: 2023/12/22 03:45:53 by ouaarabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -g -fsanitize=address -Ofast# -Wall -Wextra -Werror 
LIBMLX	:= ./includes/MLX42/
HEADERS	:= -I$(LIBMLX)/include/MLX42/ -I./includes/gnl/
GFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
GLFW_PATH = /Users/$(USER)/.brew/opt/glfw/lib
# GLFW_PATH = /goinfre/$(USER)/.brew/opt/glfw/lib/
LDFLAGS = -Iinclude -lglfw -L$(GLFW_PATH)
EX = ./includes/MLX42/build/libmlx42.a
SRCDIR = src
OBJDIR = obj
SRCS = $(shell find $(SRCDIR) -type f -name '*.c')
SRCS := $(addprefix src/,$(SRCS))
OBJECTS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
DEPS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.d, $(SRCS))
INCLUDES_DIR = includes
DEPSFLAGS = -MMD -MP
INCLUD = src/
#  incldues/MLX42/include/MLX42/
LIB = $(INCLUDES_DIR)/libft/libft.a
GNL_SRC = $(shell find $(INCLUDES_DIR)/gnl/ -type f -name '*_bonus.c')

all: $(NAME)
# @mkdir -p $(@D)

$(NAME): $(OBJECTS) $(LIB) $(EX)
	$(CC) $(CFLAGS) $(OBJECTS) $(EX) $(LIB) -o $(NAME)  $(LDFLAGS) $(GNL_SRC) $(HEADERS) -lm -g

$(OBJDIR)/%.o: %.c $(INCLUD)
	@mkdir -p $(dir $@)
	$(CC) $(DEPSFLAGS) $(CFLAGS) -c $< -o $@ -Imlx

$(LIB): $(INCLUDES_DIR)/libft/libft.h
	make bonus -C $(INCLUDES_DIR)/libft

clean:
	rm -rf $(OBJDIR)
	make clean -C $(INCLUDES_DIR)/libft/

	@echo "Cleaning objects"

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(INCLUDES_DIR)/libft/

	@echo "Cleaning objects and executable"

re: fclean all
-incldue : $(DEPS)
.PHONY: all clean fclean re
# .PRECIOUS: $(OBJECTS)