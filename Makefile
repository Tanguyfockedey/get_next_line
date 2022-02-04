# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfockede <tfockede@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 17:12:13 by tfockede          #+#    #+#              #
#    Updated: 2022/02/02 17:12:13 by tfockede         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a
FLAGS	= -Wall -Wextra -Werror
FILES	=	get_next_line.c \
			get_next_line_utils.c
			
OBJ		= $(FILES:.c=.o)

%.o: %.c
	@ cc $(FLAGS) -c $< -o $@

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@ ar -rc $(NAME) $(OBJ)
	@ echo create mandatory

clean:
	@ rm -f $(OBJ) $(B_OBJ)
	@ echo delete .o

fclean: clean
	@ rm -f $(NAME)
	@ echo delete libft.a

main: fclean all
	cc main.c -fsanitize=address $(FLAGS) $(NAME) #-D BUFFER_SIZE=42
	./a.out
	-rm -f a.out

.PHONY: all re bonus clean fclean
