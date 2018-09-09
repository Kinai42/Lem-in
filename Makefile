# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 02:59:52 by dbauduin          #+#    #+#              #
#    Updated: 2018/09/09 05:47:24 by dbauduin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(addsuffix .o, $(addprefix obj/, main get_anthill run ))
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

obj/%.o: src/%.c
	@gcc -Wall -Werror -Wextra -o $@ -c $< -I include/ -I libft/include

clean:
	@rm -f $(OBJ_W)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
