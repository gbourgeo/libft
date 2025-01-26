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

#include "ft_constants.h"
#include <stddef.h>

typedef struct __align(32) s_list
{
    void          *content;
    size_t         content_size;
    struct s_list *next;
} t_list;

void    ft_freestr(char **str);
void    ft_freetab(char ***table);
size_t  ft_strlen(const char *str);
char   *ft_strdup(const char *str);
char   *ft_strcpy(char *dest, const char *src);
char   *ft_strncpy(char *dest, const char *src, size_t len);
char   *ft_strcat(char *dest, const char *src);
char   *ft_strncat(char *dest, const char *src, size_t len);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
char   *ft_strchr(const char *str, int chr);
char   *ft_strrchr(const char *str, int chr);
char   *ft_strstr(const char *str, const char *tofind);
char   *ft_strnstr(const char *str, const char *tofind, size_t len);
int     ft_strcmp(const char *str1, const char *str2);
int     ft_strncmp(const char *str1, const char *str2, size_t len);
int     ft_atoi(const char *str);
long    ft_atol(const char *str);
long    ft_atol_base(const char *str, const char *base);
int     ft_isalpha(int chr);
int     ft_isdigit(int chr);
int     ft_isalnum(int chr);
int     ft_isascii(int chr);
int     ft_isprint(int chr);
int     ft_iswhitespace(char chr);
int     ft_toupper(int chr);
int     ft_tolower(int chr);
void   *ft_memset(void *ptr, int chr, size_t len);
void    ft_bzero(void *ptr, size_t len);
void   *ft_memcpy(void *dest, const void *src, size_t lenn);
void   *ft_memccpy(void *dest, const void *src, int chr, size_t len);
void   *ft_memchr(const void *src, int chr, size_t len);
void   *ft_memmove(void *dest, const void *src, size_t len);
int     ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
void   *ft_memalloc(size_t size);
void    ft_memdel(void **ptr);
char   *ft_strnew(size_t size);
void    ft_strdel(char **str);
void    ft_strclr(char *str);
void    ft_striter(char *str, void (*func)(char *));
void    ft_striteri(char *str, void (*func)(unsigned int, char *));
char   *ft_strmap(const char *str, char (*func)(char));
char   *ft_strmapi(const char *str, char (*func)(unsigned int, char));
int     ft_strequ(const char *str1, const char *str2);
int     ft_strnequ(const char *str1, const char *str2, size_t len);
char   *ft_strsub(const char *str, unsigned int start, size_t len);
char   *ft_strjoin(const char *str1, const char *str2);
char   *ft_strtrim(const char *str);
char  **ft_strsplit(const char *str, char chr);
char   *ft_itoa(int num);
void    ft_putchar(char chr);
void    ft_putstr(const char *str);
void    ft_putendl(const char *str);
void    ft_putnbr(int num);
void    ft_putchar_fd(char chr, int fde);
void    ft_putstr_fd(const char *str, int fde);
void    ft_putendl_fd(const char *str, int fde);
void    ft_putnbr_fd(int num, int fde);
void    ft_lstadd(t_list **alst, t_list *new);
void    ft_lstaddend(t_list **alst, t_list *new);
void    ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void    ft_lstiter(t_list *lst, void (*func)(t_list *));
t_list *ft_lstmap(t_list *lst, t_list *(*func)(t_list *));
t_list *ft_lstnew(const void *content, size_t content_size);
void    ft_lstswap(t_list *one, t_list *two);
char  **ft_tabdup(const char **table);
size_t  ft_tablen(const char **table);
void    ft_puttab(const char **table);
void    ft_puttab_fd(const char **table, int fde);
void    ft_puttabc(const char **table, const char *preprint);
void    ft_puttabc_fd(const char **table, const char *preprint, int fde);
void    ft_tabdel(char ***table);
char  **ft_split(const char *str, const char *charset);
char  **ft_split_whitespaces(const char *str);
char   *ft_str2join(const char *str1, const char *str2, const char *str3);
char   *ft_strcdup(const char *str, char chr);
char   *ft_strcharset(const char *str, const char *charset);
void    ft_stricpy(char *dest, const char *src, size_t pos);
char   *ft_strndup(const char *src, size_t size);
char   *ft_strrcdup(const char *src, char chr);

int     ft_pow(int num, int power);

#endif /* _LIBFT_H_ */
