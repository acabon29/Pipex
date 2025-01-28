/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabon <acabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:19:21 by acabon            #+#    #+#             */
/*   Updated: 2025/01/28 15:49:47 by acabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <bsd/string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
// # define IS_SPACE(c) ((c >= 9 && c <= 13) || c == ' ')
// # define IS_NUM(c) (c >= '0' && c <= '9')
// # define IS_ALPHA(c) (c >= 'a' && c <= 'z')
// # define IS_ALPHAMAJ(c) (c >= 'A' && c <= 'Z')
// # define MY_ABS(c) (c * (((c >= 0) * 1) + ((c < 0) * -1)))

static inline int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static inline int	is_num(int c)
{
	return (c >= '0' && c <= '9');
}

static inline int	is_alpha(int c)
{
	return (c >= 'a' && c <= 'z');
}

static inline int	is_alphamaj(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static inline int	my_abs(int c)
{
	return (c * (((c >= 0) * 1) + ((c < 0) * -1)));
}

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// partie 1

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);

// partie 2

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);

// bonus

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// mes fonctions

int		ft_putnbr_base(unsigned int nb, char *base);
int		ft_putexapt_pf(long long mem, char *base, int fd);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_isint(char *str);
int		ft_printf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_putnbr_base_fd(unsigned int nb, char *base, int fd);
void	free_tab(void **tab);
void	free_tabn(void **tab, int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

#endif