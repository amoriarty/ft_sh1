# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 09:54:26 by alegent           #+#    #+#              #
#    Updated: 2015/04/14 17:10:23 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#This is a typical Makefile, re-usable anytime you want to compil C project.
#All is in quiet for now, thank to do all the completion that needed for
# specify project

#Define name of program here
NAME= ft_minishell1

#SRC BLOC
# define all the .c file in the variable SRC NAME
SRC_PATH= srcs/
SRC_NAME= main.c \
	  newnode.c \
	  newenv.c \
	  insertenv.c \
	  getpath.c \
	  ft_getenv.c \
	  ft_env.c \
	  getcmd.c \
	  ft_sig.c \
	  analyze.c \
	  ft_len.c \
	  ft_sh.c \
	  ft_setenv.c \
	  ft_unsetenv.c \
	  ft_cd.c \
	  gethome.c \
	  process_error.c \
	  multicmd.c \
	  trimcmd.c \
	  verifcmd.c \
	  verifsplit.c
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

#OBJ BLOCK
#Do nothing here
OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

#GCC BLOC
#GCC flag, you don't have to modify this (but you're free to go)
GCC= gcc -Wall -Wextra -Werror

#INCLUDE BLOC
#Don't forget to include the other librarie that yo use
INC_LIB= libft/
INC_PATH= includes/
INC= -I $(INC_LIB) -I $(INC_PATH)

#Once again, don't forget to includes librairy that you use !
LIB= -L libft/ -lft

#FRAMEWORK BLOC
#Don't forget to add framework that you need !
FRAMEWORK= 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@make -C libft/ clean
	@$(GCC) $(OBJ) $(INC) $(LIB) -o $(NAME)
	@echo "$(NAME) has been created."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" 2> /dev/null
	$(GCC) $(INC) -o $@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "$(NAME) objects files are deleted."

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(NAME) is deleted."

re: fclean all

norme:
	@norminette $(INC_LIB)**.[ch]
	@norminette $(SRC_PATH)**.[ch]
	@norminette $(INC_PATH)**.[ch]

.PHONY: clean fclean re norme
