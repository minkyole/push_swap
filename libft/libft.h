/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:33:38 by minkyole          #+#    #+#             */
/*   Updated: 2023/03/23 18:18:20 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_gnl
{
	int		read_size;
	char	buff[BUFFER_SIZE + 1];
	char	*return_arr;
	int		end;
	int		parr_size;
}			t_gnl;

typedef struct s_print_member
{
	int		len;
	char	*input_msg;
	int		cnt;
	int		precision;
}	t_print_member;

t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
unsigned long	ft_strlen(const char *s);
size_t			ft_strlcpy(char *dest, char *src, size_t size);
size_t			ft_strlcat(char *dest, char *src, size_t size);
char			*ft_strchr(const char *s, int c);
void			*ft_memset(void *b, int c, unsigned long len);
void			*ft_memmove(void *dst, const void *src, unsigned long len);
void			*ft_memcpy(void *dst, const void *src, unsigned long n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_bzero(void *s, unsigned long n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*get_next_line(int fd);
char			*get_next_line2(char **parr, t_gnl member, int fd);
int				arr_read_test(t_gnl *member, char **parr);
int				arr_read_return_test(t_gnl *member, char **parr);
char			*str_add(char *buff, char *parr, int buff_size, int parr_size);
int				ft_strcpy(char	*dest, char	*src);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				check_count(char *parr, int *end, int flag);
char			*static_reset(char **parr);
int				ft_strlen2(char *arr);
int				ft_printf(const char *msg, ...);
int				print_conversion(t_print_member *member, va_list *print, int i);
void			ft_un_putnbr_fd(unsigned int n, int fd);
void			ft_putptr2(unsigned long long nb, int small);
int				ft_declen(long long num);
int				ft_undeclen(long long num);
int				ft_hexlen(long long num);
void			print_d_i(va_list *print, int cnt, int precision, int *num);
void			print_u(va_list *print, int cnt, int precision, int *num);
void			print_small_x(va_list *print, int cnt, int precision, int *num);
void			print_big_x(va_list *print, int cnt, int precision, int *num);
void			print_c(va_list *print, int cnt, int *num);
void			print_s(va_list *print, int cnt, int *num);
void			print_p(va_list *print, int cnt, int *num);
void			print_per(int cnt, int *num);

#endif
