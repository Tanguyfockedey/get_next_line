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
FLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=xx
FILES	=	get_next_line.c \
			get_next_line_utils.c
			
B_FILES	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \


OBJ		= $(FILES:.c=.o)

B_OBJ	= $(B_FILES:.c=.o)

%.o: %.c
	@ cc $(FLAGS) -c $< -o $@

re: fclean all

all: mandatory bonus
	@ echo create libft.a : mandatory + bonus

mandatory: $(OBJ)
	@ ar -rc $(NAME) $(OBJ)

bonus: $(B_OBJ)
	@ ar -rc $(NAME) $(B_OBJ)

main:
	cc $(FLAGS) -fsanitize=address main.c libft.a -g3
	./a.out
	rm -f a.out

clean:
	@ rm -f $(OBJ) $(B_OBJ)

fclean:
	rm -f $(NAME)

.PHONY: all clean fclean re mandatory bonus main so