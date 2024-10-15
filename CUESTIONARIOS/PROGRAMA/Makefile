# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: usuario <usuario@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 14:19:13 by usuario           #+#    #+#              #
#    Updated: 2024/10/14 14:14:20 by usuario          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = converter

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address `pkg-config --cflags poppler-glib`

RM = rm -f

LIBS = `pkg-config --libs poppler-glib` -lcjson -lxlsxwriter

SRC = main.c \
	utils.c \
	readpdf.c \
	createfiles.c

OBJTS = $(SRC:.c=.o)

$(NAME): $(OBJTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJTS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re