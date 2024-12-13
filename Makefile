# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 20:27:40 by acarpent          #+#    #+#              #
#    Updated: 2024/12/13 14:07:54 by acarpent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### COLORS ####

GREEN = \033[0;92m
RED = \033[0;31m
NC = \033[0m

##### FOLDERS PATH ####

SRCS_DIR = ./Srcs/
OBJS_DIR = ./Objs/
LIB_DIR = ./libft/
HEADER_DIR = ./Includes/
MLX_DIR = ./mlx

###### ARGUMENTS ######

NAME = cub3D
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L$(LIB_DIR) -lm
COMP = cc
RM = rm -rf
MKDIR = mkdir -p

######  LIB PATH ######

LIBFT_MAKE = make -s -C $(LIB_DIR)
LIBFT_PATH = $(LIB_DIR)libft.a
Includes = -I $(HEADER_DIR)

######  MLX PATH ######

MLX_FLAGS = -Lmlx -L/usr/lib -lXext -lX11 -lm -lz
MLX_EX = $(MLX_DIR)/libmlx.a

######  SOURCES  ######

SRCS_FILES = Main_functions/main.c\
				Initialisation/init.c\
				Initialisation/mlx_init.c\
				Parsing/Name/check_name.c\
				Parsing/File/get_file.c\
				Parsing/File/file_parsing.c\
				Parsing/File/file_parsing_utils.c\
				Parsing/File/Data/get_textures.c\
				Parsing/File/Data/get_colors.c\
				Parsing/File/Data/data_utils.c\
				Parsing/File/Data/data_check.c\
				Parsing/Map/get_map.c\
				Parsing/Map/Data/get_map_data.c\
				Parsing/Map/Check/map_parsing.c\
				Parsing/Map/Check/map_parsing_utils.c\
				Parsing/Map/Check/check_dir.c\
				Parsing/Map/Check/check_space_dir.c\
				Error_manager/error.c\
				Error_manager/free.c\

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))			

######  OBJECTS  ######

OBJS_FILES = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

######   RULES   ######

all: $(NAME)

$(MLX_EX):
	@echo "$(GREEN)MLX compilation in progress...$(NC)"
	@$(MAKE) -s -C $(MLX_DIR)
	@echo "$(GREEN)MLX compilation completed!$(NC)"
	
$(NAME): $(OBJS_DIR) $(OBJS_FILES) $(MLX_EX)
	@echo "$(GREEN)Compilation in progress...$(NC)"
	@$(LIBFT_MAKE)
	@$(COMP) $(CFLAGS) $(OBJS_FILES) $(MLX_EX) $(MLX_FLAGS) -o $(NAME) $(LDFLAGS) -lft
	@echo "$(GREEN)Compilation completed!$(NC)"
	
#Creer le repertoire 'Objs' et compiles C source files into object files

$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(MKDIR) $(dir $@)
	@$(COMP) $(CFLAGS) $(Includes) -c $< -o $@

#Clean objects files and dependencies

clean:
	@echo "$(GREEN)Cleaning in progress...$(NC)"
	@$(RM) $(OBJS_DIR)
	@$(LIBFT_MAKE) clean
	@$(MAKE) clean -sC $(MLX_DIR)
	@echo "$(GREEN)Cleaning completed!$(NC)"

#Cleans everything generated by the Makefile

fclean: clean
	@$(RM) $(NAME) $(OBJS_DIR)
	@$(LIBFT_MAKE) fclean

#Remake

re: 
	make fclean 
	make all

.PHONY: all clean fclean re libft