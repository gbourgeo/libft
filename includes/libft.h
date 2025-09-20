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

#include "ft_defines.h"
#include <stddef.h>

typedef struct _align(32) s_list
{
    void          *content;
    size_t         content_size;
    struct s_list *next;
} t_list;

/* Converters */
int   ft_atoi(const char *str);
long  ft_atol_base(const char *str, const char *base);
long  ft_atol(const char *str);
char *ft_itoa_base(unsigned int num, unsigned int base);
char *ft_itoa(int num);
char *ft_ltoa_base(unsigned long long num, unsigned int base);
char *ft_ltoa(long num);
int   ft_pow(int num, int power);
int   ft_toupper(int chr);
int   ft_tolower(int chr);

/* String manipulation */
void           ft_bzero(void *ptr, size_t len);
void           ft_freestr(char **str);
void           ft_freetab(char ***table);
char         **ft_split_whitespaces(const char *str);
char         **ft_split(const char *str, const char *charset);
char          *ft_str2join(const char *str1, const char *str2, const char *str3);
char          *ft_strcat(char *dest, const char *src);
char          *ft_strcdup(const char *str, char chr);
char          *ft_strcharset(const char *str, const char *charset);
char          *ft_strchr(const char *str, int chr);
void           ft_strclr(char *str);
int            ft_strcmp(const char *str1, const char *str2);
char          *ft_strcpy(char *dest, const char *src);
void           ft_strdel(char **str);
char          *ft_strdup(const char *str);
int            ft_strequ(const char *str1, const char *str2);
void           ft_stricpy(char *dest, const char *src, size_t pos);
void           ft_striter(char *str, void (*func)(char *));
void           ft_striteri(char *str, void (*func)(unsigned int, char *));
char          *ft_strjoin(const char *str1, const char *str2);
size_t         ft_strlcat(char *dest, const char *src, size_t size);
size_t         ft_strlen(const char *str);
char          *ft_strmap(const char *str, char (*func)(char));
char          *ft_strmapi(const char *str, char (*func)(unsigned int, char));
char          *ft_strncat(char *dest, const char *src, size_t len);
int            ft_strncmp(const char *str1, const char *str2, size_t len);
char          *ft_strncpy(char *dest, const char *src, size_t len);
char          *ft_strndup(const char *src, size_t size);
int            ft_strnequ(const char *str1, const char *str2, size_t len);
char          *ft_strnew(size_t size);
char          *ft_strnstr(const char *str, const char *tofind, size_t len);
char          *ft_strrcdup(const char *src, char chr);
char          *ft_strrchr(const char *str, int chr);
char         **ft_strsplit(const char *str, char chr);
char          *ft_strstr(const char *str, const char *tofind);
char          *ft_strsub(const char *str, unsigned int start, size_t len);
char          *ft_strtoupper(char *str);
char          *ft_strtrim(const char *str);
void           ft_ufreestr(unsigned char **str);
int            ft_ustrcmp(const unsigned char *str1, const unsigned char *str2);
unsigned char *ft_ustrdup(const unsigned char *str);
size_t         ft_ustrlen(const unsigned char *str);
size_t         ft_wstrlen(const wchar_t *str);

/* Table manipulation */
char **ft_tabdup(const char **table);
size_t ft_tablen(const char **table);
void   ft_tabdel(char ***table);

/* Identifiers */
int ft_isalnum(int chr);
int ft_isalpha(int chr);
int ft_isascii(int chr);
int ft_isdigit(int chr);
int ft_isprint(int chr);
int ft_iswhitespace(char chr);

/* Liste manipulation */
void    ft_lstadd(t_list **alst, t_list *new);
void    ft_lstaddend(t_list **alst, t_list *new);
void    ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void    ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void    ft_lstiter(t_list *lst, void (*func)(t_list *));
t_list *ft_lstmap(t_list *lst, t_list *(*func)(t_list *) );
t_list *ft_lstnew(const void *content, size_t content_size);
void    ft_lstswap(t_list *one, t_list *two);

/* Memory manipulation */
void *ft_memalloc(size_t size);
void *ft_memccpy(void *dest, const void *src, int chr, size_t len);
void *ft_memchr(const void *src, int chr, size_t len);
int   ft_memcmp(const void *ptr1, const void *ptr2, size_t len);
void *ft_memcpy(void *dest, const void *src, size_t lenn);
void  ft_memdel(void **ptr);
void *ft_memmove(void *dest, const void *src, size_t len);
void *ft_memset(void *ptr, int chr, size_t len);

/* Prints */
void ft_putbits(unsigned long number, size_t size);
void ft_putchar_fd(char chr, int fde);
void ft_putchar(char chr);
void ft_putendl_fd(const char *str, int fde);
void ft_putendl(const char *str);
void ft_putnbr_fd(int num, int fde);
void ft_putnbr(int num);
void ft_putstr_fd(const char *str, int fde);
void ft_putstr(const char *str);
void ft_puttab_fd(const char **table, int fde);
void ft_puttab(const char **table);
void ft_puttabc_fd(const char **table, const char *preprint, int fde);
void ft_puttabc(const char **table, const char *preprint);

#endif /* _LIBFT_H_ */
