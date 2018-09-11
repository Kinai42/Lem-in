# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 02:59:52 by dbauduin          #+#    #+#              #
#    Updated: 2018/09/11 12:21:13 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_DEF	?= 	\e[38;5;15m
OK		?=	\e[38;5;47m

OBJ = $(addsuffix .o, $(addprefix obj/, main get_anthill run free))
OBJ_W ?= $(shell find obj | grep \\.o$)

NAME = lem-in
cc =	-O1 -g -fsanitize=address	\
		-fno-omit-frame-pointer		\
		-fsanitize-address-use-after-scope


all: obj $(NAME)

obj:
	mkdir obj

$(NAME): $(OBJ)
	@make -C libft
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) libft/libft.a
	@printf "$(OK)[+][FILLER] Done$(C_DEF)\n"

obj/%.o: src/%.c
	@gcc -Wall -Werror -Wextra -o $@ -c $< -I include/ -I libft/include

clean:
	@rm -f $(OBJ_W)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
