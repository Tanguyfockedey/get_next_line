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

B_FILES =	get_next_line_bonus.c \
			get_next_line_utils_bonus.c

			
OBJ		= $(FILES:.c=.o)

B_OBJ	= $(B_FILES:.c=.o)

%.o: %.c
	@ cc $(FLAGS) -c $< -o $@

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@ ar -rc $(NAME) $(OBJ)
	@ echo create all

bonus: $(B_OBJ)
	@ ar -rc $(NAME) $(B_OBJ)
	@ echo create bonus

clean:
	@ rm -f $(OBJ) $(B_OBJ)
	@ echo delete .o

fclean: clean
	@ rm -f $(NAME)
	@ echo delete $(NAME)

main: fclean bonus
	cc main.c -fsanitize=address -g3 $(FLAGS) $(NAME)
	@ ./a.out
#	@ -rm -f a.out

.PHONY: all re bonus clean fclean
