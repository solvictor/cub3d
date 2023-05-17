/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:05:47 by tgernez           #+#    #+#             */
/*   Updated: 2022/09/04 18:05:47 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define LIST_PH "cspdiuxX%"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strstr(const char *haystack, const char *needle);
void	*ft_free_strs(char **strs);
char	ft_cset_in_str(char *charset, char *str);
void	ft_print_int_tab(int *tab, size_t len);
int		*ft_sort_int_tab(int *tab, size_t len);
int		ft_is_int_tab_sorted(int *tab, size_t len);
int		*ft_rev_int_tab(int *tab, size_t len);
void	ft_free_ints(int **tab);
int		**ft_ints(int len_tab, int len_tabs);
void	ft_free_lst(t_list *head);
int		ft_c_in_str(char c, char *str);
char	**ft_strsdup(const char **src);

/* PRINTF */
int		ft_printf(const char *placeholders, ...);
/*PRINTERS*/
int		ft_printer_c(int c);
int		ft_printer_d(int nb);
int		ft_printer_i(int nb);
int		ft_printer_p(void *addr);
int		ft_printer_s(char *str);
int		ft_printer_u(unsigned int nb);
int		ft_printer_x(int nb);
int		ft_printer_upperx(int nb);
/*NUMBERS*/
void	ft_putnbr_int(int nb, int *len);
void	ft_putnbr_ui(unsigned int nb, int *len);
/*HEXADECIMAL*/
int		ft_len_nb_hexa(long nb);
int		ft_putnbr_ul_hexa(unsigned long nb);
int		ft_putnbr_ui_hexa_low(unsigned int nb, int *len);
int		ft_putnbr_ui_hexa_up(unsigned int nb, int *len);
/* GNL */
char	*get_next_line(int fd);
int		ft_str_clean_nl(char *str);
char	*ft_strdup_bool(char *s1, int malloced);
size_t	ft_strlcpy_noconst(char *dst, char *src, size_t dstsize);
char	*ft_strdup_bool(char *s1, int malloced);
char	*ft_strdup_bool(char *s1, int malloced);
char	*ft_strjoin_noconst(char *s1, char *s2);
#endif
