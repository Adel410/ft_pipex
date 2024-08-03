/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:28:17 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/05/29 12:25:14 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

int		ft_lstsize(t_list *lst);

char	*ft_strchr(const char *str, int searched);

char	*ft_strrchr(const char *str, int searched);

char	*ft_strnstr(const char *str, const char *to_find, size_t len);

char	*ft_strdup(char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_itoa(int n);

char	**ft_split(char const *s, char c);

void	ft_bzero(void *ptr, size_t n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_memset(void *ptr, int x, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_lstadd_front(t_list **lst, t_list *new);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *str);

t_list	*ft_lstnew(void *content);

t_list	*ft_lstlast(t_list *lst);
#endif
