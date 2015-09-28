/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_serveur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 12:05:39 by elivet            #+#    #+#             */
/*   Updated: 2014/05/17 16:54:08 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <signal.h>

int			create_server(int port)
{
	int					sock;
	struct sockaddr_in	sin;

	inet_addr("127.0.0.1");
	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if (bind(sock, (const struct sockaddr*)&sin, sizeof(sin)) == -1)
	{
		printf("Bind error\n");
		exit(-42);
	}
	listen(sock, 5);
	return (sock);
}

void		loop(int csock, char *home)
{
	char					buff[1024];
	int						r;

	while ((r = read(csock, buff, 1023)) > 0)
	{
		buff[r - 1] = '\0';
		if (!ft_strncmp("ls", buff, 2))
			ft_ls(csock);
		if (!ft_strncmp("cd", buff, 2))
			ft_cd(csock, buff, home);
		if (!ft_strncmp("pwd", buff, 3))
			ft_pwd(csock, ft_strlen(home));
		if (!ft_strncmp("get", buff, 3))
			ft_get_file(csock, &buff[4]);
		printf("received %d bytes: [%s]\n", r, buff);
	}
}

int			begin(int ac, char **av)
{
	int					sock;
	int					port;

	signal(SIGCHLD, SIG_IGN);
	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	return (sock);
}

int			main(int ac, char **av)
{
	struct sockaddr_in		csin;
	t_tool					the;
	char					buff[1024];
	pid_t					pid;
	char					*home;

	the.sock = begin(ac, av);
	home = ft_strdup(getcwd(buff, 10000));
	while (1)
	{
		the.csock = accept(the.sock, (struct sockaddr*)&csin, &(the.length));
		if ((pid = fork()) == -1)
			close(the.csock);
		else if (pid > 0)
			close(the.csock);
		else if (pid == 0)
			loop(the.csock, home);
	}
	close(the.csock);
	close(the.sock);
	return (0);
}
