# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 09:54:26 by alegent           #+#    #+#              #
#    Updated: 2015/05/21 17:36:01 by alegent          ###   ########.fr        #
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
	  ft_analyze.c \
	  ft_cd.c \
	  ft_cenv.c \
	  ft_env.c \
	  ft_exit.c \
	  ft_fork.c \
	  ft_fctab.c \
	  ft_flst.c \
	  ft_gcmd.c \
	  ft_genv.c \
	  ft_glst.c \
	  ft_gpath.c \
	  ft_handler.c \
	  ft_inode.c \
	  ft_len.c \
	  ft_lstlen.c \
	  ft_mcmd.c \
	  ft_nlst.c \
	  ft_nsh.c \
	  ft_senv.c \
	  ft_sherror.c \
	  ft_tcmd.c \
	  ft_uenv.c \
	  ft_vaccess.c \
	  ft_vcmd.c \
	  ft_vsplit.c
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
LFT= libft
LINK= https://github.com/amoriarty/libft.git
LIB= -L libft/ -lft

#FRAMEWORK BLOC
#Don't forget to add framework that you need !
FRAMEWORK= 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT)
	@$(GCC) $(OBJ) $(INC) $(LIB) $(FRAMEWORK) -o $(NAME)
	@echo "$(NAME) has been created."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" 2> /dev/null
	$(GCC) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT) clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "$(NAME) objects files are deleted."

fclean: clean
	@make -C $(LFT) fclean
	@rm -rf $(NAME)
	@echo "$(NAME) is deleted."

re: fclean all

norme:
	@norminette $(INC_LIB)**.[ch]
	@norminette $(SRC_PATH)**.[ch]
	@norminette $(INC_PATH)**.[ch]

.PHONY: clean fclean re norme
