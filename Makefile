# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elivet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/13 11:54:31 by elivet            #+#    #+#              #
#    Updated: 2014/05/13 11:54:34 by elivet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESRV= serveur

NAMECLI= client

FLAGS= -Wall -Wextra -Werror

SRCSRV= main_serveur.c ft_atoi.c ft_isdigit.c ft_nospace.c usage.c \
		ft_strcmp.c ft_strlen.c ft_strsplit.c ft_strsub.c ft_strnew.c \
		ft_strclr.c ft_strncmp.c ft_putendl_fd.c ft_putstr_fd.c \
		ft_putchar_fd.c cmd.c ft_strdup.c

SRCCLI= main_client.c usage.c ft_atoi.c ft_isdigit.c ft_nospace.c \
		ft_strcmp.c ft_strlen.c ft_strsplit.c ft_strsub.c ft_strnew.c \
		ft_strclr.c ft_strncmp.c ft_putendl_fd.c ft_putstr_fd.c \
		ft_putchar_fd.c cmd.c ft_strdup.c

OBJSRV= $(SRCSRV:.c=.o)

OBJCLI= $(SRCCLI:.c=.o)

all: $(NAMESRV) $(NAMECLI)

$(NAMESRV):
		gcc $(FLAGS) -c $(SRCSRV) -g
		gcc -lpthread -o $(NAMESRV) $(OBJSRV)

$(NAMECLI):
		gcc $(FLAGS) -c $(SRCCLI) -g
		gcc -lpthread -o $(NAMECLI) $(OBJCLI)

%.o: %.c
		gcc $(FLAGS) -c $^ -o $@

clean:
		rm -f $(OBJSRV)
		rm -f $(OBJCLI)

fclean: clean
		rm -f $(NAMESRV)
		rm -f $(NAMECLI)

re: fclean all
