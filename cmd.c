/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 12:05:47 by elivet            #+#    #+#             */
/*   Updated: 2014/05/17 16:38:02 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void		ft_get_file(int csock, char *file)
{
	char	buff[5];
	int		fd;
	int		ret;

	printf("%s\n", file);
	if (file != NULL)
	{
		if ((fd = open(file, O_RDONLY)) != -1)
		{
			while ((ret = read(fd, buff, 5)) > 0)
			{
				buff[ret] = '\0';
				write(csock, buff, sizeof(buff));
			}
		}
	}
	write(csock, "\0", 1);
	write(csock, "\nSUCCESS\n", 10);
}

void		ft_quit(int sock)
{
	close(sock);
	exit(0);
}

void		ft_ls(int csock)
{
	struct dirent	*ent;
	DIR				*dir;

	if ((dir = opendir("./")) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			printf("%s\n", ent->d_name);
			write(csock, ent->d_name, ft_strlen(ent->d_name));
			write(csock, "\n", 1);
		}
		write(csock, "\nSUCCESS\n", 8);
	}
	write(csock, "\0", 1);
	closedir(dir);
}

void		ft_cd(int csock, char *str, char *home)
{
	int		ret;
	char	**cmd;
	char	buff[1024];

	cmd = ft_strsplit(str, ' ');
	if (!ft_strcmp("..", cmd[1]) && !ft_strcmp(home, getcwd(buff, 10000)))
	{
		write(csock, "ERROR: already at the root of the server\n", 42);
		return ;
	}
	if ((ret = chdir(cmd[1])) == -1)
		write(csock, "ERROR: not a directory\n", 25);
	else
		write(csock, "SUCCESS\n", 9);
}

void		ft_pwd(int csock, int home)
{
	char		buff[1024];

	getcwd(buff, 10000);
	if (*(buff + home) != '/')
		ft_putstr_fd("/", csock);
	ft_putendl_fd(buff + home, csock);
	write(csock, "SUCCESS\n", 9);
	printf("%s\n", buff);
}
