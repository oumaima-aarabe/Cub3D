# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 22:41:52 by ichaiq            #+#    #+#              #
#    Updated: 2024/01/14 00:28:11 by ichaiq           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_BONUS = cub3d_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast

LIBMLX	:= /Users/$(USER)/Desktop/MLX42

HEADERS	:= -I$(LIBMLX)/include/MLX42/ -I./includes/gnl/

GFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

GLFW_PATH = /goinfre/$(USER)/.brew/opt/glfw/lib/

LDFLAGS = -Iinclude -lglfw -L$(GLFW_PATH)

EX = $(LIBMLX)/build/libmlx42.a

SRCDIR = src
SRCBDIR = src_bonus

OBJDIR = obj
OBJBDIR = obj_bonus

SRCS = ./src/gameplay/player.c\
		./src/main.c\
		./src/parser/config_utils.c\
		./src/parser/map_converter.c\
		./src/parser/map_utils.c\
		./src/parser/map_validator.c\
		./src/parser/parser.c\
		./src/parser/texture_parser.c\
		./src/parser/validators_utils.c\
		./src/render/calcul_rays.c\
		./src/render/cast_rays.c\
		./src/render/drawers.c\
		./src/render/mlx_inits.c\
		./src/render/mlx_utils.c\
		./src/render/render.c\
		./src/render/render_utils.c\
		./src/render/textures.c\
		./src/utils/clean_exit.c\
		./src/utils/f_utils.c

SRCS_BONUS = ./src_bonus/gameplay/player.c\
		./src_bonus/main.c\
		./src_bonus/parser/config_utils.c\
		./src_bonus/parser/map_converter.c\
		./src_bonus/parser/map_utils.c\
		./src_bonus/parser/map_validator.c\
		./src_bonus/parser/parser.c\
		./src_bonus/parser/texture_parser.c\
		./src_bonus/parser/validators_utils.c\
		./src_bonus/render/calcul_rays.c\
		./src_bonus/render/cast_rays.c\
		./src_bonus/render/drawers.c\
		./src_bonus/render/mlx_inits.c\
		./src_bonus/render/mlx_utils.c\
		./src_bonus/render/render.c\
		./src_bonus/render/render_utils.c\
		./src_bonus/render/textures.c\
		./src_bonus/render/minimap.c\
		./src_bonus/utils/clean_exit.c\
		./src_bonus/utils/f_utils.c

SRC_HDRS = ./src/cub3d.h\
		./src/utils/utils.h\
		./src/render/render.h\
		./src/parser/parser.h\
		./src/gameplay/player.h
		
SRCB_HDRS = ./src_bonus/cub3d.h\
		./src_bonus/utils/utils.h\
		./src_bonus/render/render.h\
		./src_bonus/parser/parser.h\
		./src_bonus/gameplay/player.h
		
SRCS := $(addprefix src/,$(SRCS))
SRCS_BONUS := $(addprefix src_bonus/,$(SRCS_BONUS))

OBJECTS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
OBJECTS_BONUS = $(patsubst $(SRCBDIR)%.c, $(OBJBDIR)%.o, $(SRCS_BONUS))

INCLUDES_DIR = includes

INCLUD = src/

LIB = $(INCLUDES_DIR)/libft/libft.a

GNL_SRC = ./includes/gnl//get_next_line_bonus.c\
			./includes/gnl//get_next_line_utils_bonus.c

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJECTS) $(LIB) $(EX)
	$(CC) $(CFLAGS) $(OBJECTS) $(EX) $(LIB) -o $(NAME)  $(LDFLAGS) $(GNL_SRC) $(HEADERS) -lm
	
$(NAME_BONUS): $(OBJECTS_BONUS) $(LIB) $(EX)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(EX) $(LIB) -o $(NAME_BONUS)  $(LDFLAGS) $(GNL_SRC) $(HEADERS) -lm


$(OBJDIR)/%.o: %.c $(SRC_HDRS)
	@mkdir -p $(dir $@)
	$(CC)  $(CFLAGS) -c $< -o $@ 

$(OBJBDIR)/%.o: %.c $(SRCB_HDRS)
	@mkdir -p $(dir $@)
	$(CC)  $(CFLAGS) -c $< -o $@ 

$(LIB): $(INCLUDES_DIR)/libft/libft.h
	make bonus -C $(INCLUDES_DIR)/libft

clean:
	rm -rf $(OBJDIR)
	rm -rf $(OBJBDIR)
	make clean -C $(INCLUDES_DIR)/libft/

	@echo "Cleaning objects"

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	make fclean -C $(INCLUDES_DIR)/libft/

	@echo "Cleaning objects and executable"

re: fclean all

run: all
	./$(NAME) map.cub

rerun: re
	./$(NAME) map.cub

.PHONY: all clean fclean re
