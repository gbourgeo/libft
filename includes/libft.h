/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourgeo <gbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:02:18 by gbourgeo          #+#    #+#             */
/*   Updated: 2020/11/14 13:04:46 by gbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H_
#define LIBFT_H_
#include <stdlib.h>

typedef struct s_list
{
    void          *content;
    size_t         content_size;
    struct s_list *next;
} t_list;

void    ft_freestr(char **str);
void    ft_freetab(char ***table);
size_t  ft_strlen(const char *s);
char   *ft_strdup(const char *s1);
char   *ft_strcpy(char *s1, const char *s2);
char   *ft_strncpy(char *s1, const char *s2, size_t n);
char   *ft_strcat(char *s1, const char *s2);
char   *ft_strncat(char *s1, const char *s2, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t size);
char   *ft_strchr(const char *s, int c);
char   *ft_strrchr(const char *s, int c);
char   *ft_strstr(const char *s1, const char *s2);
char   *ft_strnstr(const char *s1, const char *s2, size_t n);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int     ft_atoi(const char *str);
long    ft_atol(const char *str);
long    ft_atol_base(const char *str, const char *base);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_iswhitespace(char c);
int     ft_toupper(int c);
int     ft_tolower(int c);
void   *ft_memset(void *b, int c, size_t len);
void    ft_bzero(void *s, size_t n);
void   *ft_memcpy(void *s1, const void *s2, size_t n);
void   *ft_memccpy(void *s1, const void *s2, int c, size_t n);
void   *ft_memchr(const void *s, int c, size_t n);
void   *ft_memmove(void *s1, const void *s2, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
void   *ft_memalloc(size_t size);
void    ft_memdel(void **ap);
char   *ft_strnew(size_t size);
void    ft_strdel(char **as);
void    ft_strclr(char *s);
void    ft_striter(char *s, void (*f)(char *));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
char   *ft_strmap(const char *s, char (*f)(char));
char   *ft_strmapi(const char *s, char (*f)(unsigned int, char));
int     ft_strequ(const char *s1, const char *s2);
int     ft_strnequ(const char *s1, const char *s2, size_t n);
char   *ft_strsub(const char *s, unsigned int start, size_t len);
char   *ft_strjoin(const char *s1, const char *s2);
char   *ft_strtrim(const char *s);
char  **ft_strsplit(const char *s, char c);
char   *ft_itoa(int n);
void    ft_putchar(char c);
void    ft_putstr(const char *str);
void    ft_putendl(const char *s);
void    ft_putnbr(int n);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(const char *s, int fd);
void    ft_putendl_fd(const char *s, int fd);
void    ft_putnbr_fd(int n, int fd);
void    ft_lstadd(t_list **alst, t_list *new);
void    ft_lstaddend(t_list **alst, t_list *new);
void    ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void    ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list *ft_lstnew(const void *content, size_t content_size);
void    ft_lstswap(t_list *one, t_list *two);
char  **ft_tabdup(char  *const *table);
int     ft_tablen(char     *const *table);
void    ft_puttab(char    *const *table);
void    ft_puttab_fd(char    *const *table, int fd);
void    ft_puttabc(char    *const *table, char    *const preprint);
void    ft_puttabc_fd(char    *const *table, char    *const preprint, int fd);
void    ft_tabdel(char ***table);
char  **ft_split(char *str, char *charset);
char  **ft_split_whitespaces(char *str);
char   *ft_str2join(const char *s1, const char *s2,
                    const char *s3);
char   *ft_strcdup(char *str, char c);
char   *ft_strcharset(char *s1, char *s2);
void    ft_stricpy(char *s1, const char *s2, int pos);
char   *ft_strndup(const char *s1, int size);
char   *ft_strrcdup(const char *str, char c);

int     ft_pow(int nb, int power);

#endif /* _LIBFT_H_ */
