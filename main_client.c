/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 12:05:47 by elivet            #+#    #+#             */
/*   Updated: 2014/05/17 20:05:11 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>

void		ft_get(char *buff, int sock)
{
	int		r;
	int		fd;

	if ((fd = open(&buff[4], O_RDWR |
	O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) != -1)
	{
		while ((r = read(sock, buff, 1)) > 0 && buff[0] != '\0')
		{
			buff[r] = '\0';
			write(fd, buff, r);
		}
		while ((r = read(sock, buff, 1)) > 0 && buff[0] != '\0')
		{
			buff[r] = '\0';
			write(1, buff, r);
		}
	}
}

int			create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("Connect error\n");
		exit(-42);
	}
	return (sock);
}

void		condition(char *buff, int sock)
{
	int		r;

	if (!ft_strncmp("quit", buff, 4))
		ft_quit(sock);
	if (!ft_strncmp("get", buff, 3))
		ft_get(buff, sock);
	if (ft_strcmp("ls", buff) == 0 || ft_strcmp("pwd", buff) == 0
			|| ft_strncmp("cd", buff, 2) == 0)
	{
		while ((r = read(sock, buff, 1)) > 0 && buff[0] != '\0')
		{
			buff[r] = '\0';
			write(1, buff, r);
		}
	}
}

int			begin_client(int ac, char **av)
{
	int			port;
	int			sock;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	return (sock);
}

int			main(int ac, char **av)
{
	int			sock;
	char		buff[1024];
	int			r;

	sock = begin_client(ac, av);
	write(1, "\nBonjour que puis-je faire pour vous ?--> ", 42);
	while ((r = read(0, buff, 1023)) > 0)
	{
		buff[r - 1] = '\0';
		write(sock, buff, r);
		condition(buff, sock);
		write(1, "\nBonjour que puis-je faire pour vous ?--> ", 42);
	}
	close(sock);
	return (0);
}
