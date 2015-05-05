# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 09:54:26 by alegent           #+#    #+#              #
#    Updated: 2015/05/03 16:53:50 by alegent          ###   ########.fr        #
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
	  analyze.c \
	  createenv.c \
	  ft_cd.c \
	  ft_env.c \
	  ft_free.c \
	  ft_getenv.c \
	  ft_len.c \
	  ft_setenv.c \
	  ft_sh.c \
	  ft_sig.c \
	  ft_unsetenv.c \
	  getcmd.c \
	  gethome.c \
	  getoldpwd.c \
	  getpath.c \
	  insertenv.c \
	  lstlen.c \
	  multicmd.c \
	  newenv.c \
	  newnode.c \
	  process_error.c \
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
LFT= libft
LINK= git@github.com:amoriarty/libft.git
LIB= -L libft/ -lft

#FRAMEWORK BLOC
#Don't forget to add framework that you need !
FRAMEWORK= 

all: $(OGL) $(NAME)

$(LFT):
	@git submodule add -f $(LINK)
	@git submodule update --rebase $(LFT)
	@echo "submodule is in place."
	@make -C $(LFT)

$(NAME): $(LFT) $(OBJ)
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
	@rm -rf $(NAME)
	@echo "$(NAME) is deleted."
	@git submodule deinit -f $(LFT)
	@git rm -f $(LFT)
	@rm -rf $(LFT)
	@echo "libft sources has been deleted."

re: fclean all

norme:
	@norminette $(INC_LIB)**.[ch]
	@norminette $(SRC_PATH)**.[ch]
	@norminette $(INC_PATH)**.[ch]

.PHONY: clean fclean re norme
