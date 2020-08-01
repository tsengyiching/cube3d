# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/29 11:58:13 by yictseng          #+#    #+#              #
#    Updated: 2020/08/01 19:13:22 by yictseng         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 								VARIABLES									   #
# **************************************************************************** #

# Colors
GREY = \x1b[30m
RED = \x1b[31m
GREEN = \x1b[32m
YELLOW = \x1b[33m
BLUE = \x1b[34m
PURPLE = \x1b[35m
CYAN = \x1b[36m

NAME 			= cub3D
PATH_HEADER		= includes/
PATH_SRCS		= srcs/
HEADER_LIST		= cub3d.h\
				  get_next_line.h\

SRCS_LIST		= check_map.c\
				  check_value.c\
				  check_wall.c\
				  draw_sprite.c\
				  draw_walls.c\
				  get_next_line.c\
				  get_next_line_utils.c\
				  get_texture.c\
				  init_variables.c\
				  main.c\
				  move_in_map.c\
				  parse_element.c\
				  parse_utils.c\
				  parsing.c\
				  print_screen.c\
				  run_cub3d.c\
				  run_raycasting.c\
				  write_error.c\

OBJS			= $(SRCS_LIST:.c=.o)

HEADER			= $(addprefix $(PATH_HEADER), $(HEADER_LIST))

MLX				= minilibx/libmlx.a

LIB_MLX			= -I minilibx -L minilibx -lmlx -framework OpenGL -framework Appkit

CC 				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

# **************************************************************************** #
#  								REGLES									       #
# **************************************************************************** #

all				: $(MLX) $(NAME)

$(PATH_OBJS)%.o	: $(PATH_SRCS)%.c $(HEADER)
				  @echo "$(GREEN)[Compiled]:\t$(CYAN)"$<
			  	  @$(CC) $(CFLAGS) -c $< -I $(HEADER)

$(MLX)			:
			  	  @$(MAKE) -C minilibx/

$(NAME)			: $(OBJS) $(HEADER)
				  @$(CC) $(CFLAGS) $(LIB_MLX) $(OBJS) -o $(NAME)
				  @echo "\n$(GREEN)[OK]:\t\t$(YELLOW)Minilibx"
				  @echo "$(GREEN)[OK]:\t\t$(YELLOW)Cube3D"

clean			:
				  @$(MAKE) clean -C minilibx/
				  @$(RM) $(OBJS)
				  @$(RM) screenshot.bmp
				  @echo "${RED}[CLEAN]:\t$(YELLOW)Minilibx"
				  @echo "${RED}[CLEAN]:\t$(YELLOW)Objects"
				  @echo "${RED}[CLEAN]:\t$(YELLOW)screenshot.bmp"

fclean			: clean
				  @$(RM) $(NAME)
				  @echo "${RED}[CLEAN]:\t$(YELLOW)Cube3D"

re				: fclean all

.PHONY			: clean fclean all re