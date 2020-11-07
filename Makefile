# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 11:46:02 by afoulqui          #+#    #+#              #
#    Updated: 2020/11/07 20:08:41 by kwe              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#     VARIABLES     #
# ----------------- #

NAME		=	minishell

LIB_DIR		=	libft
LIBFT		=	$(LIB_DIR)/libft.a


SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d) $(LIB_DIR)/includes

OBJ_DIR		=	objs/

LIB			=	ft
SRC			=	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))
OBJ			=	$(addprefix $(OBJ_DIR),$(SRC:%.c=%.o))
HEADERS		=	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))


vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#    COMPILATION    #
# ----------------- #

CC		=	gcc

CFLAG	=	-Wall -Werror -Wextra
IFLAG	=	$(foreach dir, $(INC_DIR), -I $(dir) )
LFLAG	=	$(foreach lib, $(LIB), -l $(lib) ) $(foreach dir, $(LIB_DIR), -L $(dir) ) 

# ----------------- #
#     FUNCTIONS     #
# ----------------- #

$(OBJ_DIR)%.o:%.c $(HEADERS)		
				@mkdir -p $(OBJ_DIR)
				@echo "\033[32mCompilation ... $(foreach file, $< , $(notdir $<))"
				@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $< 
				

$(NAME):	install $(OBJ)
				@$(CC) $(CFLAG) $(OBJ) $(IFLAG) $(LFLAG) -o $@
				@echo "\n\t\033[36;1m*.............................*"
				@echo "\n\t*    Compilation $(NAME)    *\t   \033[32;1m--------->>> \033[4;5mComplete\033[0m"
				@echo "\n\t\033[036;1m*.............................*\033[0m"

all	:		$(NAME)

install :	
				@make -C $(LIB_DIR)

re-install :
				@make -C $(LIB_DIR) re

show :
				@echo "SRC_DIR : $(SRC_DIR)\n"
				@echo "LIB_DIR : $(LIB_DIR)\n"
				@echo "INC_DIR : $(INC_DIR)\n"
				@echo "CFLAG : $(CFLAG)\n"
				@echo "IFLAG : $(IFLAG)\n"
				@echo "LFLAG : $(LFLAG)\n"
				@echo "HEADERS : $(foreach file, $(HEADERS),\n\t$(file))\n"
				@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
				@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"

# ----------------- #
#       CLEAN       #
# ----------------- #

RM		=	rm -rf

clean:	
			@$(RM) $(OBJ_DIR)
			@echo "\033[36;1m $(NAME) ------>>  clean\033[0m\n"

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C $(LIB_DIR)
			@echo "\033[36;1m $(NAME) ------>>  fclean\033[0m\n"

re:			fclean all

run:		all
				./$(NAME)

rerun:		re
				./${NAME}

.PHONY:		all clean fclean re
