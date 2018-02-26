#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/03/05 15:21:15 by                   #+#    #+#             *#
#*   Updated: 2016/04/22 13:26:36 by fpasquer         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = main.c pile.c push_swap.c fonction1.c fonction2.c fonction3.c sort.c		\
		fonction_standard.c tri.c flags.c push_swap2.c push_swap3.c

HEADS = push_swap.h

LIBS = libft/libft.a

OTHERS = libft Makefile auteur push_swap.pdf

OBJS = $(SRCS:.c=.o)

NAME = push_swap

LOGFILE = $(LOGPATH) `date +'%d/%m/%y %H:%M:%S'`

all : $(NAME)

$(NAME):
	make -C libft/ all
	$(CC) -c -g $(FLAGS) $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) -g $(OBJS) $(LIBS)

clean : $(OBJS)
	rm -rf $(OBJS)

fclean : clean
	make -C libft/ fclear
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

push : fclean
	git add $(SRCS) $(HEADS) $(OTHERS)
	git commit -m "$(LOGFILE)"
	git push

re : fclean all

exe : re
	./$(NAME) 0 7 1 3 2 6 8 4 9 5

.PHONY: all clean fclean re exe push
