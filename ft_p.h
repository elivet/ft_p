/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:54:50 by elivet            #+#    #+#             */
/*   Updated: 2014/05/17 16:42:07 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <sys/socket.h>
# include <netinet/in.h>
# include <dirent.h>

typedef struct		s_tool
{
	int				sock;
	int				csock;
	unsigned int	length;
}					t_tool;

int					ft_atoi(const char *str);
int					create_server(int port);
int					ft_isdigit(int c);
char				ft_nospace(char c);
void				usage(char *str);
void				prompt(void);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_ls(int csock);
char				*check_cd(char *str);
void				ft_cd(int csock, char *str, char *home);
void				ft_pwd(int csock, int home);
char				*ft_strdup(const char *s1);
void				ft_quit(int sock);
void				loop(int csock, char *home);
int					begin(int ac, char **av);
int					begin_client(int ac, char **av);
void				ft_get_file(int sock, char *file);
void				ft_get(char *buff, int sock);
void				condition(char *buff, int sock);

#endif
